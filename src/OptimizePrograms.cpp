//============================================================================
// Name        : OptimizePrograms.cpp
// Author      : nlz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Headers/OptimizePrograms.h"

using namespace std;

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	runAllTests();
	//
	/**
	array<int, 8> array;
	array={7,6,4,2,4,3,6,3};
	mergeSort(array);

	for (int i = 0; i < 3; i++) {
		cout << ALGO[i] << " Typ Double" << endl;
		recTime<double, SIZEsmall> testDouble;
		testDouble.meassureTimeSort(i);
		cout << endl;
	}

	for (int i = 3; i < 5; i++) {
		cout << ALGO[i] << " Typ Double" << endl;
		recTime<double, SIZEbig> testDouble;
		testDouble.meassureTimeSort(i);
		cout << endl;
	}
	*/

	return 0;
}

