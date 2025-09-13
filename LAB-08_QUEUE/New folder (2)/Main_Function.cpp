#include "Queue.h"
#include "Queue_Array.h"
#include "Queue_List.h"
#ifdef TEST
# include <cassert>
#else
# include <iostream>
#endif
#ifdef TEST
// tests both the Queues
template<class Container, class T>
void test() {
Queue<T> *queue{new Container{}};
// []
assert(queue->size() == 0);
queue->enqueue(1);
// [1]
queue->enqueue(2);
// [1, 2]
queue->enqueue(3);
// [1, 2, 3]
queue->enqueue(4);
// [1, 2, 3, 4]
assert(queue->size() == 4);
assert(queue->back() == 4);
assert(queue->front() == 1);
queue->dequeue();
// [2, 3, 4]
assert(queue->front() == 2);
queue->dequeue();
// [3, 4]
assert(queue->front() == 3);
queue->dequeue();
// [4]
assert(queue->front() == 4);
queue->dequeue();
// []
assert(queue->size() == 0);
delete queue;
}
#else
template<class Container>
void handle(Container& queue) {
// reading number of elements
std::cout << "Enter number of elements: ";
int N;
std::cin >> N;
// inserting elements
for(int i=0; i < N; ++i) {
std::cout << "Enter element: ";
int number;
std::cin >> number;
queue.enqueue(number);
}
// creates a copy of the queue
Container queueCopy(queue);
// prints all the elements in reverse order
std::cout << "Elements of the queue in reverse: [ ";
while(queueCopy.size() > 0) {
std::cout << queueCopy.front() << ' ';
queueCopy.dequeue();
}
std::cout << ']' << std::endl;
// removing half of the elements
for(int i=0; i < N / 2; ++i) {
queue.front();
queue.dequeue();
}
// prints the queue
std::cout << "Elements of the queue: [ ";
while(queue.size() > 0) {
std::cout << queue.front() << ' ';
queue.dequeue();
}
std::cout << ']' << std::endl;
}
#endif
int main() {
#ifdef TEST
test<Queue_Array<int>, int>();
test<Queue_List<int>, int>();
#else
// enters type of queue
int choice;
std::cout << "(1. Queue using Array 2. Queue using Link List Enter choice:)";
std::cin >> choice;
// handles rest of the program
if(choice == 1) {
Queue_Array<int> queue;
handle(queue);
} else {
Queue_List<int> queue;
handle(queue);
}
#endif
return 0;
}

