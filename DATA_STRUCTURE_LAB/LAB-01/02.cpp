#include<iostream>
using namespace std;
void Max(float *arr);
void Min(float *arr);
int main()
{
	float arr[5];
	cout<<"Enter any 5 floating numbers: "<<endl;
	for(int i=0; i<5; i++)
	{
		cin>>arr[i];
	}
	Max(arr);
	Min(arr);
}
void Max(float *arr)
{
	float max=0;
	for(int i=0; i<5; i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	cout<<"Maximum value you enetered is:"<<max<<endl;

}
void Min(float *arr)
{
	float min=arr[0];
	for(int i=0; i<5; i++)
	{
		if(min>arr[i])
		{
			min=arr[i];
		}
		
		
	}
		cout<<"Minimum value you enetered is:"<<min<<endl;
}
