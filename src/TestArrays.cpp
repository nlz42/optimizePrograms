/*
 * TestArrays.cpp
 *
 *  Created on: 27.10.2016
 *      Author: nlz
 */

#include"Headers/TestArrays.h"

void flushCache() {
	std::shared_ptr<std::array<int, SIZEbig>> flushArray(new std::array<int, SIZEbig>);
	initArray(*flushArray);
	for(size_t i=0;i<SIZEbig;i++){
		(*flushArray)[i]=(*flushArray)[i]+1;
	}
}
