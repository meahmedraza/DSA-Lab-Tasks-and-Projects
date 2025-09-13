#include <iostream>
using namespace std;
int recursiveLinearSearch(int arr[],int num,int nsize);
void display(int arr[],int nsize);
int main()
{ 
int num, nsize;
cout<<"Enter the size of array: ";
cin>>nsize;
int arr[nsize];
for(int i=0; i<nsize; i++)
{
	cout<<"Enter number at index arr["<<i<<"] ";
	cin>>arr[i];
	cout<<endl;
}
display(arr, nsize); 
cout << "Enter the number you want to find: "; 
cin >> num; 
 cout << "Item is found at location " <<recursiveLinearSearch(arr,num,nsize)<< endl; 
return 0; 
}
// Recursive 
int recursiveLinearSearch(int arr[],int num,int nsize)
{ 
nsize=nsize-1; 
 
if(nsize<0)
{ 
 return -1; 
} 
 else if(arr[nsize]==num){ 
 return nsize+1;
}
else { 
 return recursiveLinearSearch(arr,num,nsize); 
} 
} 
// Display 
void display(int arr[],int nsize)
{ 
for(int i=0;i<nsize;i++){ 
 cout<<arr[i]<<","; 
} 
cout<<"\b \b"<<endl; 
} 
