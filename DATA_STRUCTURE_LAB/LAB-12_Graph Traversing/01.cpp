#include<iostream>
using namespace std;

class GraphNode;
class List;
void displayList(List*);
struct ListNode{
	GraphNode* storedNode;
	ListNode* next;
};
class List
{
	public:
		ListNode* head;

		List()
		{
			head = NULL;
		}
		
		void insert(GraphNode* newGraphNode)
		{
			ListNode* newListNode = new ListNode;
			newListNode->storedNode = newGraphNode;
			newListNode->next = head;
			head = newListNode;
		}
		
		GraphNode* getNode(int i)
		{
			if(!head)
				return NULL;
			int currIndex = 0;
			ListNode* currNode = head;
			while(currNode && currIndex<i)
			{
				currNode = currNode->next;
				currIndex++;
			}
			if(!currNode)
				return NULL;
			return currNode->storedNode;
		}
		
		void display(){
			displayList(this);
		}
		
		int size(){
			if(!head)
				return 0;
			int s;
			ListNode* currNode = head;
			while(currNode!=NULL){
				s++;
				currNode = currNode->next;
			}
			return s;
		}
};
class Queue{
	public:
		ListNode* front;
		ListNode* rear;
	
		Queue(){
			front = rear = NULL;
		}
		
		ListNode* enqueue(GraphNode* newGraphNode){
			ListNode* newListNode = new ListNode;
			newListNode->storedNode = newGraphNode;
			newListNode->next = NULL;
			if (front == NULL && rear == NULL){
				front = rear = newListNode;
			} else {
				rear->next = newListNode;
				rear = newListNode;
			}
			return newListNode;
		}
		
		GraphNode* dequeue(){
			if(isEmpty())
				return NULL;
			
			GraphNode* dequeueNode = front->storedNode;
			if (front == rear)
				rear = NULL;
			front = front->next;
			//delete front;
			return dequeueNode;
		}
		
		bool isEmpty(){
			return (front == NULL);
		}
};
class GraphNode{
	public:
		char value;
		int color;			//0=white/unvisisted  1=grey/discovered  2= black/explored
		GraphNode* parent;
		int distance;
		List* adjacentNodes;
		
		GraphNode(){
			value = '-';
			color = 0;		//white, unvisited
			parent = NULL;
			distance = 0;
			adjacentNodes = new List;
		}
		
		GraphNode(char v){
			value = v;
			color = 0;		//white, unvisited
			parent = NULL;
			distance = 0;
			adjacentNodes = new List;
		}
};
void displayList(List* list){
	if(!list->head)
		return;
	ListNode* currNode = list->head;
	while(currNode!=NULL){
		cout<<currNode->storedNode->value<<" ";
		currNode = currNode->next;
	}
	cout<<endl;
}
int main(){
	
	List listOfNodes;
	GraphNode* node1 = new GraphNode('Z');
	GraphNode* node2 = new GraphNode('Y');
	GraphNode* node3 = new GraphNode('X');
	GraphNode* node4 = new GraphNode('W');
	GraphNode* node5 = new GraphNode('V');
	GraphNode* node6 = new GraphNode('U');
	
	node1->adjacentNodes->insert(node2); node1->adjacentNodes->insert(node3); node1->adjacentNodes->insert(node4);
	node2->adjacentNodes->insert(node1); node2->adjacentNodes->insert(node5);
	node3->adjacentNodes->insert(node1); node3->adjacentNodes->insert(node6);
	node4->adjacentNodes->insert(node1); node4->adjacentNodes->insert(node6);
	node5->adjacentNodes->insert(node2);
	node6->adjacentNodes->insert(node3); node6->adjacentNodes->insert(node4);
	
	listOfNodes.insert(node1);
	listOfNodes.insert(node2);
	listOfNodes.insert(node3);
	listOfNodes.insert(node4);
	listOfNodes.insert(node5);
	listOfNodes.insert(node6);
	
	//SEARCH STARTS HERE
	//initialize vertices/nodes
	GraphNode* temp;
	for (int i=0; i<5; i++){
		temp = listOfNodes.getNode(i);
		temp->color = 0;
		temp->distance = 9999;
		temp->parent = NULL;
	}
	

	temp=listOfNodes.getNode(5);
	temp->color = 1;
	temp->distance = 0;
	temp->parent = NULL;
	

	int size;
	GraphNode *u, *v;
	Queue Q;
	Q.enqueue(node1);

	while(!Q.isEmpty()){
		u = Q.dequeue();
		cout<<u->value<<" ";
		size = u->adjacentNodes->size();
		
		for (int i=0; i<size; i++){
			v = u->adjacentNodes->getNode(i);
			if (v->color == 0){
				v->color = 1;
				v->distance = u->distance + 1;
				v->parent = u;
				Q.enqueue(v);
			}
		}
		u->color = 2;
	}
}
