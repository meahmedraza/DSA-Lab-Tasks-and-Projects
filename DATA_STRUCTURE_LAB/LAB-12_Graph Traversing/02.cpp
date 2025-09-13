#include<iostream>
using namespace std;

class GraphNode;
class List;
void displayList(List*);
struct ListNode{
	GraphNode* storedNode;
	ListNode* next;
};

class List{
	public:
		ListNode* head;

		List(){
			head = NULL;
		}
		
		void insert(GraphNode* newGraphNode){
			ListNode* newListNode = new ListNode;
			newListNode->storedNode = newGraphNode;
			newListNode->next = head;
			head = newListNode;
		}
		
		GraphNode* getNode(int i){
			if(!head)
				return NULL;
			int currIndex = 0;
			ListNode* currNode = head;
			while(currNode && currIndex<i){
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

class Stack{
	public:
		ListNode* top;
	
		Stack(){
			top = NULL;
		}
		
		void push(GraphNode* newGraphNode){
			ListNode* newListNode = new ListNode;
			newListNode->storedNode = newGraphNode;
			newListNode->next = top;
			top = newListNode;
		}
		
		GraphNode* pop(){
			if(isEmpty())
				return NULL;
			
			GraphNode* dequeueNode = top->storedNode;
			top = top->next;
			return dequeueNode;
		}
		
		GraphNode* peek(){
			return top->storedNode;
		}
		
		bool isEmpty(){
			return (top == NULL);
		}
};

class GraphNode{
	public:
		char value;
		int color;			//0=white/unvisisted  1=grey/discovered  2= black/explored
		List* adjacentNodes;
		
		GraphNode(){
			value = '-';
			color = 0;		//white, unvisited
			adjacentNodes = new List;
		}
		
		GraphNode(char v){
			value = v;
			color = 0;		//white, unvisited
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

void depthFirstSearch(GraphNode* source){
	Stack S;
	S.push(source);
	
	while(!S.isEmpty()){
		GraphNode* u = S.pop();
		if(u->color == 0){
			cout<<u->value<<" ";
			u->color = 1;
		} 
		
		for (int i=0; i<u->adjacentNodes->size(); i++){
			if(u->adjacentNodes->getNode(i)->color == 0)
				S.push(u->adjacentNodes->getNode(i));
			cout<<"";
		}
	}
}





int main(){
	int numberOfNodes = 6;
	List listOfNodes;
	GraphNode* node1 = new GraphNode('Z');
	GraphNode* node2 = new GraphNode('Y');
	GraphNode* node3 = new GraphNode('X');
	GraphNode* node4 = new GraphNode('W');
	GraphNode* node5 = new GraphNode('V');
	GraphNode* node6 = new GraphNode('U');
	
	node1->adjacentNodes->insert(node2); node1->adjacentNodes->insert(node3); node1->adjacentNodes->insert(node6);
	node2->adjacentNodes->insert(node1); 
	node3->adjacentNodes->insert(node1); node3->adjacentNodes->insert(node4); node3->adjacentNodes->insert(node5);
	node4->adjacentNodes->insert(node3); node4->adjacentNodes->insert(node5); 
	node5->adjacentNodes->insert(node3); node5->adjacentNodes->insert(node4); node5->adjacentNodes->insert(node6);
	node6->adjacentNodes->insert(node1); node6->adjacentNodes->insert(node5);
	
	listOfNodes.insert(node1);
	listOfNodes.insert(node2);
	listOfNodes.insert(node3);
	listOfNodes.insert(node4);
	listOfNodes.insert(node5);
	listOfNodes.insert(node6);
	

	GraphNode* temp;
	for (int i=0; i<numberOfNodes; i++)
		listOfNodes.getNode(i)->color == 0;

	cout<<"Source Node : "<<node1->value<<endl;
	cout<<"Depth First Search Output : ";
	for (int i=numberOfNodes-1; i>=0; i--)		//A is on last index, so search starts from A
		if (listOfNodes.getNode(i)->color==0)
			depthFirstSearch(listOfNodes.getNode(i));
}

