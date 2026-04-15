#include <iostream>
#include <vector> 
#include <algorithm>
#include "randfiller.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "timecounter.h"

int main(void)
{
	randfiller rf;
	timecounter tc;
	
	for(size_t i = 4; i<=8192; i*=2) {
		std::vector<int> vec;
		vec.resize(i);
		rf.fill(vec, -10000, 10000);
		
		std::cout << "Vettori di dimensione " << i << ":\n";
		std::vector<int> vec_bubble = vec;
		std::vector<int> vec_selection = vec;
		std::vector<int> vec_insertion = vec;
		std::vector<int> vec_std = vec;
		
		tc.tic();
		bubble_sort(vec_bubble);
		double time_bubble = tc.toc();
		std:: cout << "Tempo per il bubble: " << time_bubble << "secondi\n";	
		
		tc.tic();
		insertion_sort(vec_insertion);
		double time_insertion = tc.toc();
		std:: cout << "Tempo per l'insertion: " << time_insertion << "secondi\n";
		
		tc.tic();
		selection_sort(vec_selection);
		double time_selection = tc.toc();
		std:: cout << "Tempo per il selection: " << time_selection << "secondi\n";
		
		tc.tic();
		std::sort(vec_std.begin(), vec_std.end());
		double time_std = tc.toc();
		std:: cout << "Tempo per std: " << time_std << "secondi\n";
		
	}
	return 0;
	
}
	