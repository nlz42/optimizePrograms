/*
 * TestArrays.cpp
 *
 *  Created on: 27.10.2016
 *      Author: nlz
 */

#include"Headers/TestArrays.h"

using namespace std;

void flushCache() {
	std::shared_ptr<std::array<int, SIZEbig>> flushArray(
			new std::array<int, SIZEbig>);
	initArray(*flushArray);
	for (size_t i = 0; i < SIZEbig; i++) {
		(*flushArray)[i] = (*flushArray)[i] + 1;
	}
}

void runAllTests() {
	int testResult = RUN_ALL_TESTS();
	if (testResult == 1) {
		cout << "fail" << endl;

	}
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
	array<string, 11> arrS;
	arrS = { {"a","b","b","b","c","d","f","u","a","g","z"}};
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

TEST (TestInsertionSort, normal) {
	std::shared_ptr<array<int, 100>> testArray(new array<int, 100>);
	initArray(*testArray);
	insertionSortNormal(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
	//Test with double
	std::shared_ptr<array<double, 100>> testArrayD(new array<double, 100>);
	initArray(*testArrayD);
	insertionSortNormal(*testArrayD);
	EXPECT_EQ(1, checkArray(*testArrayD));
}

TEST (TestInsertionSort, Prefetch) {
	std::shared_ptr<array<int, 128>> testArray(new array<int, 128>);
	initArray(*testArray);
	insertionSortPrefetch(*testArray);
	EXPECT_EQ(1, checkArray(*testArray));
	//Test with double
	std::shared_ptr<array<double, 100>> testArrayD(new array<double, 100>);
	initArray(*testArrayD);
	insertionSortPrefetch(*testArrayD);
	EXPECT_EQ(1, checkArray(*testArrayD));
}


TEST (TestInsertionSort, littleArraysPrefetch) {
	array<int, 11> arrI;
	arrI = { {1,6,3,56,8,3,2,1,0,3,5}};
	insertionSortPrefetch(arrI);
	EXPECT_EQ(1, checkArray(arrI));

	array<int, 5> arrIl;
	arrIl = { {3,6,1,3,9}};
	insertionSortPrefetch(arrIl);
	EXPECT_EQ(1, checkArray(arrIl));

	array<string, 11> arrS;
	arrS = { {"a","b","b","b","c","d","f","u","a","g","z"}};
	insertionSortPrefetch(arrS);
	EXPECT_EQ(1, checkArray(arrS));
}

TEST (TestButoomUp, normal) {
	//Test with double
	std::shared_ptr<array<double, 128>> testArrayD(new array<double, 128>);
	initArray(*testArrayD);
	mergeSort(*testArrayD);
	EXPECT_EQ(1, checkArray(*testArrayD));

	std::shared_ptr<array<double, 8388608>> testArrayBIG(new array<double, 8388608>);
	initArray(*testArrayBIG);
	mergeSort(*testArrayBIG);
	EXPECT_EQ(1, checkArray(*testArrayD));

}

