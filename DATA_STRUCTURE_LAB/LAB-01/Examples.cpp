#include<iostream>
using namespace std;
int main()
{
	int arr[2][3];
	
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<"Enter value in arr["<<i<<"]["<<j<<"]:";
			cin>>arr[i][j];
		}
	}
	int i, j;
	cout<<"enter the index you want to print: ";
	cin>>i>>j;
	
	cout<<"The value at that index is:"<<arr[i][j];
//		for(int i=0; i<2; i++)
//	{
//		for(int j=0; j<3; j++)
//		{
//			cout<<"Value in arr["<<i<<"]["<<j<<"] is:"<<arr[i][j]<<endl;
//		}
//	}
	return 0;
}
