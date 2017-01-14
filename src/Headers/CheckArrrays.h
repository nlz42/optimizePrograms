/*
 * CheckArrrays.h
 *
 *  Created on: 04.01.2017
 *      Author: nlz
 */

#ifndef HEADERS_CHECKARRRAYS_H_
#define HEADERS_CHECKARRRAYS_H_

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

#endif /* HEADERS_CHECKARRRAYS_H_ */
