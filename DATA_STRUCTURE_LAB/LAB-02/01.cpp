#include<iostream>
using namespace std;
int swap(int *p1,int *p2);
int main()
{
	int a, b;
	int *p1,*p2;
	cout<<"Enter frist number: ";
	cin>>a;
	cout<<"Enter second number: ";
	cin>>b;
	cout<<"\nBefore Swapping values"<<endl;
	cout<<"Value of a is "<<a<<" and value of b is "<<b<<endl;
	p1=&a;
	p2=&b;
	
	swap(*p1,*p2);
	cout<<"After Swapping values"<<endl;
	cout<<"Value of a is "<<a<<" and value of b is "<<b<<endl;
}
int swap(int *p1,int *p2)
{
	int s=*p1;
	*p1=*p2;
	*p2=s;
}
