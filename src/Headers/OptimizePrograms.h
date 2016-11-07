#ifndef HEADERS_OPTIMIZEPROGRAMS_H_
#define HEADERS_OPTIMIZEPROGRAMS_H_


#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <cstdio>
#define __STRICT_ANSI__
#else
#include <cstdio>
#endif

//#include <chrono>
#include <array>
#include <memory>
#include "gtest/gtest.h"
//#include "TestArrays.h"
#include "MinimumSearch.h"
#include "SelectionSort.h"
#include "Constants.h"
#include "MeassureTime.h"

void flushCache();

#endif