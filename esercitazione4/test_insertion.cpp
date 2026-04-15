#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>

#include "randfiller.h"
#include "is_sorted.h"
#include "insertion_sort.h"

int main(void)
{
    randfiller rf; 

    
    std::mt19937 gen_size(12345);
    std::uniform_int_distribution<size_t> size_dist(0, 1000);

   
    for (int i = 0; i < 100; i++) {
        size_t current_size = size_dist(gen_size);

        std::vector<int> vi;
        vi.resize(current_size); 

        if (current_size > 0) {
            rf.fill(vi, -1000, 1000); 
        }

        insertion_sort(vi);

        if (!is_sorted(vi)) {
            std::cerr << "ERRORE: Insertion Sort ha fallito su un vettore di interi!\n";
            return EXIT_FAILURE; 
        }
    }

   
    std::vector<std::string> vs;
    vs.resize(10);
    vs[0] = "settimana";
    vs[1] = "colore";
    vs[2] = "scuola";
    vs[3] = "stress";
    vs[4] = "lavoro";
    vs[5] = "sport";
    vs[6] = "scarpe";
    vs[7] = "pantaloncini";
    vs[8] = "ginocchiere";
    vs[9] = "rete";

    insertion_sort(vs);

    if (!is_sorted(vs)) {
        std::cerr << "ERRORE: Insertion Sort ha fallito sul vettore di stringhe!\n";
        return EXIT_FAILURE; 
    }

    std::cout << "Test di Insertion Sort completati con successo!\n";
    return EXIT_SUCCESS; 
}