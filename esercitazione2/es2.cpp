#include <iostream>
#include <cmath>

int main() {
	
	static const int N = 10;
	int i;
	double arr[N] = { 0.1, 2.2, 4.5, 3.2, 1.2, 10.0, 4.3, 21.0, 7.8, 2.2};
	double min , max, somma, media, std;
	
	min = arr[0];
	max = arr[0];
	somma = arr[0];
	
	for (i=1;i<N;i++){
		min = std::min(min,arr[i]);
		max = std::max(max,arr[i]);
		somma +=arr[i];
	}
	media = somma/N;
	
	somma = arr[0];
	for(i=1;i<N;i++){
		somma += std::pow(arr[i]-media,2);
	}
	std = std::sqrt(somma/N);
	
	std::cout << "Il minimo del vettore e':" << min << "\n";
	std::cout << "Il massimo del vettore e':" << max << "\n";
	std::cout << "La media del vettore e':" << media << "\n";
	std::cout << "La deviazione standard del vettore e':" << std << "\n";
	
	
	
	
	
	return 0;
}
