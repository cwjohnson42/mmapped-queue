#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_
#include <iostream>

class CircularQueue
{
    public:
        virtual ~CircularQueue() {};

        virtual void push(int element) = 0;

        virtual int pop() = 0;

        virtual int front() = 0;

        virtual int back() = 0;
};

#endif