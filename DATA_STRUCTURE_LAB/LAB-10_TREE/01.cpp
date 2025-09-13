#include<iostream>
using namespace std;
class TreeNode
{
	public:
	int value;
	TreeNode *left;
	TreeNode *right;
	bool printGivenLevel(TreeNode*, int num); 
	void insertNode(int num);
};

TreeNode *root=NULL;

//INSERT
void TreeNode :: insertNode(int num)
{
TreeNode *temp= new TreeNode; // Pointer to traverse the
 TreeNode *nodePtr= new TreeNode; // Create a new node
temp->value = num;
temp->left = temp->right = NULL;

if (!root) // Is the tree empty?
 root = temp;
 
else
{
nodePtr = root;

while (nodePtr != NULL)
 {
 if (num < nodePtr->value)
 {
	if (nodePtr->left)
	nodePtr = nodePtr->left;
	else
	{
	 nodePtr->left = temp;
	 break;
	}
 }
 else if (num > nodePtr->value)
 {
 if(nodePtr->right)
 nodePtr = nodePtr->right; 
 else
 	{
	 nodePtr->right = temp;
	 break;
 	}
} 
 else
 {
 cout << "Duplicate value found in tree.\n";
 break;
 }	
}
}
} 

//INORDER
 void displayInorder(TreeNode *nodePtr)
{
if(nodePtr)
 {
  displayInorder(nodePtr->left);
  cout<<nodePtr->value<<",";
  displayInorder(nodePtr->right);
 } 
}
//PREORDER
void displayPreorder(TreeNode *nodePtr)
{
if(nodePtr)
 {
  cout<<nodePtr->value<<",";
  displayPreorder(nodePtr->left);
  displayPreorder(nodePtr->right);
 }
}
//POSTORDER
void displayPostorder(TreeNode *nodePtr)
{
if(nodePtr)
 {
  displayPostorder(nodePtr->left);
  displayPostorder(nodePtr->right);
  cout<<nodePtr->value<<",";
 }
}
	
int main() {
int n,num;
cout << "Inserting nodes. "<<endl;
cout<<"Enter number of nodes you want to enter: ";
cin>>n;
while(n>0)
{
	cin>>num;
	root->insertNode(num);
	n--;
}
cout << "Done.\nInorder Display:\n"; displayInorder(root);
cout << "\nPreorder Display:\n"; displayPreorder(root);
cout << "\nPostorder Display:\n"; displayPostorder(root);
 
return 0;
}
