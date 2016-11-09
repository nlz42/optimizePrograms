/*
 * Constants.h
 *
 *  Created on: 26.10.2016
 *      Author: nlz
 */

#ifndef HEADERS_CONSTANTS_H_
#define HEADERS_CONSTANTS_H_

#include <stddef.h>

//CONSTANT Values in Bytes
const int LINE_SIZE = 64;
const int L1_CACHE_SIZE = 4096;
const size_t SIZEsmall = 32000; // 102.400
const size_t SIZEbig = 1024*1000; // 1.024.000
const size_t MIN = 1;
const size_t MAX = 500;

enum ALGO{
	sortSelectionSortNormal,
	sortSelectionSortMin2Loops,
	sortSelectionSortPrefetch
};

#endif /* HEADERS_CONSTANTS_H_ */

/**
 * int 4 Byte 32 bit groﬂ
 * double 8 Byte 64 bit groﬂ
 */
