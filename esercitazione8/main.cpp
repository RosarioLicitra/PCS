#include <iostream>
#include <cassert>
#include "unidirected_graph.h"

int main() {
    

    std::cout << "--- Test Classe unidirected_edge ---" << std::endl;
    unidirected_edge e1(5, 2);
    std::cout << "Arco creato con (5, 2): " << e1 << std::endl;
    assert(e1.from() == 2 && e1.to() == 5);
    
    unidirected_edge e2(2, 5);
    assert(e1 == e2); 
    std::cout << "Test uguaglianza archi: Superato" << std::endl;

    std::cout << "\n--- Test Classe unidirected_graph ---" << std::endl;
    unidirected_graph g1;
    

    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(1, 3);
    g1.add_edge(3, 4);


    std::cout << "Vicini del nodo 3: ";
    auto n3 = g1.neighbours(3);
    for (int node : n3) std::cout << node << " "; 
    std::cout << std::endl;


    unidirected_edge search_edge(3, 2);
    int id = g1.edge_number(search_edge);
    std::cout << "L'arco (3,2) ha indice: " << id << std::endl;
    std::cout << "L'arco all'indice " << id << " e': " << g1.edge_at(id) << std::endl;

   std::cout << "\n--- Test Operatore Differenza (G1 - G2) ---" << std::endl;
    unidirected_graph g2;
    g2.add_edge(1, 2);
    g2.add_edge(2, 3);

    unidirected_graph diff_graph = g1 - g2;

    std::cout << "Archi nel grafo differenza (G1 - G2):" << std::endl;
    auto archi_risultato = diff_graph.all_edges();
    for (const auto& e : archi_risultato) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "\n--- Tutti i test completati con successo! ---" << std::endl;

    return 0;
}

