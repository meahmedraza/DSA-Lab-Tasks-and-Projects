#include<iostream>
using namespace std;
void print_array(int arr1[][3],int arr2[][3],int arr3[][3]);
int main()
{
	int arr1[2][3],arr2[2][3],arr3[2][3];
	cout<<"Please enter 6 numbers in array(1): "<<endl;
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
		cin>>arr1[i][j];}
	}
	cout<<"Please enter 6 numbers in array(2): "<<endl;
		for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
		cin>>arr2[i][j];}
	} 
	cout<<"Please enter 6 numbers in array(3): "<<endl;
		for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
		cin>>arr3[i][j];}
	}
	print_array(arr1,arr2,arr3);
	
return 0;
}
void print_array(int arr1[][3],int arr2[][3],int arr3[][3] )
{
		cout<<"\nValues in array1 by row are:"<<endl;
		for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
		cout<<arr1[i][j]<<" ";}
		cout<<endl;
	}
	cout<<"\nValues in array2 by row are:"<<endl;
		for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
		cout<<arr2[i][j]<<" ";}
		cout<<endl;
	}
	cout<<"\nValues in array3 by row are:"<<endl;
		for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
		cout<<arr3[i][j]<<" ";}
		cout<<endl;
	}
}
