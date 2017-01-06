//============================================================================
// Name        : OptimizePrograms.cpp
// Author      : nlz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Headers/OptimizePrograms.h"

using namespace std;

//int main(int argc, char** argv){
int main() {
//	::testing::InitGoogleTest(&argc, argv);
//	runAllTests();

//	for (int i = 0; i < 5; i++) {
//		cout << ALGO[i] << " Typ Double" << endl;
//		recTime<double, SIZEsmall> testDouble;
//		testDouble.meassureTimeSort(i);
//		cout << endl;
//	}

	for (int i = 5; i < 8; i++) {
		cout << ALGO[i] << " Typ Double" << endl;
		recTime<double, SIZEbig> testDouble;
		testDouble.meassureTimeSort(i);
		cout << endl;
	}
	return 0;
}

