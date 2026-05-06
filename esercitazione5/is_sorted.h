#include <vector>

template<typename T>
bool is_sorted(const std::vector<T>& A) {
	
	if(A.size() <=1) {
		return true;
	}
	
	for(size_t i = 0; i< A.size() - 1; i++) {
		if(A[i] > A[i+1]) {
			return false;
		}
	}
	
	return true;
}
