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
		size_t j = i;
		for (; j >= 1 ; j -= STEP) {
			__builtin_prefetch(&array[j - STEP - 1]);
			std::cout << j << std::endl;
			/**
			for (size_t k = STEP - 1;
					k >= 0 && (j - k) >= 0 && array[(j + k) - 1] > array[j + k];
					k--)
				std::swap(array[(j + k) - 1], array[j + k]){}*/
		}
	}
}

#endif /* HEADERS_INSERTIONSORT_H_ */
