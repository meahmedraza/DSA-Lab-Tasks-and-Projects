#include <iostream>
using namespace std;

struct node 
{
    int data;                
    node *next;             
}
*stnode;
node *head,*tail;
void InsertAtHead(int value) 
 { 
 stnode=new node; 
stnode->data=value; 
stnode->next=head; 
if(head==NULL) 
 { head=stnode; 
tail=stnode; 
 } 
 else 
{ 
 head=stnode; 
} 
 } 
 void display() 
 { node *stnode=new node; 
stnode=head; 
while(stnode!=NULL) 
{ 
 cout<<stnode->data<<",";
  stnode=stnode->next; 
 } 
cout<<"\b \b";
	
}
                 
void searchList(int item, int n);
 


void searchList(int item , int n)
{  
    struct node *stnode;  
    int i=0,flag;  
   

  
	if(stnode == NULL)  
    {  

        cout<<"\nEmpty List\n";  
    }  
    else  
    {   

        while (stnode!=NULL)  
        {  
        cout<<stnode->data;
            if(stnode->data == item) 
            {  
                cout<<"Item found  "<<i; 
        	}
			else
			cout << "Not";  
	        //if(temp->data!=item)
	        //{  cout<<"11;";
	        //    cout<<"Item not found\n";  
	       // }
			  stnode=stnode->next;
    }  
}
}


int main()
{
    	
   InsertAtHead(25);
   InsertAtHead(30);
    InsertAtHead(50);
    InsertAtHead(90);
    InsertAtHead(60);
    InsertAtHead(40);
	display();
	int n,num,item;
			
    
    cout<<"\nEnter element you want to search: ";   
    cin>>item;
    searchList(item,n);

    return 0;
}
