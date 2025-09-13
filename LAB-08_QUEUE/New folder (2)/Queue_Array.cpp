#ifndef _QUEUE_ARRAY_H_
#define _QUEUE_ARRAY_H_
#include "Queue.h"
#include <vector>
template<class T>
class Queue_Array : public Queue<T> {
public:
void enqueue(const T& element);
void dequeue();
T front() const;
T back() const;
int size() const;
private:
std::vector<T> data;
};
#include "Queue_Array.cpp"
#endif // _QUEUE_ARRAY_H_

