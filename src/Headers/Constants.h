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

/**
 * CONSTANT Values in Bytes
 * int 4 Byte 32 bit groß
 * double 8 Byte 64 bit groß
 */
const int LINE_SIZE = 64;
const int L1_CACHE_SIZE = 4096;
const size_t SIZEsmall = 262144 ; //2^18 for qudratic O-runtime
const size_t SIZEbig = 268435456; // 2^28 // ful memory with double values
//Const für array erzeugung und rekurions abbruch
const int MIN = 1;
const int MAX = 500;
const double MIND = 0.1;
const double MAXD = 1.0;
const size_t RecCancel = 8192; // 2^13
const size_t WORST_CASE_CONST = 10;

const std::string ALGO[]={
		"SelectionsSortNormal","SelectionSort2Loops","SelectionsSortPrefetch","InsertionSortNormal","InsertionSortPrefetch",
		"mergeSort","quickSort","quicksortHybrid"
};

#endif /* HEADERS_CONSTANTS_H_ */
