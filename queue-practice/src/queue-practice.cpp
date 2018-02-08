//============================================================================
// Name        : queue-practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "queue.h"

using namespace std;

int main() {
	queue queue;

		queue.push("Bev");
		cout << "\nNext command.\n" << endl;
		queue.push("Alston");
		cout << "\nNext command.\n" << endl;
		queue.push("Kai");
		cout << "\nNext command.\n" << endl;
		queue.pop();
		cout << "\nNext command.\n" << endl;
		queue.pop();

		return 0;
}
