//============================================================================
// Name        : OptimizePrograms.cpp
// Author      : nlz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Headers/OptimizePrograms.h"

using namespace std;

//int main(int argc, char **argv) {
	int main() {

	std::shared_ptr<array<double, 64>> testArray(new array<double, 64>);
	initArray(*testArray);
	insertionSortPrefetch(*testArray);
/**
	::testing::InitGoogleTest(&argc, argv);
	int testResult = RUN_ALL_TESTS();
	if (testResult) {
		return 1;
	}


	for (int i = 0; i < 3; i++) {
		cout << ALGO[i] << " Typ Double" << endl;
		recTime<double, SIZEsmall> testDouble;
		testDouble.meassureTimeSort(i);
		cout << endl;
	}
*/

	return 0;
}

TEST(ArrayIinitialisations, all) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArrayAscending(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
	std::shared_ptr<array<int, 100>> testArray2(new array<int, 100>);
	initArrayDescending(*testArray2);
	EXPECT_EQ(1, checkArrayDesc(*testArray2));
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
TEST (TestSelectionSort, normalChars) {
	array<string,11> arrS;
	arrS ={{"a","b","b","b","c","d","f","u","a","g","z"}};
	selectionSortNormal(arrS);
	EXPECT_EQ(1, checkArray(arrS));
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
TEST (TestSelectionSort, 2LoopsDoubledoppelt) {
	std::shared_ptr<array<double, 5>> testArray(new array<double, 5>);
	(*testArray)[0] = 0.0;
	(*testArray)[1] = 0.2;
	(*testArray)[2] = 0.2;
	(*testArray)[3] = 0.8;
	(*testArray)[4] = 0.4;
	selectionSortmin2loops(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
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

TEST (TestInsertionSort, Normal) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray);
	insertionSortNormal(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
}

