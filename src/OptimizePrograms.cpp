//============================================================================
// Name        : OptimizePrograms.cpp
// Author      : nlz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <chrono>
#include "ExerciseAB.cpp"
using namespace std;

int main() {
	auto i = 0;
	auto y = 2;
	cout << "!!!Hello Worl!!!" << endl; // prints !!!Hello World!!!
	i = i + y;
	cout << i << endl;

	// testing chrono library
	auto start_time = chrono::high_resolution_clock::now();
	int age = 0;
	cout << "Was eingeben:";
	cin >> age;
	cout << age << endl;
	int temp;
	for (int i = 0; i < 242000000; i++)
		temp += temp;
	auto end_time = chrono::high_resolution_clock::now();
	cout
			<< chrono::duration_cast<chrono::seconds>(end_time - start_time).count()
			<< ":";
	cout
			<< chrono::duration_cast<chrono::microseconds>(
					end_time - start_time).count() << ":";
	cout << "Hello world!" << endl;

	std::array<int, 3> arr1;
	arr1[0]=5;
	arr1[1]=8;
	arr1[2]=3;

	sortieren(arr1);

	return 0;
}
