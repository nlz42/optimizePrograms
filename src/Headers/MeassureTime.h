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
#include <array>
#include <stdlib.h>

//sing namespace std;



/**
 * Komnzpet:
 * Meassure Time bekommt Funktikon Übergeben
 * Erzuegt selber die nötigen Arrays zur Zeitzmessung.
 */

template<typename T, size_t SIZE>
void meassureTime(T (*pFunc)(std::array<T, SIZE>,size_t)){

	auto start_time = std::chrono::high_resolution_clock::now();

	std::array<T,128> array = initArray(array, 0, 500);
	size_t startIndex=0;
	std::cout << "Typ: "<<typeid(T).name()<<", minimum ist: =" << pFunc(array,startIndex) << std::endl;

	int j = 0;
	for (int i= 0; i<9000000;i++){
		j+=1;
	}

	auto end_time = std::chrono::high_resolution_clock::now();

	std::cout
			<< std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count()
			<< "sec:";

	std::cout
			<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
			<< "millisec:";
	std::cout
			<< std::chrono::duration_cast<std::chrono::microseconds>(
					end_time - start_time).count() << "microsec:";

}

#endif /* HEADERS_MEASSURETIME_H_ */
