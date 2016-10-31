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

	std::array<double,128> a1 = initArray(a1, 0, 50);
	std::cout << "Values: \n" << a1[1]<<" , "<<a1[15]<<" , "<<a1[127];

	std::array<int,128> a2 = initArray(a2, 0, 500);
	std::cout << "Values: \n" << a2[1]<<" , "<<a2[15]<<" , "<<a2[127] << "\n";

	meassureTime<int, 128>(minNormal);

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST (TestSchleifen, normal) {
	//EXPECT_EQ(3, minNormal());
}


TEST (TestSchleifen, ZweiSchleifen) {
	//EXPECT_EQ(3, minTwoLoops(initArrays64()));
}

