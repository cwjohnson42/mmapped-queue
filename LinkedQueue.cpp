#include "LinkedQueue.h"

LinkedQueue::LinkedQueue(int capacity)
{
	this->capacity = capacity;
	head = nullptr;
	tail = nullptr;
}

LinkedQueue::~LinkedQueue()
{
	while (head != tail)
	{
		Node *prev_head = head;
		head = head->getNext();
		delete prev_head;
	}
	delete head;
	delete tail;
}

void LinkedQueue::push(int element)
{
	Node *cur_tail = tail;
	tail = new Node(element, cur_tail);
	if (head == nullptr)
	{
		head = tail;
		return;
	}
	cur_tail->setNext(tail);
}

int LinkedQueue::pop()
{
	int element = head->getItem();
	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return element;
	}
	Node *cur_head = head;
	head = head->getNext();
	delete cur_head;
	return element;
}

int LinkedQueue::front()
{
	return head->getItem();
}

int LinkedQueue::back()
{
	return tail->getItem();
}

LinkedQueue::Node::Node(int item, Node *prev)
{
	this->item = item;
	this->prev = prev;
}

LinkedQueue::Node::~Node()
{
	if (prev != nullptr)
	{
		prev->setNext(nullptr);
	}
	if (next != nullptr)
	{
		next->setPrev(nullptr);
	}
}

int LinkedQueue::Node::getItem()
{
	return item;
}

LinkedQueue::Node *LinkedQueue::Node::getPrev()
{
	return prev;
}

LinkedQueue::Node *LinkedQueue::Node::getNext()
{
	return next;
}

void LinkedQueue::Node::setPrev(Node *node)
{
	prev = node;
}

void LinkedQueue::Node::setNext(Node *node)
{
	next = node;
}