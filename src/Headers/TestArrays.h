/*
 * TestArrays.h
 *
 *  Created on: 27.10.2016
 *      Author: nlz
 */

#ifndef HEADERS_TESTARRAYS_H_
#define HEADERS_TESTARRAYS_H_

#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <cstdio>
#define __STRICT_ANSI__
#else
#include <cstdio>
#endif

#include <iostream>
#include <memory>
#include<array>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "Constants.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ButtomUpMergesort.h"
#include "QuickSort.h"
#include "CheckArrrays.h"
#include <memory>

void flushCache();

void runAllTests();

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
void initArrayAscending(std::array<T, ArraySize> &array) {
	for (size_t i = 0; i < ArraySize; i++) {
		array[i] = (T) i;
	}
}

template<typename T, std::size_t ArraySize>
void initArrayDescending(std::array<T, ArraySize> &array) {
	for (size_t i = 0; i < ArraySize ; i++) {
		array[i] = (T) ArraySize-i;
	}
}

#endif /* HEADERS_TESTARRAYS_H_ */
