#include <vector>
#include "quick_sort.h"

//Insertion Sort sui sottovettori, confinato agli indici p e r
template <typename T>
void insertion_sort_subarray(std::vector<T>& A, int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        T key = A[i];
        int j = i - 1;
        while (j >= p && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}


template <typename T>
void hybrid_quick_sort(std::vector<T>& A, int p, int r) {
    const int soglia = 215; 

    if (p < r) {
        
        if (r - p + 1 <= soglia) {
            insertion_sort_subarray(A, p, r);
        } 
   
        else {
            int q = partition(A, p, r);
            hybrid_quick_sort(A, p, q - 1);
            hybrid_quick_sort(A, q + 1, r);
        }
    }
}