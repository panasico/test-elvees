#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <ctime>
using namespace std;

int function(int size, int * arr) {
	int res = 0;

	for (int i = 0; i < size; i++)
		res ^= arr[i];

	return res;
}

int main(int argc, char* argv[])
{
	int size = 0; //size of array
	int flag = 0; //flag input arguments
	int* arr; 
	
	//rand-mode
	if (argc == 3 && (strcmp(argv[1],"rand") == 0 || strcmp(argv[2], "rand") == 0)) {
		if (strcmp(argv[1], "rand") == 0)
			size = atoi(argv[2]);
		else
			size = atoi(argv[1]);
		if (size % 2 == 0) {
			cout << "error! program works with an odd array size!" << endl;
			return -2;
		}

		flag = 1;
		}
	//cin-mode
	if (argc == 1)
		flag = 2;

	switch (flag)
	{
		//elements of array from argv
		case 0: {
			size = argc - 1;

			arr = new int[size];

			for (int i = 1; i < argc; i++) {
				try {
					arr[i - 1] = atoi(argv[i]);
				}
				catch (...) {
					cout << "error! program works with integer argument!" << endl;
					return -1;
				}
			}
			cout << "Result : " << function(size, arr) << endl;
			break;
		}

		//cin-mode
		case 2: {
			cout << "Enter size of array : ";
			try {
				cin >> size;
			}
			catch (...) {
				cout << "error! program works with integer argument!" << endl;
				return -1;
			}
		
			arr = new int[size];

			cout << "Enter elements (through enter) : " << endl;
			for (int i = 0; i < size; i++) {
				cout << "1 element = ";
				cin >> arr[i];
			}

			cout << "Result : " << function(size, arr) << endl;
			break;
		}

		//rand-mode
		case 1: {
			srand(time(0));
			arr = new int[size]();
			int position = rand() % (size - 1); //position of searching element

			for (int i = 0; i < size; i++) {
				if (i == position) {
					if (i == size - 1 || i % 2 == 0) {
						arr[i] = rand() + 1;
						continue;
					}
					arr[i + 1] = arr[i];
					arr[i] = rand() + 1;
					i++;
					continue;
				}
				if (arr[i] != 0 && i > 0)
					continue;
				arr[i] = rand() + 1;
				arr[i + 1] = arr[i];
			}
			
			//print generated array
			cout << "Generated array :" << endl;
			for (int i = 0; i < size; i++) {
				cout << arr[i] << " ";
				if (i % 6 == 0 && i)
					cout << endl;
			}

			cout << endl << endl << "Result : " << function(size, arr) << endl;
			break;
		}
	}
	delete[] arr;
	return 0;
}