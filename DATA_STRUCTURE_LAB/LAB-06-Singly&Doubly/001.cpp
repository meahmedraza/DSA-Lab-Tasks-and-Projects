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
	
	int size()
	{
		int size=0;
		ptr=head;
		cout<<endl;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			size++;
		}
		size++;
		return size;
	}

};

int main()
{
	int value,num,i=1;
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
	cout<<"\nThe number of elements in the linked list are: "<<n.size();
}

