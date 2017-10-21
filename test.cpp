#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "MemoryMappedQueue.h"

#include <queue>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int main(int argc, char * argv[])
{
	srand(time(NULL));
	std::queue<int> values;
	LinkedQueue *l_q = new LinkedQueue(80);
	ArrayQueue *a_q = new ArrayQueue(80);
	MemoryMappedQueue *m_q = new MemoryMappedQueue(80);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int value = rand();
			values.push(value);
			l_q->push(value);
			a_q->push(value);
			m_q->push(value);
			if (values.back() != l_q->back())
			{
				std::cout << "LinkedQueue returned " << l_q->back() << " as back. Actual value is: " << values.back() << "\n";
			}
			if (values.back() != a_q->back())
			{
				std::cout << "ArrayQueue returned " << a_q->back() << " as back. Actual value is: " << values.back() << "\n";
			}
			if (values.back() != m_q->back())
			{
				std::cout << "MemoryMappedQueue returned " << m_q->back() << " as back. Actual value is: " << values.back() << "\n";
			}
		}
		for (int j = 0; j < 20; j++)
		{
			int value = values.front();
			values.pop();
			int l_value = l_q->pop();
			int a_value = a_q->pop();
			int m_value = m_q->pop();
			if (value != l_value)
			{
				std::cout << "LinkedQueue returned " << l_value << " from pop(). Actual value is: " << value << "\n";
			}
			if (value != a_value)
			{
				std::cout << "ArrayQueue returned " << a_value << " from pop(). Actual value is: " << value << "\n";
			}
			if (value != m_value)
			{
				std::cout << "MemoryMappedQueue returned " << m_value << " from pop(). Actual value is: " << value << "\n";
			}
		}
	}
	delete a_q;
	delete l_q;
	delete m_q;
}