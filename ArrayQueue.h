#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

#include <vector>
#include <iostream>
#include "CircularQueue.h"

class ArrayQueue : public CircularQueue
{
	private:
		std::vector<int> *queue;
		int tail;
		int head;
		int capacity;

	public:
		ArrayQueue(int capacity);

		~ArrayQueue();

		void push(int element);
		
		int pop();

		int front();

		int back();
};

#endif