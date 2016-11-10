//============================================================================
// Name        : OptimizePrograms.cpp
// Author      : nlz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Headers/OptimizePrograms.h"

using namespace std;

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	int testResult = RUN_ALL_TESTS();
	if(testResult){
		return 1;
	}

	for (int i=0 ; i<3;i++){
		cout<<ALGO[i]<<" Integer"<<endl;
		recTime<int,SIZEsmall> testInt;
		testInt.meassureTimeSort(i);
		cout<<endl;
	}
	for(int i=0; i<3;i++){
		cout<<ALGO[i]<<" Typ Double"<<endl;
		recTime<double,SIZEsmall> testDouble;
		testDouble.meassureTimeSort(i);
		cout<<endl;
	}

	return 0;
}




TEST (TestSelectionSort, normal) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray);
	selectionSortNormal(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
	//Test with double
	std::shared_ptr<array<double, 100>> testArrayD(new array<double, 100>);
	initArray(*testArrayD);
	selectionSortNormal(*testArrayD);
	EXPECT_EQ(1, checkArray(*testArrayD));
}


TEST (TestSelectionSort, 2Loops) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray);
	selectionSortmin2loops(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
	//Test with double
	std::shared_ptr<array<double, 100>> testArrayD(new array<double, 100>);
	initArray(*testArrayD);
	selectionSortmin2loops(*testArrayD);
	EXPECT_EQ(1, checkArray(*testArrayD));
}
TEST (TestSelectionSort, 2LoopsPrefetch) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray);
	selectionSortPrefetch(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
	//Test with double
	std::shared_ptr<array<double, 100>> testArrayD(new array<double, 100>);
	initArray(*testArrayD);
	selectionSortPrefetch(*testArrayD);
	EXPECT_EQ(1, checkArray(*testArrayD));
}

