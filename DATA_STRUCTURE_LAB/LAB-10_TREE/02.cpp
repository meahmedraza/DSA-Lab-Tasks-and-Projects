#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;

class Item {
	public:
		string code;
		string name;
		string price;
		string amount;
		string dateReceived;
		string expiryDate;
		Item* left;
		Item* right;
		
		Item(){
			code = price = amount = name = dateReceived = expiryDate = "";
			left = right = NULL;
		}
		
		Item(string c, string n, string p, string a, string r, string e){
			code = c;
			name = n;
			price = p;
			amount = a;
			dateReceived = r;
			expiryDate = e;
			left = right = NULL;
		}
		
		void display(){
			cout<<std::left
				<<setw(5)<<code
				<<setw(15)<<name
				<<setw(10)<<price
				<<setw(10)<<amount
				<<setw(20)<<dateReceived
				<<setw(20)<<expiryDate<<endl;
		}
};

class BinaryTree {
	private:
		Item* root;
		int numberOfItems;
	
	public:
		BinaryTree(){
			root = NULL;
			numberOfItems = 0;
		}
		
		Item* getRoot(){
			return root;
		}
		
		int getNumberOfItems(){
			return numberOfItems;
		}
		
		void insert(Item* newItem){
			if (!root)
				root = newItem;
			else {
				Item* currItem = root;
				while (currItem != NULL){
					if (newItem->code < currItem->code) {
						if (currItem->left)
							currItem = currItem->left;
						else{
							currItem->left = newItem;
							numberOfItems++;
							break;
						}	
					} else if (newItem->code > currItem->code){
						if (currItem->right)
							currItem = currItem->right; 
						else {
							currItem->right = newItem;
							numberOfItems++;
							break;
						}	
					} else {		
		 				cout << "Duplicate Code. Code must be unique"<<endl;
						break;
					}
				}
			}
		}
		
		void find(Item* currItem, int code){
			if(currItem){
				if (stoi( currItem->code ) == code){
					cout<<"Item with code "<<code<<" found"<<endl;
					cout<<left<<setw(5)<<"Code"<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Amount"<<setw(20)<<"Date Received"<<setw(20)<<"Expiry Date"<<endl;
					currItem->display();					char choice;
					cout<<"\n\nWould you like to update this item(Y/N)? : ";
					cin>>choice;
					if (toupper( choice ) == 'Y')
						update(currItem);
					return;
				}
				find(currItem->left, code);
				find(currItem->right, code);
			}
		}
	
		void update(Item* currItem){
			cout<<"Enter new name : ";
			cin.ignore(); getline(cin, currItem->name);
			cout<<"Enter new Price : ";
			cin>>currItem->price;
			cout<<"Enter new Amount : ";
			cin>>currItem->amount;	
			cout<<"Enter new Date received : ";
			cin.ignore();getline(cin, currItem->dateReceived);
			cout<<"Enter new Expiry date : ";
			getline(cin, currItem->expiryDate);
		}
		
		void display(Item* currItem){
			if (currItem){
				currItem->display();
				display(currItem->left);
				display(currItem->right);
			}
		}
		
		void displayValidItems(Item* currItem){
			if (currItem){
				if (strcmp(currItem->dateReceived.c_str(), currItem->expiryDate.c_str()) <= 0)
					currItem->display();
				displayValidItems(currItem->left);
				displayValidItems(currItem->right);
			}
		}
		
		void displayExpiredItems(Item* currItem){
			if (currItem){
				if (strcmp(currItem->dateReceived.c_str(), currItem->expiryDate.c_str()) > 0)
					currItem->display();
				displayExpiredItems(currItem->left);
				displayExpiredItems(currItem->right);
			}
		}
		
		Item* deleteItem(Item* currentItem, int code){
			if (currentItem == NULL)
				return currentItem;
				
			if ( code < stoi( currentItem->code ) ){					
				currentItem->left = deleteItem(currentItem->left, code);
			} else if ( code > stoi( currentItem->code ) ){			
				currentItem->right = deleteItem(currentItem->right, code);
			} else {															
				if (currentItem->left == NULL && currentItem->right == NULL){		
					delete currentItem;
					currentItem = NULL;
				} else if (currentItem->left == NULL){
					Item* temp = currentItem;
					currentItem = currentItem->right;
					delete temp;
				} else if (currentItem->right == NULL){
					Item* temp = currentItem;
					currentItem = currentItem->left;
					delete temp;
				} else{
					Item* temp = findSmallestItem(currentItem->right);
					currentItem->code = temp->code;
					currentItem->right = deleteItem(currentItem->right, stoi( currentItem->code ));
				}
				numberOfItems--;
			}
			
			root = currentItem;
			return currentItem;
		}	
		
		Item* deleteAllExpiredItems(Item* currItem){
			if (currItem){
				if ( strcmp( currItem->dateReceived.c_str(), currItem->expiryDate.c_str() ) > 0 )
					deleteItem(root, stoi( currItem->code ));
				
				deleteAllExpiredItems(currItem->left);
				deleteAllExpiredItems(currItem->right);
			}
		}
		
		Item* findSmallestItem(Item* currentItem){
			if (currentItem == NULL)
				return NULL;
			else if ( currentItem->left ==NULL)
				return currentItem;
			
			return findSmallestItem(currentItem->left);
		}
		
