#include <iostream> 
using namespace std; 
#define MAX 10 
void printline(int count);
void selectionSort();
void display();
int intArray[MAX] = {5,8,7,2,4,9,1,3};

int main() 
{ 
cout<<"Input Array: "; 
display(); 
printline(50); 
selectionSort();
cout<<"Output Array: "; 
display(); 
printline(50); 
return 0;
}

void printline(int count) 
{ int i; 
 for(i = 0;i < count-1;i++)
 { 
 cout<<"="; 
 } 
cout<<"=\n"; 
}

void display()
{ 
int i; 
 cout<<"[ "; 
 
 // navigate through all items 
for(i = 0;i < MAX;i++) 
{ cout<< intArray[i]<<" "; 
 } 
cout<<"]\n"; 
}

void selectionSort()
{ 
int indexMin,i,j; 
 
 for(i =0; i<MAX-1; i++)
 { 
	indexMin = i;
for(j = i+1; j<MAX; j++)
{ 
 if(intArray[j] < intArray[indexMin]) 
{ indexMin = j; 
 } 
} 
 if(indexMin != i) 
{ 
cout<<"Items swapped: ["<<intArray[i]<<","<<intArray[indexMin]<<" ]\n"; 
 
 int temp = intArray[indexMin]; 
intArray[indexMin] = intArray[i]; 
intArray[i] = temp; 
 } 
 cout<<"Iteration "<<i+1<<" #:"; 
display(); 
 } 
}
