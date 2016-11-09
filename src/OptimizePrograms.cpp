//============================================================================
// Name        : OptimizePrograms.cpp
// Author      : nlz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Headers/OptimizePrograms.h"

using namespace std;

//TODO Type und Size als Constanten festlegen.

int main(int argc, char **argv) {
	std::shared_ptr<array<int, SIZEsmall>> array1(new array<int, SIZEsmall>);

	//run first
	initArray(*array1,1,100);
	ALGO algo;
	algo = sortSelectionSortNormal;
	recTime<int,SIZEsmall> test;
	test.meassureTimeSort(selectionSortNormal, *array1, algo);


	//meassureTimeSortFunc(selectionSortNormal, *array1);

	// end first
/**
	//run second
	initArray(*array1,1,100);
	minTwoLoopsPrefetch(*array1,0);
	flushCache();
	meassureTimeSort(selectionSortmin2loops, *array1);
	// end first

	//run third
	initArray(*array1,1,100);
	minTwoLoopsPrefetch(*array1,0);
	flushCache();
	meassureTimeSort(selectionSortPrefetch, *array1);
	// end first

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	*/
	return 0;

}




TEST (TestSelectionSort, normal) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray,1,20);
	selectionSortNormal(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
}


TEST (TestSelectionSort, 2Loops) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray,1,20);
	selectionSortmin2loops(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
}
TEST (TestSelectionSort, 2LoopsPrefetch) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray,1,20);
	selectionSortPrefetch(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
}

