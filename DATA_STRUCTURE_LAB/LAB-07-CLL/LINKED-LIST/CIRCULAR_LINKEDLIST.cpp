#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		int key;
		Node* next;
		//initialize
		Node()
		{
			key=0;
			data=0;
			next=NULL;
		}
		Node(int key, int data)
		{
			this->key=key;
			this->data=data;
		}

};
class CircularLinkedList
{
	public:
		Node* head;
		
		CircularLinkedList()
		{
			head=NULL;
		}
		SinglyLinkedList(Node* n)
		{
			head=n;
		}
		//Check Node exist by using key
		
		Node* nodeExist(int k)
		{
			Node* temp =NULL; 
			Node* ptr =head;
			
			if(ptr==NULL)
			{
				return temp;
			}
			else
			{
				do
				{
					if(ptr->key==k)
					{
						temp=ptr;
					}
					ptr=ptr->next;
				}
				while(ptr!=head);
				return temp;
			}
			//return temp;
		}
		
//		2-Append a node to a list

void appendNode(Node *new_node)
{
	if(nodeExist(new_node->key)!=NULL)
	{
		cout<<"Node Already exits with the key value: "<<new_node->key<<". Append another node 	with the diifferent Key value"
		<<endl;	
	}
	else
	{
		if(head==NULL)
		{
			head=new_node;
			new_node->next=head;
			cout<<"Node Appended at first Head position"<<endl;
		}
		else
		{
			Node* ptr=head;
			while(ptr->next!=head)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=head;
			cout<<"Node Appended"<<endl;
		}
	}
}
// 3. Prepend Node- Attach a Node at Start

void prependedNode(Node *new_node)
{
	if(nodeExist(new_node->key)!=NULL)
	{
		cout<<"Node Already exits with the key value: "<<new_node->key<<". Append another node 	with the diifferent Key value"
		<<endl;	
	}
	
		
	else
	{
		Node* ptr=head;
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->next=head;
		head=new_node;
		cout<<"Node Appended"<<endl;
	}
}
//4. Insert a node after particular node in the list

void insertNodeAfter( int k, Node* new_node)
{
	Node* ptr=nodeExist(k);
	if(ptr==NULL)
	{
		cout<<"No Node Existswith the key value OF: "<<k<<endl;
	}
	else
	{
		if( nodeExist(new_node->key)!=NULL)
		{
			cout<<"Node Already exits with the key value: "<<new_node->key<<". Append another node 	with the diifferent Key value"
		<<endl;	
		}
		else
	{
		if(ptr->next==head)
		{
		new_node->next=head;
		ptr->next=new_node;
		cout<<"Node Inserted At the End	"<<endl;
		}
		else
		{
			new_node->next=ptr->next;
			ptr->next=new_node;
			cout<<"Node Inserted in between"<<endl;
		}
	  }
	}
}

// 5. Delete a Node by Unique Key
void deleteNodeByKey(int k)
	{
	Node* ptr= nodeExist(k);
	if(ptr==head)
	{
		if(head->next==NULL)
		{
			head=NULL;
			cout<<"Head node Unliked...List Empty";
		}
		else
		{
			Node* ptr1 =head;
			while(ptr->next!=head)
			{
				ptr1=ptr->next;
			}
			ptr1->next=head->next;
			head=head->next;
			cout<<"Node UNLIKED with the Keys Value"<<k<<endl;
		}
	}
	else
	{
		Node* temp=NULL;
		Node* prevptr = head;
		Node* currentptr = head->next;
		while(currentptr!=NULL)
		{
			if(currentptr->key==k)
			{
				temp = currentptr;
				currentptr=NULL;
			}
			else
			{
				prevptr = prevptr->next;
				currentptr = currentptr->next;
			}
		}
		prevptr->next = temp->next;
		cout<<"Node UNLIKED with the Keys Value : "<<k<<endl;
	}	
}

// 6th Update Node by Specific Key

void updateNodeByKey(int k, int new_data)
	{
	Node* ptr= nodeExist(k);
	if(ptr!=NULL)
	{
		ptr->data = new_data;
		cout<<"Node Data Updated Successfully...";
	}
	else
		{
			cout<<"Node Doesn't Exist with the Key Value: "<<k<<endl;
		}
	}
	
	// 7th Printing 
	void printList()
	{
		if(head==NULL)
		{
			cout<<"No Nodes in Singly Linked List";
		}
		else
		{
			cout<<"\nHead Address: "<<head<<endl;
			cout<<"Singly Linked List Values: "<<endl;
			
			Node* temp = head;
			
			do
			{
				cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<") --> ";
				temp = temp->next;
			}
			while(temp!=head);
		}
	}

};
// Main functoin

int main()
{
	CircularLinkedList obj;
	int option;
	int key1, k1,data1;
	do
	{
		cout<<"\nWhat operation you want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNodeAfter()"<<endl;
		cout<<"4. deleteNodeByKey()"<<endl;
		cout<<"5. updateNodeByKey()"<<endl;
		cout<<"6. print()"<<endl;
		cout<<"7. Clear Screen"<<endl<<endl;
		
		cin>>option;
		Node* n1 = new Node();
		
//		Node n1
		
		switch(option)
		{
			case 0:
				break;
			case 1:
					cout<<"Append Node Operation \nEnter key & data of the Node to be Appended"<<endl;
					cin>>key1;
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					obj.appendNode(n1);
//					cout<<n1.key<<" = "<<n1.data<<endl;
					break;
			case 2:
					cout<<"Prepend Node Operation \nEnter key & data of the Node to be Prepended"<<endl;
					cin>>key1;
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					obj.prependedNode(n1);
//					cout<<n1.key<<" = "<<n1.data<<endl;
					break;
			case 3:
					cout<<"Insert Node after Operation \nEnter key of existing Node after which you want to Insert this node: "<<endl;
					cin>>k1;
					cout<<"Enter key & data of the New Node first: "<<endl;
					cin>>key1;
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					
					obj.insertNodeAfter(k1,n1);
					break;
		    case 4:
					cout<<"Delete Node By Key Operation \nEnter key of the Node to be deleted: "<<endl;
					cin>>k1;
					obj.deleteNodeByKey(k1);
					break;
			case 5:
					cout<<"Update Node By Key Operation \nEnter key & New data to be updated: "<<endl;
					cin>>key1;
					cin>>data1;
					obj.updateNodeByKey(key1,data1);
					break;
			case 6:
				obj.printList();
				break;
			case 7:
				system("cls");
				break;
				
			default:
				cout<<"Enter Proper Option number "<<endl;
		}
	}while(option!=0);
}
