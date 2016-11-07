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
std::array<int, 12800> resultArr;

int main(int argc, char **argv) {

	//meassureTime<int, 20>(minNormal);
	std::shared_ptr<array<int, SIZEsmall>> foo(new array<int, SIZEsmall>);

	initArray(*foo,1,100);
	cout<<"firstmin:= "<<minTwoLoopsPrefetch(*foo,0)<<endl;

	meassureTimeSort(selectionSortNormal, *foo);
	flushCache();
	cout<<"Value 0: "<<(*foo)[0]<<endl;
	initArray(*foo,1,100);
	cout<<"New Value 0: "<<(*foo)[0]<<endl;
	meassureTimeSort(selectionSortmin2loops, *foo);
	cout<<"Value 0: "<<(*foo)[0]<<endl;
	initArray(*foo,1,100);
	cout<<"New Value 0: "<<(*foo)[0]<<endl;
	meassureTimeSort(selectionSortPrefetch, *foo);
	cout<<"Value 0: "<<(*foo)[0]<<"Das wars"<<endl;

	for(size_t i=0;i<10;i++){
		cout<<(*foo)[i]<<endl;
	}

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}

//TODO How secure flush L1 Cache?
void flushCache() {
	std::shared_ptr<array<int, SIZEbig>> flushArray(new array<int, SIZEbig>);
	initArray(*flushArray,MIN,MAX);
	minNormal(*flushArray,0);
	cout<<"flush cash sucess"<<endl;
}

int checkArray(std::array<int, 12800> array) {
	int result = 1; // true
	for (size_t i = 0; i < array.size() - 1; i++) {
		if (!(array[i] <= array[i + 1])) {
			result = 0; // false
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

