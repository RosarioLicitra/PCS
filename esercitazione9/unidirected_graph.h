#ifndef UNIDIRECTED_GRAPH_H
#define UNIDIRECTED_GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <fstream> 



// 1. -----CLASSE ARCO-----

class unidirected_edge {
private:
    int u, v;

public:
    unidirected_edge(int first, int second) {
        u = std::min(first, second);
        v = std::max(first, second);
    }

    int from() const { return u; }
    int to() const { return v; }  

    bool operator<(const unidirected_edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }

    bool operator==(const unidirected_edge& other) const {
        return u == other.u && v == other.v;
    }

    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge) {
        os << "(" << edge.u << ", " << edge.v << ")";
        return os;
    }
};


// 2. -----CLASSE GRAFO-----

class unidirected_graph {
private:
    std::map<int, std::set<int>> adj;
    std::vector<unidirected_edge> edges_vec; 
    std::map<unidirected_edge, int> edge_to_id;

public:
    unidirected_graph() = default;
    unidirected_graph(const unidirected_graph& other) = default;

    void add_edge(int u, int v) {
        unidirected_edge new_edge(u, v);
        if (edge_to_id.find(new_edge) == edge_to_id.end()) {
            int new_id = edges_vec.size();
            edges_vec.push_back(new_edge);
            edge_to_id[new_edge] = new_id;
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }

    std::set<int> neighbours(int node) const {
        auto it = adj.find(node);
        return (it != adj.end()) ? it->second : std::set<int>();
    }

    std::set<int> all_nodes() const {
        std::set<int> nodes;
        for (const auto& pair : adj) nodes.insert(pair.first);
        return nodes;
    }

    std::vector<unidirected_edge> all_edges() const {
        return edges_vec;
    }

    int edge_number(const unidirected_edge& edge) const {
        auto it = edge_to_id.find(edge);
        return (it != edge_to_id.end()) ? it->second : -1;
    }

    unidirected_edge edge_at(int index) const {
        if (index < 0 || index >= (int)edges_vec.size()) 
            throw std::out_of_range("Indice non valido");
        return edges_vec[index];
    }

    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph result;
        for (const auto& e : edges_vec) {
            if (other.edge_to_id.find(e) == other.edge_to_id.end()) {
                result.add_edge(e.from(), e.to());
            }
        }
        return result;
    }
};


// 3. -----ADAPTERS (FIFO / LIFO)----- 

class fifo {
private:
    std::queue<int> container;
public:
    fifo() = default;
    void put(int val) { container.push(val); }
    int get() { int val = container.front(); container.pop(); return val; }
    bool empty() const { return container.empty(); }
};

class lifo {
private:
    std::stack<int> container;
public:
    lifo() = default;
    void put(int val) { container.push(val); }
    int get() { int val = container.top(); container.pop(); return val; }
    bool empty() const { return container.empty(); }
};


// 4. ------FUNZIONE TEMPLATE GRAPH_VISIT (BFS/DFS)------ 

template <typename Container>
unidirected_graph graph_visit(const unidirected_graph& G, int source, Container container) {
    unidirected_graph visit_tree;
    std::set<int> visited;

    container.put(source);
    visited.insert(source);

    while (!container.empty()) {
        int current = container.get();
        for (int neighbor : G.neighbours(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                container.put(neighbor);
                visit_tree.add_edge(current, neighbor);
            }
        }
    }
    return visit_tree;
}


// 5. -----DFS RICORSIVA-----

inline void recursive_dfs_helper(const unidirected_graph& G, int current, std::set<int>& visited, unidirected_graph& visit_tree) {
    visited.insert(current);
    for (int neighbor : G.neighbours(current)) {
        if (visited.find(neighbor) == visited.end()) {
            visit_tree.add_edge(current, neighbor);
            recursive_dfs_helper(G, neighbor, visited, visit_tree);
        }
    }
}

inline unidirected_graph recursive_dfs(const unidirected_graph& G, int source) {
    unidirected_graph visit_tree;
    std::set<int> visited;
    recursive_dfs_helper(G, source, visited, visit_tree);
    return visit_tree;
}


// 6. -----ALGORITMO DI DIJKSTRA----- 

inline void dijkstra(const unidirected_graph& G, int source) {
    std::map<int, int> dist;
    std::set<int> all_nodes = G.all_nodes();
    const int INF = std::numeric_limits<int>::max();

    for (int node : all_nodes) dist[node] = INF;
    dist[source] = 0;

    std::set<std::pair<int, int>> queue;
    queue.insert({0, source});

    while (!queue.empty()) {
        int u = queue.begin()->second;
        queue.erase(queue.begin());

        for (int v : G.neighbours(u)) {
            int weight = 1; 
            if (dist[u] + weight < dist[v]) {
                queue.erase({dist[v], v});
                dist[v] = dist[u] + weight;
                queue.insert({dist[v], v});
            }
        }
    }

    std::cout << "Distanze da sorgente " << source << ":\n";
    for (const auto& pair : dist) {
        std::cout << "Nodo " << pair.first << " -> Distanza: " << pair.second << "\n";
    }
}




inline void save_to_graphviz(const unidirected_graph& G, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Errore nell'apertura del file " << filename << std::endl;
        return;
    }

    out << "graph G {\n";
    // Scrive tutti gli archi nel formato di GraphViz per grafi non diretti (--)
    for (const auto& edge : G.all_edges()) {
        out << "    " << edge.from() << " -- " << edge.to() << ";\n";
    }
    out << "}\n";
    out.close();
	
}

#endif