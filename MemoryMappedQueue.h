#include "CircularQueue.h"
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

class MemoryMappedQueue : public CircularQueue
{
	private:
		int size;
		int fd;
		int *mem_start;
		int *head;
		int *tail;

	public:
		MemoryMappedQueue(int capacity);

		~MemoryMappedQueue();

		void push (int element);

		int pop();

		int front();

		int back();
};
