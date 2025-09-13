//Task 1: Write a code to sort the following arrays using bubble sort method.
//[10, 34, 2, 56,7,67, 88, 42]
#include<iostream>
using namespace std;
void display(int arr[],int size);
void BubbleSort(int arr[],int size);
int main()
{
	int size=8;
	int arr[size] = {10,34,2,56,7,67,88,42};
	cout<<"Input array is: ";
	display(arr,size);
	
	BubbleSort(arr,size);
	
	return 0;
}
void display(int arr[],int size)
{
	cout<<"\n[";
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"]";
}
void BubbleSort(int arr[],int size)
{
	int i,j;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size-1-i; j++)
		{
			if(arr[j]>arr[j+1])
			{
			cout<<"\nSwapping the number "<<arr[j]<<" and "<<arr[j+1]<<" :";
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			display(arr,size);
			}
		
		}
			cout<<"\nIteration completed "<<i<<endl;
			
	}
	
}
