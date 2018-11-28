#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <time.h>
#include <vector>
#include "List.h"
#include "Array.h"
#include "File.h"
using namespace std;


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

void main()
{
	List arr;
	cout << "Array for Insertion sort" << endl;
	arr.display();  //outputs arrays of given types
	arr.InsertionSort();  //calls the function of the corresponding sort of List class
	cout << endl;
	cout << "InsertionSort" << endl;
	arr.display();  //displays sorted arrays
	cout << "\n_____________\n";
	

	List arr2;
	cout << "Array for Quick Sort" << endl;
	arr2.display_2(); 
	arr2.QuickSort(0, MAX - 1);
	cout << endl;
	cout << "Quick Sort" << endl;
	arr2.display_2();
	cout << "\n_____________\n";


	List arr3;
	cout << "Array for Merge Sort" << endl;
	arr3.display_3();
	arr3.MergeSort(0, MAX - 1);
	cout << endl;
	cout << "Merge Sort" << endl;
	arr3.display_3();
	cout << "\n_____________\n";

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