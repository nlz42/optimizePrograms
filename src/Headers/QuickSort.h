/*
 * QuickSort.h
 *
 *  Created on: 22.12.2016
 *      Author: nlz
 */

#ifndef HEADERS_QUICKSORT_H_
#define HEADERS_QUICKSORT_H_


template <typename T, size_t SIZE>
void partioningArray(std::array<T,SIZE> &a, size_t l, size_t r, size_t &middle){

	size_t i=l+1;
	size_t j=r;
	T p = a[l];

	//ptr runs into the middle#
	while (i<=j){
		if(a[i] <= p){
			i++;
		} else if(a[j] > p){
			j--;
		} else {
			std::swap(a[i],a[j]);
		}
	}
	//set p onto the middle of the two sub array
	std::swap(a[l],a[j]);
	middle = j;
}

template <typename T, size_t SIZE>
void threeWayPartition(std::array<T,SIZE> &array, size_t left, size_t right){
	//little helper
	size_t middle =0;
	//array is empty
	if(left >= right){
		return;
	}
	partioningArray(array,left,right, middle);

	threeWayPartition(array,left,middle-1);
	threeWayPartition(array,middle+1,right);

}

template<typename T, size_t SIZE>
void quickSort(std::array<T,SIZE> &array){

	threeWayPartition(array,0,SIZE-1);

}


#endif /* HEADERS_QUICKSORT_H_ */
