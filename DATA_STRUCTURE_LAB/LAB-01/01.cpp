#include<iostream>
using namespace std;
int main()
{
	int arr[10]={80, 72, 93, 87, 90, 55, 66, 74, 69, 56};
	
	for(int i=0; i<10; i++)
	{
		cout<<"Mathematics Grade of Student "<<i+1<<" is : ";
	switch(arr[i]/10)
		{
		case 9:
			cout<<"Grade is A"<<endl;
			break;
		case 8:
			(arr[i]>8.1)?cout<<"Grade is B+"<<endl : cout<<"Grade is B"<<endl;
			break;
		case 7:
			(arr[i]>7.1)?cout<<"Grade is B"<<endl : cout<<"Grade is C"<<endl;
			break;
		case 6:
			(arr[i]>6.6)?cout<<"Grade is C"<<endl : cout<<"Grade is D"<<endl;
			break;
		case 5:
			(arr[i]>5.9)?cout<<"Grade is D"<<endl : cout<<"Grade is F"<<endl;
			break;
		}
		
	}
	return 0;
}
