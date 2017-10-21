#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_

#include "CircularQueue.h"
#include <iostream>

class LinkedQueue : public CircularQueue
{
	private:
		class Node
		{
			private:
				int item;
				Node *prev;
				Node *next;

			public:
				Node(int item, Node *prev);

				~Node();

				int getItem();

				Node *getPrev();

				Node *getNext();

				void setPrev(Node *node);

				void setNext(Node *node);
		};
	private:
		Node *head;
		Node *tail;
		int capacity;

	public:
		LinkedQueue(int capacity);

		~LinkedQueue();

		void push(int element);

		int pop();

		int front();

		int back();
};

#endif