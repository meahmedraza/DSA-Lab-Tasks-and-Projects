#include <iostream>
using namespace std;

class Stack
{
	private:
		int top;
		int size;
		int arr[];
	public:
		Stack(int si)
		{
			size=si;
			top=-1;
		}
		int pop()
		{
			if(top==-1)
			{
				cout<<"Stack Underflow"<<endl;
			}
			else{
				int temp=top;
				top--;
				return arr[temp];
			}
		}
		
		int pop_index(int index)
		{
			if(top==-1)
			{
				cout<<"Stack Underflow"<<endl;
			}
			else{
				return arr[index];
			}
		}
		
		void push(int num)
		{
			if(top==size-1)
			{
				cout<<"Stack is Overflowed"<<endl;
			}
			else{
				top++;
				arr[top]=num;
			}
		}
		void display()
		{
			cout<<"\n\t\t__The Elements in the Stacks are__"<<endl<<endl;
			for(int i=size-1;i>=0;i--)
			{
				cout<<"\t\t\t|| "<<arr[i]<<" ||"<<endl;
			}
			cout<<"\t\t\t-------"<<endl;
		}
		
};
main()
{
	Stack s1(10);
	
	s1.push(0);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	
	Stack s2(3);
	
	int num;
		s1.display();
	for(int i=0;i<3;i++)
	{
		cout<<"Enter Index-number to input: ";
		cin>>num;
		s2.push(s1.pop_index(num));
	}
	
	s2.display();
	return 0;
}

