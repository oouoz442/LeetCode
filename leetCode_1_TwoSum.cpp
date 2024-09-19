#include <iostream>
#include <random>

const int arraySize = 5;

void static fillArrayRandomNumbers(int* ptrArray, int A, int B);
void static outputArray(int* ptrArray);

// Given an array of integers array and an integer target, return indices of the two numbers such that they add up to target.
int main()
{
	int array[arraySize] = {};
	int a = 2, b = 10;
	int target = 9;

	fillArrayRandomNumbers(array, a, b);
	outputArray(array);

	for (int i = 0; i < arraySize - 1; i++) {
		for (int j = i + 1; j < arraySize; j++) {
			std::cout << array[i] << array[j] << std::endl;
			if (array[i] + array[j] == target) {
				std::cout << "We found it. " << array[i] << " + " << array[j] << " = " << target << std::endl;
			}
		}
	}

	return 0;
	// return {i, j};
}


void static fillArrayRandomNumbers(int* ptrArray, int A, int B) {
	srand(time(0));
	for (int i = 0; i < arraySize; i++)
		*(ptrArray + i) = rand() % (B - A + 1) + A;
}

void static outputArray(int* ptrArray) {
	for (int i = 0; i < arraySize; i++) {
		std::cout << *(ptrArray + i) << "\t";
	}
	std::cout << std::endl;
}
