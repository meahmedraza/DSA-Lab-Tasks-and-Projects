//Task 1: Write a code to sort the following arrays using selection sort method. 
//[10, 34, 2, 56,7,67, 88, 42]
#include<iostream>
using namespace std;
void display(int arr[],int size);
void selectionSort(int arr[],int size);
int main()
{
	int size=8;
	int arr[size] = {10,34,2,56,7,67,88,42};
	cout<<"Input array is: ";
	display(arr,size);
	
	selectionSort(arr,size);
	
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
void selectionSort(int arr[],int size)
{
	int Min,i,j;
	for(i=0; i<size-1; i++)
	{
		Min=i;
		for(j=i+1; j<size; j++)
		{
			if(arr[j]<arr[Min])
			{
				Min=j;
			}
		}
		if(Min!=i)
		{
			cout<<"\nSwapping the number "<<arr[i]<<" and "<<arr[Min]<<" :";
			int temp=arr[Min];
			arr[Min]=arr[i];
			arr[i]=temp;
		}
		
		display(arr,size);
	}
	
}