		void putDataInFile(ofstream& file, Item* currItem){
			if (!currItem)
				return;
			
			putDataInFile(file, currItem->left);
			file<<"\n"<<currItem->code<<","<<currItem->name<<","<<currItem->price<<","<<currItem->amount<<","<<currItem->dateReceived<<","<<currItem->expiryDate<<",";
			putDataInFile(file, currItem->right);
		}
				
		void saveStockInFile(){
			ofstream file("stock.txt", ios::out);
			
			putDataInFile(file, root);
			
			file.close();
		}
		
		void putExpiredInSeparateTree(BinaryTree &tree2, Item* currItem){
			if (!currItem)
				return;
			
			putExpiredInSeparateTree(tree2,currItem->left);
			if ( strcmp( currItem->dateReceived.c_str(), currItem->expiryDate.c_str() ) > 0 )
				tree2.insert(currItem);
			putExpiredInSeparateTree(tree2, currItem->right);
		}
};

int displayMenu();
Item* createItem();

int main(){
	BinaryTree BT;
	BinaryTree binaryTreeOfExpiredItems;
	ifstream checkFile("stock.txt", ios::in);
	if(!checkFile.good()){
		ofstream file("stock.txt", ios::out);
		file.close();
		checkFile.close();
	}
	ifstream file("stock.txt", ios::in);
	
	string data;
	
	getline(file, data);
	while(!file.eof()){
		Item* item = new Item();
		getline(file, item->code, ',');
		getline(file, item->name, ',');
		getline(file, item->price, ',');
		getline(file, item->amount, ',');
		getline(file, item->dateReceived, ',');
		getline(file, item->expiryDate, ',');
		BT.insert(item);
		getline(file,data);
	}
	file.close();
	
	while (true)
		switch(displayMenu()){
			case 1:
				BT.insert( createItem() );
				break;
			
			case 2:{
				int code;
				cout<<"Enter code of item to find : ";
				cin>>code;
				BT.find(BT.getRoot(), code);
				break;
			}
			
			case 3:
				cout<<"=====Valid Items======\n";
				cout<<left<<setw(5)<<"Code"<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Amount"<<setw(20)<<"Date Received"<<setw(20)<<"Expiry Date"<<endl;
				BT.displayValidItems(BT.getRoot());
				break;
			
			case 4:
				cout<<"=====Expired Items======\n";
				cout<<left<<setw(5)<<"Code"<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Amount"<<setw(20)<<"Date Received"<<setw(20)<<"Expiry Date"<<endl;
				BT.displayExpiredItems(BT.getRoot());
				break;
			
			case 5:
				cout<<left<<setw(5)<<"Code"<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Amount"<<setw(20)<<"Date Received"<<setw(20)<<"Expiry Date"<<endl;
				BT.display(BT.getRoot());
				break;
			
			case 6:{
				int code;
				cout<<"Enter Code of Item You Want To Delete : ";
				cin>>code;
				BT.deleteItem(BT.getRoot(), code);
				cout<<"=====Successfully Deleted Item of Code "<<code<<"====="<<endl;
				break;
			}
			
			case 7:{
				BT.deleteAllExpiredItems(BT.getRoot());
				cout<<"=====Expired Items Successfully Deleted====="<<endl;
				break;
			}
			
			case 8:{
				BT.putExpiredInSeparateTree(binaryTreeOfExpiredItems, BT.getRoot());
				cout<<"=====Expired Items Successfully Put Into Separate Binary Tree====="<<endl;
				break;
			}
			
			case 9:{
				BT.saveStockInFile();
				cout<<"=====Stock Successfully Stored in 'stock.txt' File====="<<endl;
				break;
			}
			
			case 10:{
				cout<<"Exiting Program"<<endl;
				exit(0);
				break;
			}
		}	
}

int displayMenu(){
	int choice;
	cout<<"\n\n==================================================================\n";
	cout<<"1 -> Insert an Item\n"
		<<"2 -> Find Item and Update it\n"
		<<"3 -> List valid items\n"
		<<"4 -> List expired items\n"
		<<"5 -> List all items\n"
		<<"6 -> Delete item by its code\n"
		<<"7 -> Delete all expired items\n"
		<<"8 -> Create a separate Binary Tree for expired Items\n"
		<<"9 -> Save current stock in file\n"
		<<"10 -> Exit"<<endl;
		
	do {
		cout<<"Enter Your Choice : ";
		cin>>choice;
		if (choice < 1 || choice > 10)
			cout<<"Please enter a number between 1 and 10"<<endl;
	} while (choice < 1 || choice > 10);
	cout<<"\n\n\n";
	return choice;
}

Item* createItem(){
	Item* newItem = new Item();
	
	cout<<"Enter code : ";
	cin>>newItem->code;
	cout<<"Enter name : ";
	cin.ignore();
	getline(cin,newItem->name);
	cout<<"Enter price : ";
	cin>>newItem->price;
	cout<<"Enter amount : ";
	cin>>newItem->amount;
	cout<<"Enter date received (yyyy/mm/dd) : ";
	cin>>newItem->dateReceived;
	cout<<"Enter expiry date (yyyy/mm/dd) : ";
	cin>>newItem->expiryDate;
	
	return newItem;
}

