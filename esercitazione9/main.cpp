#include <iostream>
#include "unidirected_graph.h"


int main() {
    unidirected_graph G;
    G.add_edge(1, 2);
    G.add_edge(2, 3);
    G.add_edge(3, 4);
    G.add_edge(4, 1);
    G.add_edge(1, 3); 

    std::cout << "--- TEST ESERCITAZIONE 9 ---" << std::endl;

    // Test BFS 
    fifo q;
    unidirected_graph bfsG = graph_visit(G, 1, q);
    std::cout << "Archi albero BFS: ";
    for (const auto& e : bfsG.all_edges()) std::cout << e << " ";
    std::cout << "\n";

    // Test DFS Iterativa 
    lifo s;
    unidirected_graph dfsG = graph_visit(G, 1, s);
    std::cout << "Archi albero DFS Iterativa: ";
    for (const auto& e : dfsG.all_edges()) std::cout << e << " ";
    std::cout << "\n";

    // Test DFS Ricorsiva 
    unidirected_graph dfsRecG = recursive_dfs(G, 1);
    std::cout << "Archi albero DFS Ricorsiva: ";
    for (const auto& e : dfsRecG.all_edges()) std::cout << e << " ";
    std::cout << "\n\n";

    // Test Dijkstra 
    dijkstra(G, 1);

	save_to_graphviz(bfsG, "bfs_tree.dot");
    save_to_graphviz(dfsG, "dfs_tree.dot");

    std::cout << "\nFile .dot per GraphViz generati con successo!" << std::endl;
    return 0;
}