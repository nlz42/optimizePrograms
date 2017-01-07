/*
 * QuickSort.h
 *
 *  Created on: 22.12.2016
 *      Author: nlz
 */

#ifndef HEADERS_QUICKSORT_H_
#define HEADERS_QUICKSORT_H_

#include "CheckArrrays.h"
#include "ButtomUpMergesort.h"

template< typename T,std::size_t N>
void threeWaySort(std::array<T, N> &a, size_t lo, size_t hi) {
	if (hi <= lo) {
		return;
	}
	size_t lt = lo;
	size_t gt = hi;
	T p = a[lo];
	size_t i = lo;
	while (i <= gt) {
		if (p > a[i]) {
			std::swap(a[lt], a[i]);
			lt++;
			i++;
		} else if (p < a[i]) {
			std::swap(a[i], a[gt]);
			gt--;
		} else {
			i++;
		}
	}
	threeWaySort(a, lo, (lt==0)? 0:(lt-1) );
	threeWaySort(a, (gt+1), hi);
}

template<std::size_t N, typename T>
void threeWaySortHybrid(std::array<T, N> &a, size_t lo, size_t hi) {
	if (hi <= lo) {
		return;
	}
	size_t lt = lo;
	size_t gt = hi;
	T p = a[lo];
	size_t i = lo;
	while (i <= gt) {
		if (p > a[i]) {
			std::swap(a[lt], a[i]);
			lt++;
			i++;
		} else if (p < a[i]) {
			std::swap(a[i], a[gt]);
			gt--;
		} else {
			i++;
		}
	}

	if( ((lt==0)? 0:(lt-1))-lo < 50){
		insertionSortPrefetchIndexes(a,lo,(lt==0)? 0:(lt-1));
	} else {
		threeWaySortHybrid(a, lo,  (lt==0)? 0:(lt-1));
	}

	if(hi - (gt+1) < 50){
		insertionSortPrefetchIndexes(a,gt+1,hi);
	} else{
		threeWaySortHybrid(a, gt + 1, hi);
	}
}

template< typename T, std::size_t N>
void quicksortHybrid(std::array<T, N> &a) {
	if (checkArray(a) == 1) {
		return; // array is already sorted
	}
	if (checkArrayDesc(a) == 1) {
		//Worst Case is descending ordered array
		size_t middleOfArray = N / 2;
		threeWaySortHybrid(a, 0, middleOfArray - 1);
		threeWaySortHybrid(a, middleOfArray, N - 1);
		//merge array
		std::shared_ptr<std::array<T, N>> workingArray(new std::array<T, N>);
		mergeBitonic(a, *workingArray, middleOfArray);
	} else {
		threeWaySortHybrid(a, 0, N - 1);
	}
}

template<std::size_t N,typename T>
void quickSort(std::array<T, N> &a) {
	threeWaySort(a,0,(N-1));
}

#endif /* HEADERS_QUICKSORT_H_ */
