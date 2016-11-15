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
const size_t SIZEsmall = 16000; // 102.400
const size_t SIZEbig = 1024*1000; // 1.024.000
//Const für array erzeugung und rekurions abbruch
const int MIN = 1;
const int MAX = 500;
const double MIND = 0.1;
const double MAXD = 1.0;
const size_t RecCancel = 256000*2;

const std::string ALGO[]={
		"SelectionsSortNormal","SelectionSort2Loops","SelectionsSortPrefetch"
};

#endif /* HEADERS_CONSTANTS_H_ */
