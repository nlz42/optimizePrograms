/*
 * TestArrays.h
 *
 *  Created on: 27.10.2016
 *      Author: nlz
 */

#ifndef HEADERS_TESTARRAYS_H_
#define HEADERS_TESTARRAYS_H_
#include <iostream>
#include<array>
#include <stdlib.h>

void flushCache();

template<std::size_t ArraySize>
std::array<double, ArraySize> initArray(std::array<double, ArraySize> array,
		std::size_t MIN, std::size_t MAX) {
	for (size_t i = 0; i < ArraySize; i++) {
		array[i] = (double) MIN + (((double) rand() / RAND_MAX)) * (MAX - MIN);
	}
	return array;
}

template<std::size_t ArraySize>
void initArray(std::array<int, ArraySize> &array, size_t MIN, size_t MAX) {
	for (size_t i = 0; i < ArraySize; i++) {
		array[i] = MIN + (rand() % (MAX - MIN + 1));
	}
}

template<typename T, std::size_t ArraySize>
std::array<T, ArraySize> initArraySort(std::array<T, ArraySize> array,
		std::size_t MIN, std::size_t MAX) {
	for (size_t i = 0; i < ArraySize; i++) {
		array[i] = (T) i;
	}
	return array;
}

#endif /* HEADERS_TESTARRAYS_H_ */

/**
 * zu kleinen doenle werte zu gering der vorteil.
 */
