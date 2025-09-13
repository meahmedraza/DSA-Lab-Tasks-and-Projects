// C++ program to find first and last occurrence of
// an elements in given sorted array
#include <iostream>
using namespace std;
void findFirstAndLast(int arr[], int n, int x);

int main()
{
	int arr[10] = { 1, 2, 2, 2, 2, 3, 4, 3, 8, 8 };
	int n = sizeof(arr) / sizeof(int);
	int x;
	for(int i=0; i<10; i++)
	cout<<arr[i]<<" ";
	cout<<"\nEnter number you want to find :";
	cin>>x;
	findFirstAndLast(arr, n, x);
	return 0;
}
// Function for finding first and last occurrence
// of an elements
void findFirstAndLast(int arr[], int n, int x)
{
	int first = -1, last = -1;
	for (int i = 0; i < n; i++) {
		if (x != arr[i])
			continue;
		if (first == -1)
			first = i;
		last = i;
	}
	if (first != -1)
		cout << "First Occurrence = " << first
			<< "\nLast Occurrence = " << last;
	else
		cout << "Not Found";
}
