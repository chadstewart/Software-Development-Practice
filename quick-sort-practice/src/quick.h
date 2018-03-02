/*
 * quick.h
 *
 *  Created on: Mar 2, 2018
 *      Author: chadstewart
 */

#ifndef QUICK_H_
#define QUICK_H_

class quick
{

private:



public:

	quick();
	~quick();
	void quickSort(int*, int, int);
	int partition(int*, int, int);
	void swap(int*, int*);
	void printArray(int*, int);

};





#endif /* QUICK_H_ */
