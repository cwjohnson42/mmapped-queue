#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(int capacity)
{
	queue = new std::vector<int>(capacity);
	this->capacity = capacity;
	head = 0;
	tail = 0;
}

ArrayQueue::~ArrayQueue()
{
	delete queue;
}

void ArrayQueue::push(int element)
{
	if (tail % capacity != (head % capacity) - 1)
	{
		int index = (tail) % capacity;
		(*queue)[index] = element;
		tail++;
	}
}

int ArrayQueue::pop() 
{
	int ret;
	if (tail != head)
	{
		int index = (head) % capacity;
		int front = (*queue)[index];
		head++;
		ret = front;
	}
	return ret;
}

int ArrayQueue::front()
{
	return (*queue)[head % capacity];
}

int ArrayQueue::back()
{
	return (*queue)[(tail - 1) % capacity];
}