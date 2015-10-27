#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

int * arr;
const int ARRSIZE = 1000000;
unsigned int sixesCount;
int numThreads;
mutex myMutex; //Always global so threads share it

void getCounts(int threadID) 
{
	unsigned int localCount = 0;
	//threadID 0 should get to <ARRSIZE /2
	//threadID 1 should get ARRSIZE /2 to ARRSIZE
	int beginIndex = (ARRSIZE * threadID) / numThreads;
	int endIndex = (ARRSIZE * (threadID + 1)) / numThreads;
	//printf("I'm in thread %d and beginIndex is %d and endIndex is %d\n", threadID, beginIndex, endIndex);
	for (unsigned int i = beginIndex; i < endIndex; i++)
	{
		if (arr[i] == 6)
		{
			localCount++;
		}
	}
	//printf("Thread %d counted %d many sixes\n", threadID, localCount);
	//only one thread at a time can run this - Mutexes solve this problem
	myMutex.lock();
	sixesCount = sixesCount + localCount;
	myMutex.unlock();
}

void generateRands(int threadID) 
{
	int beginIndex = (ARRSIZE * threadID) / numThreads;
	int endIndex = (ARRSIZE * (threadID + 1)) / numThreads;
	//printf("I'm in thread %d and beginIndex is %d and endIndex is %d\n", threadID, beginIndex, endIndex);
	for (unsigned int i = beginIndex; i < endIndex; i++)
	{
		arr[i] = rand() % 10;
	}
}

int main()
{
	sixesCount = 0;
	arr = new int[ARRSIZE];
	srand(time(0));
	numThreads = 4;

	thread *threads = new thread[numThreads];
	for (int i = 0; i < numThreads; i++)
	{
		threads[i] = thread(generateRands,i);
	}
	for (int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}
	/*for (int i = 0; i < ARRSIZE; i++)
	{
		arr[i] = rand() % 10;
	}*/

	for (int i = 0; i < numThreads; i++)
	{
		threads[i] = thread(getCounts, i);
	}
	for (int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}
	// Launch function in multithreads
	/*threads[0] = thread(getCounts, 0);
	threads[1] = thread(getCounts, 1);*/
	//wait until threads are done - synchronization point
	/*threads[0].join();
	threads[1].join();*/

	//getCounts();

	printf("The count of sixes is %d\n", sixesCount);

	_getch();
	return 0;
}
//participation code 10/26 050293