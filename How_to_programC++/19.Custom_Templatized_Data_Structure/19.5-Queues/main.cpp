#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> intQueue;

    std::cout << "processing and integer Queue" << std::endl;

    for (int i = 0; i < 3; ++i) {
	intQueue.enqueue(i);
	intQueue.printQueue();
    }

    int dequeueInteger;
    while ( !intQueue.isQueueEmpty() ) {
        intQueue.dequeue(dequeueInteger);
        std::cout << dequeueInteger << " dequeue integer" << std::endl;
        intQueue.printQueue();
    }

    Queue<double> doubleQueue;
    std::cout << "processing and double Queue" << std::endl;

    for (int i = 0; i < 3; ++i) {
        doubleQueue.enqueue(i * 1.1);
        doubleQueue.printQueue();
    }

    double dequeueDouble;
    while ( !doubleQueue.isQueueEmpty() ) {
        doubleQueue.dequeue(dequeueDouble);
        std::cout << dequeueDouble << " dequeue double" << std::endl;
        doubleQueue.printQueue();
    }

    return 0;    
}
