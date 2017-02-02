/*
 * Constants.h
 *
 *  Created on: 26.10.2016
 *      Author: nlz
 */

#ifndef HEADERS_CONSTANTS_H_
#define HEADERS_CONSTANTS_H_

#include <stddef.h>
#include <string>

const int LINE_SIZE = 64;
const int L1_CACHE_SIZE = 4096;
const size_t SIZEsmall = 262144 ;
const size_t SIZEbig = 268435456;
const int MIN = 1;
const int MAX = 500;
const double MIND = 0.1;
const double MAXD = 1.0;
const size_t RecCancel = 8192;
const size_t WORST_CASE_CONST = 10;
const size_t SWITCH_SORT_ALGO = 25;

const std::string ALGO[]={
		"SelectionsSortNormal","SelectionSort2Loops","SelectionsSortPrefetch","InsertionSortNormal","InsertionSortPrefetch",
		"mergeSort","quickSort","quicksortHybrid"
};

#endif /* HEADERS_CONSTANTS_H_ */
