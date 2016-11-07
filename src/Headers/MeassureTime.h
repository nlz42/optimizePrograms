/*
 * MeassureTime.h
 *
 *  Created on: 27.10.2016
 *      Author: nlz
 */

#ifndef HEADERS_MEASSURETIME_H_
#define HEADERS_MEASSURETIME_H_
#include <iostream>
#include <chrono>
#include <typeinfo>
#include "TestArrays.h"
#include "Constants.h"
#include <array>
#include <stdlib.h>

//sing namespace std;

/**
 * Komnzpet:
 * Meassure Time bekommt Funktikon Übergeben
 * Erzuegt selber die nötigen Arrays zur Zeitzmessung.
 */

template<typename T, size_t SIZE>
void meassureTime(size_t (*pFunc)(std::array<T, SIZE>,size_t)) {

	auto start_time = std::chrono::high_resolution_clock::now();

	std::array<T, SIZE> array = initArray(array, 1, 10);
	size_t startIndex = 0;

	auto end_time = std::chrono::high_resolution_clock::now();

	std::cout
			<< std::chrono::duration_cast<std::chrono::milliseconds>(
					end_time - start_time).count() << "millisec:";
	std::cout
			<< std::chrono::duration_cast<std::chrono::microseconds>(
					end_time - start_time).count() << "microsec:";

}

template<typename T, size_t SIZE>
//void meassureTimeSort(std::array<T, SIZE> (*pFunc)(std::array<T, SIZE>)) {
void meassureTimeSort( void(*pFunc)(std::array<T,SIZE> &a), std::array<T,SIZE>&array) {

	auto start_time = std::chrono::high_resolution_clock::now();

	//std::array<T, SIZE> array = initArray(array, 1, 9);
	pFunc(array);

	auto end_time = std::chrono::high_resolution_clock::now();

	std::cout
			<< std::chrono::duration_cast<std::chrono::milliseconds>(
					end_time - start_time).count() << "millisec:";
	std::cout
			<< std::chrono::duration_cast<std::chrono::microseconds>(
					end_time - start_time).count() << "microsec:";
//	for(size_t i =0;i<SIZE;i++){
//		std::cout<<array[i]<<", ";
//	}
	std::cout<<std::endl;
}


#endif /* HEADERS_MEASSURETIME_H_ */
