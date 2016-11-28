/*
 * InsertionSort.h
 *
 *  Created on: 24.11.2016
 *      Author: nlz
 */

#ifndef HEADERS_INSERTIONSORT_H_
#define HEADERS_INSERTIONSORT_H_

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
void insertionSortPrefetch(std::array<T, SIZE> &array) {
	const size_t STEP = LINE_SIZE / sizeof(T);
	for (size_t i = 1; i < SIZE; i++) {
		size_t j = (i>=(STEP))? i : (STEP);
		for (; j >= (STEP) &&array[i-1]>array[i]  ; j -= STEP) {
			__builtin_prefetch(&array[j - (2*STEP)]);
			size_t index=i;
			for(size_t k=STEP;k>=0 && array[(index)-1]>array[index] && index > 0 ;k--){
				std::swap(array[(index)- 1], array[index]);
				index--;
			}
		}
	}
}

#endif /* HEADERS_INSERTIONSORT_H_ */