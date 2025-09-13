#include<iostream>
using namespace std;
int main()
{
	int arr[2][2][3]={ {{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}} };
		for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			for(int k=0; k<3; k++)
		{
			cout<<"Value in arr["<<i<<"]["<<j<<"]["<<k<<"] is:"<<arr[i][j][k]<<endl;
		}
		}
	}
	int i,j,k;
	cout<<"Enter the i: ";
	cin>>i;
	cout<<"Enter the j: ";
	cin>>j;
	cout<<"Enter the k: ";
	cin>>k;
	
	cout<<"The value at that index is:"<<arr[i][j][k];
	return 0;
}
