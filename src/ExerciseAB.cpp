/*
 * ExerciseAB.cpp
 *
 *  Created on: 18.10.2016
 *      Author: nlz
 */

#include<array>

template <typename T, size_t SIZE>

T min(std::array<T, SIZE> a) {
	T result = a[0];
	for(size_t i=0; i<SIZE;i++){
		if(result>a[i]){
			result = a[i];
		}
	}
	return result;
}

