/*
 * ExerciseAB.h
 *
 *  Created on: 25.10.2016
 *      Author: nlz
 */
#ifndef HEADERS_MINIMUMSEARCH_H_
#define HEADERS_MINIMUMSEARCH_H_

#include <array>
#include "Constants.h"

template<typename T, size_t SIZE>
size_t minNormal(std::array<T, SIZE>&a, size_t left) {
	size_t minIndex = left;
	for (; left < SIZE; left++) {
		if (a[minIndex] > a[left]) {
			minIndex = left;
		}
	}
	return minIndex;
}

template<typename T, size_t SIZE>
size_t minTwoLoops(std::array<T, SIZE> &a, size_t left) {
	const size_t STEP = LINE_SIZE/sizeof(T);
	size_t minIndex = left;
	for (; left < SIZE; left+=STEP) {
		for (size_t j=0; j < STEP && (j+left)<SIZE; j++) {
			if (a[minIndex] > a[left + j]) {
				minIndex = left + j;
			}
		}
	}
	return minIndex;
}

template<typename T, size_t SIZE>
size_t minTwoLoopsPrefetch(std::array<T, SIZE> &a, size_t left) {
	const size_t STEP = LINE_SIZE/sizeof(T);
	size_t minIndex = left;
	for (; left < SIZE; left+=STEP) {
		__builtin_prefetch(&a[left+STEP+1]);
		for (size_t j=0; j < STEP && (j+left)<SIZE; j++) {
			if (a[minIndex] > a[left + j]) {
				minIndex = left + j;
			}
		}
	}
	return minIndex;
}

#endif /* HEADERS_MINIMUMSEARCH_H_ */
