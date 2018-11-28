#pragma once
#include "Array.h"

class List : public Array /*This class is inherited from the Array class. 
						  The class is responsible for the sorting function, and the output of the arrays.*/
{
public:

	void InsertionSort();
	void QuickSort(int left, int right);
	void MergeSort(int s, int e);
	void merge(int s, int e);
	void display();
	void display_2();
	void display_3();

};
