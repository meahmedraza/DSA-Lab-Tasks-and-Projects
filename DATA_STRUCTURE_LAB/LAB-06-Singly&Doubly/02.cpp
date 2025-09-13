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

};

int main()
{
	int value,search,i=1;
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
	cout<<"\n\nEnter the number to find : ";
	cin>>search;
	
	bool flag=n.find(search);
	
	if(flag)
	cout<<"\nIt is present in the linked list";
	
	else 
	cout<<"\nIt is NOT present in the linked list";
}

