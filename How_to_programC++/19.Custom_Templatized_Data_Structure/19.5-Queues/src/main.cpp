#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> intQueue;

    std::cout << "processing and integer Queue" << std::endl;

    for (int i = 0; i < 3; ++i) {
        intQueue.enqueue(i);
        intQueue.print();
    }

    int dequeueInteger;
    while ( !intQueue.empty() ) {
        intQueue.dequeue(dequeueInteger);
        std::cout << dequeueInteger << " dequeue integer" << std::endl;
        intQueue.print();
    }

    Queue<double> doubleQueue;
    std::cout << "processing and double Queue" << std::endl;

    for (int i = 0; i < 3; ++i) {
        doubleQueue.enqueue(i * 1.1);
        doubleQueue.print();
    }

    double dequeueDouble;
    while ( !doubleQueue.empty() ) {
        doubleQueue.dequeue(dequeueDouble);
        std::cout << dequeueDouble << " dequeue double" << std::endl;
        doubleQueue.print();
    }

    return 0;    
}
