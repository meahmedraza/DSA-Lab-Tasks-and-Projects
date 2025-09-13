#include "Queue_List.h"
template<class T>
void Queue_List<T>::enqueue(const T& element) {
data.emplace_back(element);
}
template<class T>
void Queue_List<T>::dequeue() {
data.pop_front();
}
template<class T>
T Queue_List<T>::front() const {
return data.front();
}
template<class T>
T Queue_List<T>::back() const {
return data.back();
}
template<class T>
int Queue_List<T>::size() const {
return data.size();
}

