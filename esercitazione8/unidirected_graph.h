#ifndef UNIDIRECTED_GRAPH_H
#define UNIDIRECTED_GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdexcept>


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
	
#endif