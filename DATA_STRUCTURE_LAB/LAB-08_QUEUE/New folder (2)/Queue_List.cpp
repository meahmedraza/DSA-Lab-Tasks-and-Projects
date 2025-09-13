#ifndef _QUEUE_LIST_H_
#define _QUEUE_LIST_H_
#include "Queue.h"
#include <list>
template<class T>
class Queue_List : public Queue<T> {
public:
void enqueue(const T& element);
void dequeue();
T front() const;
T back() const;
int size() const;
private:
std::list<T> data;
};
#include "Queue_List.cpp"
#endif // _QUEUE_LIST_H_
