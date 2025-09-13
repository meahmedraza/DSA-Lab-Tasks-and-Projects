#include <iostream>
 
using namespace std;
 
// Linked list node
struct Node {
    int data;
    Node* next;
};
 
// function to get a new node
Node* getNode(int data)
{
    // allocate memory for node
    Node* newNode = new Node;
 
    // put in the data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// Function to reverse the circular linked list
void reverse(Node** head_ref)
{
    // if list is empty
    if (*head_ref == NULL)
        return;
 
    // reverse procedure same as reversing a
    // singly linked list
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (*head_ref));
 
    // adjutsing the links so as to make the
    // last node point to the first node
    (*head_ref)->next = prev;
    *head_ref = prev;
}
 
// Function to print circular linked list
void printList(Node* head)
{
    if (head == NULL)
        return;
 
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
 
// Driver program to test above
int main()
{
	int num1,num2,num3,num4;
	cout<<"Enter 4 any number:\n";
	cin>>num1>>num2>>num3>>num4;

    Node* head = getNode(num1);
    head->next = getNode(num2);
    head->next->next = getNode(num3);
    head->next->next->next = getNode(num4);
    head->next->next->next->next = head;
 
    cout << "Given circular linked list: ";
    printList(head);
 
    reverse(&head);
 
    cout << "\nReversed circular linked list: ";
    printList(head);
 
    return 0;
}
