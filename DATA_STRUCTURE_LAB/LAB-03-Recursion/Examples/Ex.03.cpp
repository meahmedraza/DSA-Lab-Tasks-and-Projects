#include<iostream>
using namespace std;
int main()
{
	int A[9]={1,3,7,9,5,12,14,10,8};
    int num;

cout<<"Enter number you want to find: ";
cin>>num;
int div = 8/2;
//if number is on the right side
if(A[div]<num)
{

	for(int i=div; i<=8; i++)
{
	if(A[i]==num)
	{
		cout<<"Number found at the index "<<i;
	}
}
}
//if number is on the left side
else
{

		for(int i=0; i<=div; i++)
{
	if(num==A[i])
	{
		cout<<"Number found at the index "<<i;
	}
}

}
return 0;
}

