/*
 * QuickSort.h
 *
 *  Created on: 22.12.2016
 *      Author: nlz
 */

#ifndef HEADERS_QUICKSORT_H_
#define HEADERS_QUICKSORT_H_

template<std::size_t N, typename T>
void threeWayPartioning(std::array<T, N>& array, size_t left_ptr, size_t right_ptr) {

	//rec cancel
	if(right_ptr<=left_ptr){
		return;
	}

	size_t startleft = left_ptr;
	size_t startright = right_ptr;

	std::size_t itr = left_ptr;

	T pivot = array[right_ptr-1];

	while(itr < right_ptr) {
		if(array[itr]< pivot) {
			std::swap(array[itr++], array[left_ptr++]);
		} else if (array[itr]== pivot) {
			itr++; //no swapping needed is equal
		} else {
			std::swap(array[itr], array[right_ptr-1]);
			right_ptr--;
		}
	}

	threeWayPartioning(array, startleft, left_ptr);
	threeWayPartioning(array, itr, startright);
}


template<typename T, size_t SIZE>
void quickSort(std::array<T,SIZE> &array){
	threeWayPartioning(array,0,SIZE-1);
}


#endif /* HEADERS_QUICKSORT_H_ */
