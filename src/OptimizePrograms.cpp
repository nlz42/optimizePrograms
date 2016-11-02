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

