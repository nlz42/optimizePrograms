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
void merge(std::array<T, SIZE> &array, std::array<T, SIZE> &wrkArray,
		size_t merge_step) {
	//const size_t halfOfArray = SIZE / 2;
	size_t wrk_ptr = 0; // pointer for wrkArray
	size_t left_ptr = 0; // right ptr of array
	size_t right_ptr = 0; // left ptr of array
	size_t middle_border = merge_step;

	while (wrk_ptr < SIZE && middle_border < SIZE) {
		//merge step loop
		left_ptr = wrk_ptr;
		right_ptr = middle_border;

		//while(left_ptr < middle_border || right_ptr < middle_border+merge_step  ){
		for (size_t i = 0; i < merge_step * 2; i++) {
			// both pointer in valid area
			if (left_ptr < middle_border
					&& right_ptr < middle_border + merge_step) {
				if (array[left_ptr] <= array[right_ptr]) {
					wrkArray[wrk_ptr] = array[left_ptr];
					left_ptr++;
				} else {
					wrkArray[wrk_ptr] = array[right_ptr];
					right_ptr++;
				}
			}
			// min one pointer is out of valid area
			else {
				//left ptr is in valid area
				if (left_ptr < middle_border) {
					wrkArray[wrk_ptr] = array[left_ptr];
					left_ptr++;
				}
				//right ptr is in valid area
				else {
					wrkArray[wrk_ptr] = array[right_ptr];
					right_ptr++;
				}
			}
			wrk_ptr++;
		}
		middle_border = middle_border + (2 * merge_step);
	}
	//copy to right array
	array = wrkArray;
}

template<typename T, size_t SIZE>
void mergeSort(std::array<T, SIZE> &array) {
	std::shared_ptr<std::array<T, SIZE>> workingArray(new std::array<T, SIZE>);
	const size_t halfOfArray = SIZE / 2;
	size_t merge_stepp = 1;
	for (; merge_stepp <= halfOfArray; merge_stepp *= 2) {
		merge(array, *workingArray, merge_stepp);
	}
}

#endif /* HEADERS_BUTTOMUPMERGESORT_H_ */
