#include <iostream>
using namespace std;
  
void Merge(int array[],int const left,int const mid,int const right)
{
    int const subArrayOne=mid -left+1;
    int const subArrayTwo=right-mid;
  

    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
  

    for (int i=0; i<subArrayOne;i++)
    leftArray[i]=array[left+i];
    for (int j=0; j<subArrayTwo;j++)
    rightArray[j]=array[mid+1+j];
  
    int indexOfSubArrayOne=0;
    int indexOfSubArrayTwo=0; 
    int indexOfMergedArray=left;
  

    while (indexOfSubArrayOne<subArrayOne && indexOfSubArrayTwo<subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]<=rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]=leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]=rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]=leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]=rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void Merge(int array[],int const begin,int const end)
{
    if (begin>=end)
    return;
  
    int mid=begin+(end-begin)/2;
    Merge(array,begin,mid);
    Merge(array,mid+1,end);
    Merge(array,begin,mid,end);
}

void Show(int a[],int size)
{
    for (int i=0; i<size;i++)
    cout<<a[i]<<"\t";
}

int main()
{
	int a[]={10, 34, 33, 22, 77, 98, 2, 56, 7, 55, 56, 67, 88, 42};
	int size = sizeof(a)/sizeof(a[0]);
  
    cout << "\nThe array is\n";
    Show(a,size);
  
    Merge(a,0,size-1);
  
    cout << "\n\nSorted array is \n";
    Show(a, size);
}

