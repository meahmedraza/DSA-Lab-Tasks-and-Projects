#include <iostream> 
using namespace std; 
 
int binarySearch(int arr[], int start, int end, int num);
void display(int arr[],int size);
int main(void) 
{
		int size, num;
		cout<<"Enter the size of array: ";
		cin>>size;
		int arr[size];
		 for(int i=0; i<size; i++)
		{
			cout<<"Enter number at index arr["<<i<<"] ";
			cin>>arr[i];
			cout<<endl;
		}
	display(arr, size);
	cout << "\nEnter the number you want to find: "; 
	cin >>num; 
	int end=size-1;
	 int result = binarySearch(arr, 0, end, num);
		 if(result == -1)
		 { 
		 cout<<"Element is not present in array"<<endl; 
		}
		else
		{ 
		 cout<<"Element is present at index "<<result; 
		} 
	return 0; 
}
void display(int arr[],int nsize)
{ 
for(int i=0;i<nsize;i++){ 
 cout<<arr[i]<<","; 
} 
cout<<"\b \b"<<endl; 
} 

int binarySearch(int arr[], int start, int end, int num) 
{ 
 while (start <= end) 
	 { 
		int mid = (start + end)/2; 
		if (arr[mid] == num) 
		return mid;
		else if (arr[mid] < num) 
		start = mid + 1; 
		else 
		end = mid - 1; 
	 } 
 
 // if we reach here, then element was not present
 return -1; 
} 
