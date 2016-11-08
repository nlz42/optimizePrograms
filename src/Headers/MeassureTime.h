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
#include <memory>
#include <typeinfo>
#include "TestArrays.h"
#include "Constants.h"
#include "SelectionSort.h"
#include <array>
#include <stdlib.h>

//sing namespace std;

/**
 * Komnzpet:
 * Meassure Time bekommt Funktikon Übergeben
 * Erzuegt selber die nötigen Arrays zur Zeitzmessung.
 */
template <typename T, size_t SIZE>
struct recTime  {
		void meassureTimeSort(void (*pFunc)(std::array<T, SIZE> &a),
				std::array<T, SIZE>&array) {
			flushCache();

			auto start_time = std::chrono::high_resolution_clock::now();

			pFunc(array);

			auto end_time = std::chrono::high_resolution_clock::now();

			std::cout
					<< std::chrono::duration_cast<std::chrono::milliseconds>(
							end_time - start_time).count() << "ms:" << SIZE;

			recTime<T,SIZE*2> tc;
			std::shared_ptr<std::array<int, SIZE*2>> array1(new std::array<int, SIZE*2>);

			//auto *pFunc2 = selectionSortNormal<T,SIZE*2>;
			auto *pFunc2 = (void (*)(std::array<T,SIZE*2>&))&pFunc;

			tc.meassureTimeSort(*pFunc2, *array1);
		};
};

template<typename T>
struct recTime <T, 64000> {
	void meassureTimeSort(void (*pFunc)(std::array<T, 64000> &a),
			std::array<T, 64000>&array) {
		flushCache();

		auto start_time = std::chrono::high_resolution_clock::now();

		pFunc(array);

		auto end_time = std::chrono::high_resolution_clock::now();

		std::cout
				<< std::chrono::duration_cast<std::chrono::milliseconds>(
						end_time - start_time).count() << "ms:ENDE REKURSION";
	};
};

/**
template<typename T, size_t SIZE>
size_t meassureTimeSort(void (*pFunc)(std::array<T, SIZE> &a),
		std::array<T, SIZE>&array) {
	flushCache();

	auto start_time = std::chrono::high_resolution_clock::now();

	pFunc(array);

	auto end_time = std::chrono::high_resolution_clock::now();

	std::cout
			<< std::chrono::duration_cast<std::chrono::milliseconds>(
					end_time - start_time).count() << "ms:" << SIZE;

	size_t x=SIZE*2;
	return x;
}
*/

#endif /* HEADERS_MEASSURETIME_H_ */
