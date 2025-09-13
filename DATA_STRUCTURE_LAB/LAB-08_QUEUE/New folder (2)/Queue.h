#ifndef _QUEUE_H_
#define _QUEUE_H_
template<class T>
class Queue {
public:
virtual void enqueue(const T& element) = 0;
virtual void dequeue() = 0;
virtual T front() const = 0;
virtual T back() const = 0;
virtual int size() const = 0;
};
#endif // _QUEUE_H_
