c = g++
OBJS = ArrayQueue.o LinkedQueue.o MemoryMappedQueue.o

time : $(OBJS) driver.o 
	$(c) -o dmmq $^ -lrt
test : $(OBJS) test.o
	$(c) -o dmmq $^ -lrt

ArrayQueue.o : CircularQueue.h ArrayQueue.h ArrayQueue.cpp
	$(c) -c -g $^ -lrt
LinkedQueue.o : CircularQueue.h LinkedQueue.h LinkedQueue.cpp
	$(c) -c -g $^ -lrt
MemoryMappedQueue.o : CircularQueue.h MemoryMappedQueue.h MemoryMappedQueue.cpp
	$(c) -c -g $^ -lrt
driver.o : driver.cpp CircularQueue.h ArrayQueue.h LinkedQueue.h MemoryMappedQueue.h
	$(c) -c -g $^ -lrt
test.o : test.cpp CircularQueue.h ArrayQueue.h LinkedQueue.h MemoryMappedQueue.h
	$(c) -c -g $^ -lrt

clean :
	rm -rf ./*.o
	rm -rf ./*.gch
