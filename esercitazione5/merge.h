#include <vector>
#include <limits>
#include <string>
#include <type_traits>

template <typename T>
void merge(std::vector<T>& A, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	
	std::vector<T> L(n1+1);
	std::vector<T> R(n2+1);
	
	for(int i = 0; i < n1; i++){
		L[i] = A[p + i];
	}
	
	for(int j = 0; j < n2; j++){
		R[j] = A[q + j + 1];
	}
	
	//HO CHIESTO ALL'IA COME IMPOSTARE A INF L E R NEL CASO DI UN VETTORE DI STRINGHE
	T sentinel;
    if constexpr (std::is_same_v<T, std::string>) {
        sentinel = "\x7F"; 
    } 
	else {
        sentinel = std::numeric_limits<T>::max();
    }

    L[n1] = sentinel;
    R[n2] = sentinel;
	
	int i = 0;
	int j = 0;
	
	for (int k = p; k <= r; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
		j++;
		}
	}
}

	
	