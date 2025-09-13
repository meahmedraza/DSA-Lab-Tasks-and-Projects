#include <iostream>
#include <conio.h>
const int size=10;
using namespace std;
class queue
{
private:
int array[size];
int first,last,count;
public:
queue();
void insert(int,int);
int remove();
int print(int);
};
queue:: queue()
{
first=0;
last=-1;
count=0;
}
//FOR INSERT
void queue::insert(int value,int num)
{
if(count>=num)
{
cout<<"Queue is full\n";
return;
}
if(last>=num-1)
{
last=-1;
}
array[++last]=value;
count++;
}
//FOR REMOVE
int queue::remove()
{
if(count<0)
{
cout<<"Queue is empty\n";
return NULL;
}

if(first>count)
{
first=0;
}
count--;
first++;

return array[first++];

}
//
//int queue::remove(int num)
//{
//if(count<=0)
//{
//cout<<"Queue is empty\n";
//return NULL;
//}
//if(first>=num)
//{
//first=0;
//}
//count--;
//}

//For Printing
int queue::print(int num)
{

if(first>num)
{
first=0;
}
for(int i=0; i<=num; i++)
{
cout<<"Number at index "<<i<<" is: "<<array[first++]<<endl;
}
}

int main()
{
queue q;
int num,value;
char ans;
cout<<"How many times you want to insert number: ";
cin>>num;
cout<<"Enter "<<num<<" number \n";
for(int i=0; i<num; i++)
{
	cin>>value;
	q.insert(value,num);
}
do
{
	cout<<"Do you want to remove number Y|N : ";
	cin>>ans;
}
while(ans=='Y' || ans=='y');
{
	q.remove();
	--num;
}

if(ans=='N'||ans=='n')
	{
	q.print(num);	
	}


return 0;
}
