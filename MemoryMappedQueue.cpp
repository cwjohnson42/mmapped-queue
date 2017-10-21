#include "MemoryMappedQueue.h"

MemoryMappedQueue::MemoryMappedQueue(int capacity) {
	float total_size = sizeof(int) * capacity * 2.0f;
	int page_count = ceil(total_size / getpagesize());
	fd = shm_open("mmappedqueue", O_RDWR | O_CREAT, 0600);
	ftruncate(fd, page_count);
	mem_start = (int *) mmap(nullptr, total_size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	head = mem_start;
	tail = mem_start;
	size = total_size / 2;
	mmap(mem_start, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, fd, 0);
	mmap(mem_start + size, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, fd, 0);
}

MemoryMappedQueue::~MemoryMappedQueue()
{
	close(fd);
}

void MemoryMappedQueue::push (int element)
{
	*tail = element;
	tail += sizeof(int);
}

int MemoryMappedQueue::pop()
{
	int ret;
	ret = *head;
	head += sizeof(int);
	if (head == mem_start + size)
	{
		tail -= size;
		head = mem_start;
	}
	return ret;
}

int MemoryMappedQueue::front()
{
	return *head;
}

int MemoryMappedQueue::back()
{
	return *(tail - sizeof(int));
}