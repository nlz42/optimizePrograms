//============================================================================
// Name        : OptimizePrograms.cpp
// Author      : nlz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <cstdio>
#define __STRICT_ANSI__
#else
#include <cstdio>
#endif

#include <array>
#include <chrono>
#include "TestCases.cpp"
#include "ExerciseAB.cpp"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv) {

	auto i = 0;
	auto y = 2;
	cout << "!!!Hello Worl!!!" << endl; // prints !!!Hello World!!!
	i = i + y;
	cout << i << endl;

	// testing chrono library
	auto start_time = chrono::high_resolution_clock::now();
	int temp;
	for (int i = 0; i < 242000000; i++)
		temp += temp;
	auto end_time = chrono::high_resolution_clock::now();
	cout
			<< chrono::duration_cast<chrono::seconds>(end_time - start_time).count()
			<< ":";
	cout
			<< chrono::duration_cast<chrono::microseconds>(
					end_time - start_time).count() << ":";
	cout << "Hello world!" << endl;

	std::array<int, 3> arr1;
	arr1[0] = 5;
	arr1[1] = 8;
	arr1[2] = 3;

	std::array<double, 5> arr2;
	arr2[0] = 0.6;
	arr2[1] = 4;
	arr2[2] = 4.1;
	arr2[3] = 2.1;
	arr2[4] = 23;

	int minimum = min(arr1);
	cout << "min ist:";
	cout << minimum;

	double minimum_d = min(arr2);
	cout << "min ist:";
	cout << minimum_d;

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	//return 0;
}

//some google Test test

double testfunc(int i) {
	return 2 * i;
}

TEST (SimpleTest, doublething) {
	EXPECT_EQ(4, testfunc(2));
	EXPECT_EQ(8, testfunc(4));
}

