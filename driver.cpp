#include "CircularQueue.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "MemoryMappedQueue.h"
#include <stdio.h>
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

double When();

int main(int argc, char* argv[])
{
	int capacity = argc > 1 ? atoi(argv[1]) : 300;
	CircularQueue * queue;
	int iterations = argc > 2 ? atoi(argv[2]) : 200;
	char q_type = argc > 3 ? argv[3][0] : 'a';

	switch (q_type)
	{
		case 'a':
			queue = new ArrayQueue(capacity);
			break;
		case 'l':
			queue = new LinkedQueue(capacity);
			break;
		case 'm':
			queue = new MemoryMappedQueue(capacity);
			break;
	}
	int f = 0;
	double start = When();
	for (int i = 0; i < iterations; i++)
	{
		for (int j = 0; j < capacity / 2; j++)
		{
			queue->push(f);
		}
		for (int j = 0; j < capacity / 2; j++)
		{
			queue->pop();
		}
	}
	std::cout << "Elapsed time: " << When() - start << "\n";
	delete queue;
	return 0;
}

double When()
{

    struct timeval tp;

    gettimeofday(&tp, nullptr);

    return ((double) tp.tv_sec + (double) tp.tv_usec * 1e-6);

}