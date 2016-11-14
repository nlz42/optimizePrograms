#ifndef HEADERS_OPTIMIZEPROGRAMS_H_
#define HEADERS_OPTIMIZEPROGRAMS_H_


#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <cstdio>
#define __STRICT_ANSI__
#else
#include <cstdio>
#endif

//#include <chrono>
#include <array>
#include <memory>
#include "gtest/gtest.h"
//#include "TestArrays.h"
#include "MinimumSearch.h"
#include "SelectionSort.h"
#include "Constants.h"
#include "MeassureTime.h"

template <typename T, size_t SIZE>
int checkArray(std::array<T,SIZE> &array) {
	int result = 1; // true
	for (size_t i = 0; i < array.size() - 1; i++) {
		if (!(array[i] <= array[i + 1])) {
			result = 0; // false
		}
	}
	return result;
}

template <typename T, size_t SIZE>
int checkArrayDesc(std::array<T,SIZE> &array) {
	int result = 1; // true
	for (size_t i = 0; i < array.size() - 1; i++) {
		if (!(array[i] >= array[i + 1])) {
			result = 0; // false
		}
	}
	return result;
}

#endif
