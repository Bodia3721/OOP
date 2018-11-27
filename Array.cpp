#include "Array.h"
#include <iostream>


Array::Array() //Fills arrays with different types of data
{
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 30;
	}

	for (int j = 0; j < MAX; j++)
	{
		arr2[j] = rand() /30;
	}

	for (int j = 0; j < MAX; j++)
	{
		arr3[j] = rand() ;
		arr3[j] = arr3[j] / 30;
	}
}