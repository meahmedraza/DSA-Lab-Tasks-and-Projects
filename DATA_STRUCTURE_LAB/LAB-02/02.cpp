//Write a program to convert Fahrenheit temperature to Celsius degrees by passing pointers as 
//arguments to the function. The formula for the conversion is: c = ( f-32) *5 .0/9.0. The output of 
//the program should be like:
#include<iostream>
using namespace std;
void convert(int *p);
int main()
{
	int temp;
	int *p;
	cout<<"Enter temperature in Fahrenheit: ";
	cin>>temp;
	cout<<"\nTemperature in Fahrenheit is: "<<temp<<endl;
	temp;
	convert(&temp);
	cout<<"\nTemperature in Celsius is: "<<temp<<endl;
	return 0;
}
void convert(int *p)
{
	*p = ((*p-32)*5)/9;
//	return *p;
}
