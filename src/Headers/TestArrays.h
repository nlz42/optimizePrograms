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
#include "Constants.h"
#include <memory>

void flushCache();

template<std::size_t ArraySize>
void initArray(std::array<double, ArraySize> &array) {
	for (size_t i = 0; i < ArraySize; i++) {
		array[i] = (double) MIN + (((double) rand() / RAND_MAX)) * (MAXD - MIND);
	}
}

template<std::size_t ArraySize>
void initArray(std::array<int, ArraySize> &array) {
	for (size_t i = 0; i < ArraySize; i++) {
		array[i] = MIN + (rand() % (MAX - MIN + 1));
	}
}

template<typename T, std::size_t ArraySize>
void initArraySort(std::array<T, ArraySize> &array) {
	for (size_t i = 0; i < ArraySize; i++) {
		array[i] = (T) i;
	}
	return array;
}

#endif /* HEADERS_TESTARRAYS_H_ */
