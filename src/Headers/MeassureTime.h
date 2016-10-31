/*
 * MeassureTime.h
 *
 *  Created on: 27.10.2016
 *      Author: nlz
 */

#ifndef HEADERS_MEASSURETIME_H_
#define HEADERS_MEASSURETIME_H_
#include <iostream>
#include "TestArrays.h"
#include <array>
#include <stdlib.h>
#include <chrono>

/**
 * Komnzpet:
 * Meassure Time bekommt Funktikon Übergeben
 * Erzuegt selber die nötigen Arrays zur Zeitzmessung.
 */

template<typename T, size_t SIZE>
void meassureTime(T (*pFunc)(std::array<T, SIZE>)){

	std::cout << "bin jetzt hier";
	std::array<int,128> a2 = initArray(a2, 0, 500);
	std::cout << "Minimum Int: =" << pFunc(a2) << std::endl;
	//T min = pFunc(a2);
}

template <typename T>
void sometest(){
	std::cout << "huiiiiiii";
}


/**
template <typename F>
void getTime (){

  	auto start_time = chrono::high_resolution_clock::now();

  	//f.run();


	auto end_time = chrono::high_resolution_clock::now();
	cout
			<< chrono::duration_cast<chrono::seconds>(end_time - start_time).count()
			<< ":";
	cout
			<< chrono::duration_cast<chrono::microseconds>(
					end_time - start_time).count() << ":";
	cout << "Hello world!" << endl;

}
**/
#endif /* HEADERS_MEASSURETIME_H_ */
