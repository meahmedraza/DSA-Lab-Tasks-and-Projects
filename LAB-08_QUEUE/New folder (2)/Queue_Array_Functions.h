#include "Queue_Array.h"
template<class T>
void Queue_Array<T>::enqueue(const T& element) {
data.emplace_back(element);
}
template<class T>
void Queue_Array<T>::dequeue() {
data.erase(data.begin());
}
template<class T>
T Queue_Array<T>::front() const {
return data.front();
}
template<class T>
T Queue_Array<T>::back() const {
return data.back();
}
template<class T>
int Queue_Array<T>::size() const {
return data.size();
}
