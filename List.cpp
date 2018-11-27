#include "List.h"
#include <iostream>
using namespace std;

void List::InsertionSort() //Functiom of Insertion Sort. Sort array "arr[MAX]", array of type "int"
{
	int i, key, j;
	for (i = 1; i < MAX; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void List::QuickSort(int left, int right) //Functiom of Quick Sort. Input - array of type "long long"
{
	long long *a = arr2;
	int i = left, j = right;
	bool end = false;
	int tmp;
	int pivot = arr2[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr2[i] < pivot)
			i++;
		while (arr2[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr2[i];
			arr2[i] = arr2[j];
			arr2[j] = tmp;
			i++;
			j--;
		}
	}
	/* recursion */
	if (left < j) {
		QuickSort(left, j);
	}
	if (i < right) {
		QuickSort(i, right);
	}

}


void List::merge(int s, int e) //subsidiary function for Merge Sort
{
	double *a = arr3;
	int mid = (s + e) / 2; //defines a central element

	int i = s;
	int j = mid + 1;
	int k = s;

	double temp[100];

	while (i <= mid && j <= e) {
		if (arr3[i] < arr3[j]) {
			temp[k++] = arr3[i++];
		}
		else {
			temp[k++] = arr3[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr3[i++];
	}
	while (j <= e) {
		temp[k++] = arr3[j++];
	}

	//We need to copy all element to original arrays
	for (int i = s; i <= e; i++) {
		arr3[i] = temp[i];
	}
}

void List::MergeSort(int s, int e) //Functiom of Merge Sort. Input - array of type "double"
{
	double *a = arr3;
	//Base case - 1 or 0 elements
	if (s >= e) {
		return;
	}

	//Follow 3 steps
	//1. Divide
	int mid = (s + e) / 2;

	//Recursively the arrays - s,mid and mid+1,e
	MergeSort(s, mid);
	MergeSort(mid + 1, e);

	//Merge the two parts
	merge(s, e);

}

void List::display() //displays various types of arrays
{
	for (int j = 0; j < MAX; j++) cout << arr[j] << "\t";
	
}
void List::display_2()
{
	for (int j = 0; j < MAX; j++) cout << arr2[j] << "\t";
	
}
void List::display_3()
{
	for (int j = 0; j < MAX; j++) cout << arr3[j] << "\t";
}