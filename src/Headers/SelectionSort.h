/*
 * SelectionSort.h
 *
 *  Created on: 02.11.2016
 *      Author: nlz
 */

#ifndef HEADERS_SELECTIONSORT_H_
#define HEADERS_SELECTIONSORT_H_
#include "MinimumSearch.h"

//TODO impl selection sort
template <typename T, size_t SIZE>
void selectionSortNormal(std::array<T,SIZE> &array){
	size_t min = 0;
	for(size_t i=0;i<SIZE;i++){
		min = minNormal(array,i);
		std::swap(array[i],array[min]);
	}
}

template <typename T, size_t SIZE>
void selectionSortmin2loops(std::array<T,SIZE> &array){
	size_t min = 0;
	for(size_t i=0;i<SIZE;i++){
		min = minTwoLoops(array,i);
		std::swap(array[i],array[min]);
	}
}

template <typename T, size_t SIZE>
void selectionSortPrefetch(std::array<T,SIZE> &array){
	size_t min = 0;
	for(size_t i=0;i<SIZE;i++){
		min = minTwoLoopsPrefetch(array,i);
		std::swap(array[i],array[min]);
	}
}



#endif /* HEADERS_SELECTIONSORT_H_ */
