#include<iostream>
using namespace std;
int main()
{
	int arr[10];
	cout<<"Please enter 10 numbers: "<<endl;
	for(int i=0; i<10; i++){
	cin>>arr[i];
	}
	cout<<"\nElement\t\tValue\t\tHistogram"<<endl;
	for(int i=0; i<10; i++)
	{
		cout<<i<<"\t\t"<<arr[i]<<"\t\t";
		for(int j=0; j<arr[i]; j++)
		cout<<"*";
		cout<<endl;
	}
return 0;
}
