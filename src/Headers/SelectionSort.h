/*
 * SelectionSort.h
 *
 *  Created on: 02.11.2016
 *      Author: nlz
 */

#ifndef HEADERS_SELECTIONSORT_H_
#define HEADERS_SELECTIONSORT_H_
#include "MinimumSearch.h"

//TODO impl selection sort
template <typename T, size_t SIZE>
std::array<T, SIZE> selectionSort(std::array<T,SIZE> array){
	T min = array[0];
	for(size_t i=1;i<SIZE;i++){
		//hioer jetzet minimum funtionen aufrugfen
		//TODO Index zurückliefern ! und swap einfügen
		min = minNormal(array,i);
		//XXX kp ob das so geht !!!
		std::swap(&array[i],&array[min]);
	}
//XXX just for testing
	for (size_t i=0;i<SIZE;i++){
		std::cout<<array[i]<<", ";
	}

}



#endif /* HEADERS_SELECTIONSORT_H_ */
