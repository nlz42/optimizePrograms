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
std::array<int,12800> resultArr;

int main(int argc, char **argv) {

	//meassureTime<int, 20>(minNormal);
	std::array<int, 12800> array = initArray(array, 1, 5);

	flushCache();

	meassureTimeSort(selectionSortNormal, array);

	flushCache();

	resultArr = meassureTimeSort(selectionSortmin2loops, array);
	flushCache();

	meassureTimeSort(selectionSortPrefetch, array);


	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//TODO How secure flush L1 Cache?
void flushCache() {
	std::array<int, 2048> array = initArray(array, 5, 1);
}

int checkArray(std::array<int,12800> array){
	int result = 1; // true
	for(size_t i=0;i<array.size()-1;i++){
		if(!(array[i]<=array[i+1])){
			result=0; // false
		}
	}
return result;
}

TEST (TestSchleifen, normal) {
	EXPECT_EQ(1, checkArray(resultArr));
}

TEST (TestSchleifen, ZweiSchleifen) {
	//EXPECT_EQ(3, minTwoLoops(initArrays64()));
}

