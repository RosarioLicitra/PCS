#include <vector>
#include "partition.h"

template <typename T>
void quick_sort(std::vector<T>& A, int p, int r){
	if(p < r){
		int q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q + 1, r);
	}
}
