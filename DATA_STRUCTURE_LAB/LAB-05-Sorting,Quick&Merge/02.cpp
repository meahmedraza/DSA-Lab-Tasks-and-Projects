#include <iostream>            
using namespace std;

void swapping(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int l,int h)
{
	int pivot = a[h];                  // pivot
	int i=(l-1); 
	for (int j=l; j<=h-1;j++)
	{
		if (a[j]<pivot)
		{
			i++; 
			swapping(&a[i],&a[j]);
		}
	}
	swapping(&a[i+1],&a[h]);
	return (i+1);
}

void quickSort(int a[],int low,int high)
{
	if (low<high)
	{
		int pi=partition(a,low,high);

		quickSort(a,low,pi-1);
		quickSort(a,pi+1,high);
	}
}


void Show(int a[],int size)
{
	int i;
	for (i=0;i<size;i++)
	cout<<a[i]<<"\t";
}

int main()
{
	int a[] = {10, 34, 45, 33, 23, 47, 31, 23, 45, 69, 2, 56,7,67, 88, 42};
	int size = sizeof(a)/sizeof(a[0]);
	
	cout << "\nThe array is\n";
            Show(a,size);
    
	quickSort(a,0,size-1);
	
	cout<<"\n\nSorted array:\n";
	Show(a,size);
}

