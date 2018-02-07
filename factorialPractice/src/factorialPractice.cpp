//============================================================================
// Name        : factorialPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int FirstFactorial(int num) {

	int numCalc = num;
	while (num != 1) {
		numCalc *= (num - 1);
		num--;
	}
	return numCalc;

}

int main() {

	// keep this function call here
	cout << FirstFactorial(8);
	return 0;

}
