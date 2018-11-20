#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

const int MAX = 20;

struct File
{
	enum class Type
	{
		File = 0,
		Directory
	};

	std::string name;
	Type type;
	size_t size;
	time_t creationTime;
	time_t modificationTime;
};

ostream& operator<<(ostream& os, const File& fileInfo)
{
	switch (fileInfo.type)
	{
	case File::Type::Directory: os << "Folder \""; break;
	case File::Type::File: os << "File \""; break;
	}
	os << fileInfo.name << "\" (size = " << fileInfo.size % 1000 << " KB)\n";
	os << "\tCreation time: " << fileInfo.creationTime << "\n";
	return os << "\tMoodification time: " << fileInfo.modificationTime << "\n";
}

class Array
{
public:

	int arr[MAX];
	Array();

};

Array::Array()
{
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 30;
	}
}

class List : public Array
{
public:
	void InsertionSort();
	void QuickSort(int left, int right);
	void MergeSort(int s, int e);
	void merge(int s, int e);
	void display();

};


void List::InsertionSort()
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

void List::QuickSort(int left, int right)
{
	int *a = arr;
	int i = left, j = right;
	bool end = false;
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
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


void List::merge(int s, int e)
{
	int *a = arr;
	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[100];

	while (i <= mid && j <= e) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= e) {
		temp[k++] = arr[j++];
	}

	//We need to copy all element to original arrays
	for (int i = s; i <= e; i++) {
		arr[i] = temp[i];
	}
}

void List::MergeSort(int s, int e)
{
	int *a = arr;
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

void List::display()
{
	for (int i = 0; i < MAX; i++) cout << arr[i] << "\t";
	cout << endl;
	cout << endl;

}

void main()
{
	List arr;
	arr.display();
	arr.InsertionSort();
	arr.display();
	List arr2;
	arr2.QuickSort(0, MAX - 1);
	arr2.display();
	List arr3;
	arr3.MergeSort(0, MAX - 1);
	arr3.display();

	vector<File> files;
	files.emplace_back(File{
		"readme.txt",
		File::Type::File,
		2 * 1024 * 1024,
		time(0) - 2 * 24 * 3600, // 2 days ago
		time(0)
		});

	files.emplace_back(File{
		"New Folder",
		File::Type::Directory,
		2 * 1024 * 1024,
		time(0) - 2 * 24 * 3600, // 2 days ago
		time(0)
		});

	for (auto& file : files)
		cout << file << "\n_____________\n";

	system("pause");
	return;
}