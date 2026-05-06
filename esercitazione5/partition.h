#include <vector>

template<typename T>
int partition(std::vector<T>& A, int p, int r){
	T x = A[r];
	int i = p - 1;
	for(int j = p; j < r; j++){
		if(A[j] <= x){
			i++;
			T temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	T temp = A[r];
	A[r] = A[i+1];
	A[i+1] = temp;
	return i + 1;
}
