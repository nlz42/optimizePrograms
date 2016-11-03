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



	//meassureTime<int, 20>(minNormal);
	std::array<int, 6400> array = initArray(array, 1, 9);

	meassureTimeSort(selectionSortNormal,array);

//	cout<<"test2"<<endl;
//	for (size_t i=0;i<array.size();i++){
//		cout<<array[i];
//	}
//	cout<<"test2"<<endl;

	meassureTimeSort(selectionSortmin2loops,array);

	meassureTimeSort(selectionSortPrefetch,array);

	//meassureTimeSort<int, 15>(selectionSortmin2loops);

	//::testing::InitGoogleTest(&argc, argv);
	//int testResult = RUN_ALL_TESTS();
	//if(testResult != 0){
	//	return testResult;
	//	}

	return 0;
}

TEST (TestSchleifen, normal) {
	//EXPECT_EQ(3, minNormal());
}


TEST (TestSchleifen, ZweiSchleifen) {
	//EXPECT_EQ(3, minTwoLoops(initArrays64()));
}

