#include <iostream>
#include <conio.h>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

template <typename T>
class BaseSort 
{
public:
	BaseSort(unsigned int capacity) {
		arr = new T[capacity];
		this->capacity = capacity;
		srand(time(NULL));
	}
	~BaseSort() {
		delete[] arr;
		capacity = 0;
	}
	void randomize()
	{
		for (unsigned int i = 0; i < capacity; i++)
		{
			arr[i] = rand();
		}
	}

	void print()
	{
		for (unsigned int i = 0; i < capacity; i++)
		{
			printf("%d", arr[i]);
		}
		printf("\n");
	}

	virtual void sort() = 0;

protected:
	T * arr;
	unsigned int capacity;
};
template <typename T>
class SelectSort : public BaseSort<T>
{
public:
	SelectSort(unsigned int capacity) : BaseSort(capacity) {};
	void sort()
	{
		for (unsigned int i = 0; i < capacity - 1; i++)
		{
			unsigned int largestIndex = 0;
			for (unsigned int j = 1; j < capacity - i; j++)
			{
				//scan down the array, find the largest number
				//remember the index of the largest number
				if (arr[j] > arr[largestIndex])
				{
					largestIndex = j;
				}
			}
			//swap here
			T temp = arr[largestIndex];
			arr[largestIndex] = arr[capacity - 1 - i];
			arr[capacity - 1 - i] = temp;
		}
	}
};

template <typename T>
void runSort(BaseSort<T> * sortObj, string name) 
{
	printf("Randomizing for %s\n", name.c_str());
	sortObj->randomize();
	sortObj->print();
	printf("Sorting\n");
	sortObj->sort();
	sortObj->print();
	printf("Done\n");
}

int main()
{
	BaseSort<unsigned int>* sortObj = new SelectSort<unsigned int>(100);
	runSort(sortObj, "Select");
	
	_getch();
	return 0;
}

//Participation code 10/14 342240