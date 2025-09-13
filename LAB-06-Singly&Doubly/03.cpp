#include <iostream>
using namespace std;
class node
{
	private:
	int data;
	node* next;
	node *head=NULL;
	node *ptr;
	public:
	void InsertNode(int value)
	{
		node* temp=new node();
		temp->data=value;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			ptr=head;
		}
		else
		{
			ptr->next=temp;
			ptr=ptr->next;	
		}
	}
	void show()
	{
		ptr=head;
		cout<<"\n\nThe values in the linked list are :\n";
		while(ptr->next!=NULL)
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->next;
		}
		cout<<ptr->data;
	}
	bool find(int find)
	{
		int found;
		ptr=head;
		while(ptr->next!=NULL)
		{
			if(ptr->data == find)
			return true;	
			ptr=ptr->next;
		}
		if(ptr->data == find)
		return true;
		return false;
	}
	void swaping(int num1,int num2)
	{
		ptr=head;
		while(ptr->data!=num1)
		{ptr=ptr->next;	}
		node*temp=head;
		while(temp->data!=num2)
		{	temp=temp->next;	}
		temp->data=num1;	
		ptr->data=num2;		
	}
};
int main()
{
	int value,no,search,i=1;
	int num1,num2;
	node n;
	do
	{
		cout<<"Enter number "<<i<<" (-1 to exit) : ";
		cin>>value;
		
		if(value!=-1)
		n.InsertNode(value);	
		i++;
	}
	while(value!=-1);
	n.show();
	cout<<"\n\nEnter the first number to find : ";
	cin>>num1;
	bool flag1=n.find(num1);
	if(flag1)
	cout<<"\nFirst number present in the linked list";
	else 
	cout<<"\nFirst number is NOT present in the linked list";
	cout<<"\n\nEnter the second number to find : ";
	cin>>num2;
	bool flag2=n.find(num2);
	if(flag2)
	cout<<"\nSecond number present in the linked list";
	else 
	cout<<"\nSecond number is NOT present in the linked list";
	if(flag1 && flag2)
	{
		n.swaping(num1,num2);
	}
	n.show();	
}
