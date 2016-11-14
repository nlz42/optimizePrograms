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

template<typename T, size_t SIZE>
struct recTime {
	void meassureTimeSort(int algo) {
		std::shared_ptr<std::array<T, SIZE>> array(new std::array<T, SIZE>);

		auto pFunc1 = choiceAlgoSimple(algo);
		for (size_t i = 0; i<3; i++) {
			initArrayValues(i, *array);
			flushCache();
			auto start_time = std::chrono::high_resolution_clock::now();
			pFunc1(*array);
			auto end_time = std::chrono::high_resolution_clock::now();
			std::cout
					<< std::chrono::duration_cast<std::chrono::milliseconds>(
							end_time - start_time).count() << ",ms,"
					<< " bei N=," << SIZE << std::endl;

		}
		recTime<T, SIZE * 2> tc;
		std::shared_ptr<std::array<T, SIZE * 2>> array1(
				new std::array<T, SIZE * 2>);
		tc.meassureTimeSort(algo);
	}
	;

	auto choiceAlgoSimple(int algo) {
		switch (algo) {
		case 0:
			return selectionSortNormal<T, (SIZE)> ;
			break;
		case 1:
			return selectionSortmin2loops<T, (SIZE)> ;
			break;
		case 2:
			return selectionSortPrefetch<T, (SIZE)> ;
			break;
		default:
			std::cout << std::endl << "ERROR ### ERROR" << std::endl;
			exit(1);
		}

	}

	void initArrayValues(int i, std::array<T, SIZE> &array) {
		switch (i) {
		case 0:
			initArray(array);
			std::cout << "Random Array,";
			break;
		case 1:
			initArrayAscending(array);
			std::cout << "Ascending Array,";
			break;
		case 2:
			initArrayDescending(array);
			std::cout << "Descending Array,";
			break;
		default:
			initArray(array);
			break;

		}
	}
};

template<typename T>
struct recTime<T, RecCancel> {
	void meassureTimeSort(int algo) {
		algo = 0;
		algo = algo - 1;
	}
	;
};
#endif /* HEADERS_MEASSURETIME_H_ */
