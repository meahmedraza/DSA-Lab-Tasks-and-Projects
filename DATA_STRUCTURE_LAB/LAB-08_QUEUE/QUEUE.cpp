#include <iostream>
using namespace std;
    
    int queue[10]; 
	int n = 10;  
    int front = - 1; 
    int rear = - 1;
	
int enqueue() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}

void dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"\nElement deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}

void Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"\nQueue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}

int main(){
	enqueue();
	enqueue();
	enqueue();
	enqueue();
	Display();
	dequeue();
	dequeue();
	dequeue();
	Display();
	
} 
