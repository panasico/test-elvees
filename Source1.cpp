#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <ctime>
using namespace std;

int function(int N) {
	if (N == 0)
		return 0;
	if (N == 1)
		return 1;

	if (N % 2 == 0)
		return function(N / 2);
	else
		return function(N - 1) + function(N / 2 + 1);
}

int main(int argc, char* argv[])
{
	int N;

	if (argc == 2) {
		//if rand-mode
		if (strcmp(argv[1], "rand") == 0) {
			srand(time(0));
			N = rand();
			cout << "Result : " << function(N);
			return 0;
		}
		//if N from input arguments
		try {
			N = atoi(argv[1]);
		}
		catch (...) {
			cout << "error! program works with integer argument!" << endl;
			return -1;
		}


		if (N >= 0) {
			cout << "Result : " << function(N);
			return 0;
		}
		else {
			cout << "error! program works with integer argument!" << endl;
			return -1;
		}
	}

	//cin-mode
	cout << "Enter N : ";
	try {
		cin >> N;
	}
	catch (...) {
		cout << "error! program works with integer argument!" << endl;
		return -1;
	}

	cout << "Result : " << function(N);
	return 0;
}