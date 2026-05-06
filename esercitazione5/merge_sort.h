#include <vector>
#include "merge.h"

template<typename T>
void merge_sort(std::vector<T>& A, int p, int r){
	if(p < r){
		int q = (p + r) / 2;
		merge_sort(A,p,q);
		merge_sort(A, q + 1,r);
		merge(A,p,q,r);
	}
}



