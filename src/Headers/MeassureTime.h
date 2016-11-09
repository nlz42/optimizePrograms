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
				std::array<T, SIZE>&array, ALGO algo){
			flushCache();

			auto start_time = std::chrono::high_resolution_clock::now();

			pFunc(array);

			auto end_time = std::chrono::high_resolution_clock::now();

			std::cout
					<< std::chrono::duration_cast<std::chrono::milliseconds>(
							end_time - start_time).count() << "ms:" << SIZE;

			recTime<T,SIZE*2> tc;
			std::shared_ptr<std::array<int, SIZE*2>> array1(new std::array<int, SIZE*2>);
			auto *pFunc2 = choiceAlgo(algo);

			tc.meassureTimeSort(*pFunc2, *array1, algo);
		};

		auto choiceAlgo(ALGO algo){
			switch ( algo )
			{
			    case sortSelectionSortNormal:
			        return selectionSortNormal<T,(SIZE*2)>;
			        break;
			    case sortSelectionSortMin2Loops:
			    	return selectionSortmin2loops<T,(SIZE*2)>;
			    	break;
			    default:
			    	return selectionSortNormal<T,(SIZE*2)>;
			}

		}
};

template<typename T>
struct recTime <T, 64000> {
	void meassureTimeSort(void (*pFunc)(std::array<T, 64000> &a),
			std::array<T, 64000>&array, ALGO algo) {
		flushCache();

		auto start_time = std::chrono::high_resolution_clock::now();

		pFunc(array);

		auto end_time = std::chrono::high_resolution_clock::now();

		std::cout
				<< std::chrono::duration_cast<std::chrono::milliseconds>(
						end_time - start_time).count() << "ms:ENDE REKURSION";
	};
};
#endif /* HEADERS_MEASSURETIME_H_ */
