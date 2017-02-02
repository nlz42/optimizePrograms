/*
 * ButtomUpMergesort.h
 *
 *  Created on: 01.12.2016
 *      Author: nlz
 */

#ifndef HEADERS_BUTTOMUPMERGESORT_H_
#define HEADERS_BUTTOMUPMERGESORT_H_
#include <memory>

template<typename T, size_t SIZE>
void mergeBitonic(std::array<T, SIZE> &array, std::array<T, SIZE> &wrkArray,
		size_t merge_step, size_t startIndex, size_t endIndex) {
	size_t wrk_ptr = 0;
	size_t left_ptr = 0;
	size_t right_ptr = 0;
	size_t middle_border = merge_step;

	while (wrk_ptr <= endIndex) {

		if (startIndex == 0 && endIndex == SIZE - 1) {
			left_ptr = wrk_ptr;
			right_ptr = middle_border + merge_step - 1;
		} else {
			wrk_ptr = startIndex;
			left_ptr = startIndex;
			right_ptr = endIndex;
			middle_border = merge_step;
		}

		while (left_ptr < middle_border) {
			wrkArray[wrk_ptr++] = array[left_ptr++];
		}

		while (right_ptr >= middle_border) {
			wrkArray[wrk_ptr++] = array[right_ptr--];
		}

		if (startIndex == 0 && endIndex == SIZE - 1) {
			left_ptr = middle_border - merge_step;
			right_ptr = middle_border + merge_step - 1;
			wrk_ptr = left_ptr;
		} else {
			wrk_ptr = startIndex;
			left_ptr = startIndex;
			right_ptr = endIndex;
		}

		while (left_ptr <= right_ptr) {
			if (wrkArray[left_ptr] <= wrkArray[right_ptr]) {
				array[wrk_ptr++] = wrkArray[left_ptr++];
			} else {
				array[wrk_ptr++] = wrkArray[right_ptr--];
			}
		}
		middle_border = middle_border + (2 * merge_step);
	}
}

template<typename T, size_t SIZE>
void mergeSort(std::array<T, SIZE> &array) {
	std::shared_ptr<std::array<T, SIZE>> workingArray(new std::array<T, SIZE>);
	const size_t halfOfArray = SIZE / 2;
	size_t merge_stepp = 1;
	for (; merge_stepp <= halfOfArray; merge_stepp *= 2) {
		mergeBitonic(array, *workingArray, merge_stepp, 0, SIZE - 1);
	}
}
#endif /* HEADERS_BUTTOMUPMERGESORT_H_ */
