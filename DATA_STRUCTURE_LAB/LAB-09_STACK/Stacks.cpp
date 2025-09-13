#include <iostream>
#include <conio.h>
using namespace std;
struct link
{
	int data;
	link *next;
};
class Stack
{
	private:
		link *top;
		public:
			Stack();
			void push(int d);
			int pop();
			void show();
};
Stack::Stack()
{
	top=NULL;
}
void Stack::push(int d)
{
	link *ptr,*temp;
	if(top==NULL)
	{
		top=new link;
		top->data=d;
		top->next=NULL;
	}
else
	{
		ptr=top;
		
		while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
		temp=new link;
		temp->data=d;
		temp->next=NULL;
		ptr->next=temp;
     	
	}	
}
int Stack::pop()
{
	link *temp,*pre;
	int n;
	temp=top;
	if(top==NULL)
	{
		cout<<"Stack empty"<<endl;
		return 0;
	}
pre=temp;
	while(temp->next!=NULL)
	{
		pre=temp;
		temp=temp->next;
	}
	
	pre->next=NULL;
	n=temp->data;
	delete temp;
	return n;
	}
void Stack::show()
	{
		link *temp;
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}	}
int main()
{
Stack s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.show();
cout<<endl;
s.pop();
s.pop();
s.show();
cout<<endl;
		s.push(50);
		s.show();
		getch();
		
		
	}
