//Then, create a structure variable(s). Then take data (name, roll and marks) from user and store it 
//in data members of structure variables. Display the data Entered by the user
#include<iostream>
#include<cstdlib>
using namespace std;
struct Student
{
	string name;
	int marks;
	double Roll_no;
};
int main()
{
	int size;
	cout<<"Enter the number of students you want to put data: ";
	cin>>size;
	Student S[size];
	for(int i=0; i<size;i++)
	{
		cout<<"\nEnter information for Student 0"<<i+1<<endl;
		cin.ignore();
		cout<<"\nEnter the name of the student: ";
		getline(cin,S[i].name);
		cout<<"\nEnter the marks of the student: ";
		cin>>S[i].marks;
		cout<<"\nEnter the Roll_no of the student: ";
		cin>>S[i].Roll_no;
	}
	for(int i=0; i<size; i++)
	{
		cout<<"\nInformation for Student 0"<<i+1<<endl;
		cout<<"\nName of the student: "<<S[i].name;
		cout<<"\nMarks of the student: "<<S[i].marks;
		cout<<"\nRoll_no of the student: "<<S[i].Roll_no<<endl;
	}
	return 0;
}
