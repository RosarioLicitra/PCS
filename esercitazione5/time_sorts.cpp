#include <iostream>
#include <vector> 
#include <algorithm>
#include "randfiller.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "timecounter.h"

int main(void)
{
	randfiller rf;
	timecounter tc;
	
	std::cout << std::fixed << std::setprecision(4);
	
	for(size_t i = 20; i <= 300 ; i+=5) {
		
		
		std::vector<std::vector<int>> original_vectors;
		original_vectors.resize(100);
		for(int k = 0; k < 100; k++) {
			original_vectors[k].resize(i);
			rf.fill(original_vectors[k], -10000, 10000);
		}
		
		std::cout << "\nVettori di dimensione " << i << ":\n";
		
		
		std::vector<std::vector<int>> vec_bubble = original_vectors;
		std::vector<std::vector<int>> vec_selection = original_vectors;
		std::vector<std::vector<int>> vec_insertion = original_vectors;
		std::vector<std::vector<int>> vec_merge = original_vectors;
		std::vector<std::vector<int>> vec_quick = original_vectors;
		std::vector<std::vector<int>> vec_std = original_vectors;
		
		// --- BUBBLESORT ---
		tc.tic();
		for(int k = 0; k < 100; k++) {
			bubble_sort(vec_bubble[k]);
		}
		double time_bubble = tc.toc() / 100.0;
		std::cout << "Tempo per il bubble: " << time_bubble*1000.0 << "ms\n";	
		
		// --- INSERTIONSORT ---
		tc.tic();
		for(int k = 0; k < 100; k++) {
			insertion_sort(vec_insertion[k]);
		}
		double time_insertion = tc.toc() / 100.0;
		std::cout << "Tempo per l'insertion: " << time_insertion*1000.0 << "ms\n";
		
		// --- SELECTIONSORT ---
		tc.tic();
		for(int k = 0; k < 100; k++) {
			selection_sort(vec_selection[k]);
		}
		double time_selection = tc.toc() / 100.0;
		std::cout << "Tempo per il selection: " << time_selection*1000.0 << "ms\n";

		// --- MERGESORT ---
		tc.tic();
		for(int k = 0; k < 100; k++) {
			merge_sort(vec_merge[k], 0, vec_merge[k].size() - 1);
		}
		double time_merge = tc.toc() / 100.0;
		std::cout << "Tempo per il merge: " << time_merge*1000.0 << "ms\n";

		// --- QUICKSORT ---
		tc.tic();
		for(int k = 0; k < 100; k++) {
			quick_sort(vec_quick[k], 0, vec_quick[k].size() - 1);
		}
		double time_quick = tc.toc() / 100.0;
		std::cout << "Tempo per il quick: " << time_quick*1000.0 << "ms\n";
		
		// --- STD::SORT ---
		tc.tic();
		for(int k = 0; k < 100; k++) {
			std::sort(vec_std[k].begin(), vec_std[k].end());
		}
		double time_std = tc.toc() / 100.0;
		std::cout << "Tempo per std: " << time_std*1000.0 << "ms\n";
		
	}
	return 0;
}