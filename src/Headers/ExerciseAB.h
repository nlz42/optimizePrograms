/*
 * ExerciseAB.h
 *
 *  Created on: 25.10.2016
 *      Author: nlz
 */
#ifndef HEADERS_EXERCISEAB_H_
#define HEADERS_EXERCISEAB_H_

#include <array>
#include "Constants.h"


/**
 * TODO: statt werte nur indexe merken ! schenller
 */
template <typename T, size_t SIZE>
T minTwoLoops(std::array<T, SIZE> a){
	T result = a[0];
	for (size_t i=0;i<SIZE;i+=LINE_SIZE){
		for(size_t j=0;j<64;j++){
			if(result>a[i+j]){
				result = a[i+j];
			}
		}
	}
	return result;;
}

template <typename T, size_t SIZE>
T minNormal(std::array<T, SIZE> a){
	T result = a[0];
	for(size_t i=0; i<SIZE;i++){
		if(result>a[i]){
			result = a[i];
		}
	}
	return result;;
}

#endif /* HEADERS_EXERCISEAB_H_ */
