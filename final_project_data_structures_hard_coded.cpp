#include <iostream>
#include<iomanip>
using namespace std;

class Item {
public:
	string name;
	int price;
	int quantity;

	Item() {
		name = ""; // initializing name to avaid dummy values
		price = quantity = 0;
	}

	Item(string n, int p, int q) {
		name = n;
		price = p;
		quantity = q;
	}
};

struct ItemNode {
	Item item;
	ItemNode* next;

	ItemNode(){
		next = NULL;
	}

	ItemNode(Item* item) {
		this->item = *item;
		next = NULL;
	}
};

class VendingMachine {
public:
	ItemNode *front, * rear;
	int numberOfItems;

	VendingMachine() {
		front = rear = NULL;
		numberOfItems = 0;
	}

	//enqueue
	void insertItem(Item* item) {
		ItemNode* newNode = new ItemNode(item);
		numberOfItems++;
		if (rear == NULL) {
			front = rear = newNode;
			return;
		}
		rear->next = newNode;
		rear = newNode;
	}

	//dequeue
	Item* dequeue() {
		if (front == NULL)
			return NULL;

		ItemNode* nodeToRemove = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		numberOfItems--;
		return &nodeToRemove->item;
	}

	//getItem
	Item* getItem(int index) {
		if (front == NULL)
			return NULL;
		ItemNode* currNode = front;
		int currIndex = 1;

		while (currNode && currIndex < index) {
			currNode = currNode->next;
			currIndex++;
		}
		return &currNode->item;
	}

	//reduce quantity by this amount
	void decreaseQuantity(int index, int amount) {
		if (front == NULL)
			return;
		ItemNode* currNode = front;
		int currIndex = 1;

		while (currNode && currIndex < index) {
			currNode = currNode->next;
			currIndex++;
		}

		if (currNode->item.quantity > amount)
			currNode->item.quantity -= amount;
		else
			currNode->item.quantity = 0;
	}
	
	bool productAvbCheck(int id){
		if (front == NULL)
			return true;
		
		ItemNode* currNode = front;
		int currIndex = 1;
		
		while (currNode && currIndex < id) {
			currNode = currNode->next;
			currIndex++;
		}
		
		
		if (currNode->item.quantity == 0)
			return true;
		else
			return false;
	}
	
	bool quantityCheck(int id, int qty){
		if (front == NULL)
			return true;
		
		ItemNode* currNode = front;
		int currIndex = 1;
		
		while (currNode && currIndex < id) {
			currNode = currNode->next;
			currIndex++;
		}
		
		
		if (currNode->item.quantity < qty)
			return true;
		else
			return false;
	}

	bool display() {
		if (front == NULL) {
			cout << "Vending Machine is empty" << endl;
			return false;
		}

		cout<<left<<setw(10) << "ID" << setw(10) << "|" << setw(20) << "Name" << setw(10) << "|" << setw(10) << "Price" << setw(10) << "|" << setw(10) << "Quantity" << endl;
		ItemNode* currNode = front;
		int index = 1;
		while (currNode != NULL) {
			cout<<setw(10)<<index << setw(10) << "|" << setw(20) << currNode->item.name << setw(10) << "|"  << setw(10) << currNode->item.price << setw(10) << "|"  << setw(10) << currNode->item.quantity << endl;
			currNode = currNode->next;
			index++;
		}
		return true;
	}
};



int main() {
	Item purchases[100];		//store the bill here
	int purchaseQuantity = 0;	//number of orders that customer has made
	VendingMachine VM;
	int choice = 1;
	
	// Hard coding the values of items
	// initializing the arrays for each values i.e. item name, item price, item qty
	int number = 10;
	string itm_name[number] = {"Chocolates", "Lays", "Kurkure", "Pepsi", "Dew", "Red Bull", "KitKat", "Sooper", "Tuc", "Butter Crunch"};
	int price_item[number] = {20, 30, 40, 60, 60, 200, 80, 25, 25, 25};
	int qty_item[number] = {5,5,5,5,5,5,5,5,5,5};
	
	string name;
	int price, qty;
	
	
	// storing values in class item
	for (int index = 0; index < number; index++)
	{
		name = itm_name[index];
		price = price_item[index];
		qty = qty_item[index];

		Item* newItem = new Item(name, price, qty);
		VM.insertItem(newItem);
	}
	
	cout << "------------------------- Welcome to Vending Machine--------------------------" << endl;
	VM.display(); // Displaying the list of items
	cout << endl;
	
	while (true) {
		cout << "-------- MENU --------" << endl;
		cout << "Enter 1 to Buy Item" << endl;
		cout << "Enter 2 to Show List of Items" << endl;
		cout << "Enter 3 to Display the Purchased Items" << endl;
		cout << "Enter 4 to Exit Vending Machine" << endl;
		cout << "Enter Your Choice : ";
		cin >> choice;
		cout << endl;
		
		while(cin.fail()) 
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please Enter a Numeric Value: ";
			cin >> choice;
		}

		
		switch (choice)
		{
		case 1: {
			Item* itemToPurchase = NULL;
			int id, qty;
			cout << "Which item would you like to purchase?" << endl;
			while (true) {
				cout << "Enter ID of item: ";
				cin >> id;
				if (id <= VM.numberOfItems)
					break;
				else
					cout << "Please enter a valid id" << endl;
			}
			if (VM.productAvbCheck(id)){
				cout << "Not Enough Quantity, Please try another product!" <<endl << endl;
				break;
			}
			cout << "Enter quantity: ";
			cin >> qty;
			
			if (VM.quantityCheck(id, qty)){
				cout << "Not Enough Quantity, Please try another product!" <<endl << endl;
				break;
			}
			itemToPurchase = VM.getItem(id);
			Item newItem(itemToPurchase->name, itemToPurchase->price, qty);
			purchases[purchaseQuantity++] = newItem;
			VM.decreaseQuantity(id, qty);
			cout << "Purchased Successful" << endl << endl;
			break;
		} 
		case 2: {
			VM.display();
			cout << endl;
			break;
		}
		case 3: {
			int total = 0;
			cout << left << setw(10) << "Name" << setw(10) << "|" << setw(10) << "Price" << setw(10) << "|" << setw(10) << "Quantity" << setw(10) << "|" << setw(10) << "Total for Purchase" << endl;
			for (int i = 0; i < purchaseQuantity; i++) {
				cout << setw(10) << purchases[i].name << setw(10)<< "|" << setw(10) << purchases[i].price << setw(10) << "|" << setw(10) << purchases[i].quantity << setw(10) << "|" << purchases[i].price * purchases[i].quantity << endl;
				total += purchases[i].price * purchases[i].quantity;
			}
			cout << "\nTotal Bill = " << total << endl << endl;
			break;
		}
		case 4: {
			cout << "Thank You, Have A Nice Day !!" << endl;
			exit(0);
		}
		}
	}
	return 0;
}