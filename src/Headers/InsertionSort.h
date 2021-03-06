/*
 * InsertionSort.h
 *
 *  Created on: 24.11.2016
 *      Author: nlz
 */

#ifndef HEADERS_INSERTIONSORT_H_
#define HEADERS_INSERTIONSORT_H_
#include <stdlib.h>
#include <iostream>

template<typename T, size_t SIZE>
void insertionSortNormal(std::array<T, SIZE> &array) {
	for (size_t i = 1; i < SIZE; i++) {
		size_t j = i;
		for (; j >= 1 && array[j - 1] > array[j]; j--) {
			std::swap(array[j - 1], array[j]);
		}
	}
}

template<typename T, size_t SIZE>
void insertionSortPrefetchIndexes(std::array<T, SIZE> &array, size_t startIndex, size_t endIndex) {
	const size_t STEP = LINE_SIZE / sizeof(T);
	size_t index=0;
	for (size_t i = startIndex+1; i <= endIndex; i++) {
		index=i;
		for (; array[index-1]>array[index] && index>startIndex;) {
			__builtin_prefetch(&array[index - (2*STEP)]);
			for(size_t k=(STEP);index>startIndex && k>0 && array[index-1]>array[index];k--){
				std::swap(array[index-1], array[index]);
				index = index-1;
			}
		}
	}
}

template<typename T, size_t SIZE>
void insertionSortPrefetch(std::array<T, SIZE> &array) {
	insertionSortPrefetchIndexes(array,0,SIZE-1);
}


#endif /* HEADERS_INSERTIONSORT_H_ */
