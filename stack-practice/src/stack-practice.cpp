//============================================================================
// Name        : stack-practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	stack stack;

	stack.push("Bev");
	cout << "\nNext command.\n" << endl;
	stack.push("Alston");
	cout << "\nNext command.\n" << endl;
	stack.push("Kai");
	cout << "\nNext command.\n" << endl;
	stack.pop();
	cout << "\nNext command.\n" << endl;
	stack.pop();

	return 0;
}
