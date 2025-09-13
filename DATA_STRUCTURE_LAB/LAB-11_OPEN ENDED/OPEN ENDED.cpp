#include <iostream> 
#include <string.h> 
#include <stdlib.h>

using namespace std; 

class Stack 
{ 
public:
    int top; 
    int capacity; 
    int* array; 
}; 


class Stack* createStack( int capacity) 
{ 

    class Stack* stack = new Stack; 
    if (!stack)
	return NULL; 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if (!stack->array)
	return NULL; 

    return stack; 
} 
 

int isEmpty(class Stack* stack) 
{ 

    return stack->top == -1 ; 
} 
 

char peek(class Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 
 

char pop(class Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 

    return '$'; 
} 
 

void push(class Stack* stack, char op) 
{ 
    stack->array[++(stack->top)] = op;

} 


int evaluatePostfix(char* exp) 
{
    class Stack* stack = createStack(strlen(exp)); 
    int i;
    if (!stack)
	return -1;
    for (i = 0; exp[i]; ++i) 
    { 
    
        if (isdigit(exp[i]))   
            push(stack, exp[i]- '0'); 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack);

            switch (exp[i]) 
            { 
	            case '+':
				cout<<"Sum of value(1) "<<val1<<" and value(2) "<<val2<<" is: "<<val2+val1<<endl;
				push(stack, val2 + val1);
				break; 
	            case '-':
				cout<<"Subtraction of value(1) "<<val1<<" and value(2) "<<val2<<" is: "<<val2-val1<<endl;
				push(stack, val2 - val1);
				break; 
	            case '*':
				cout<<"Multiplication of value(1) "<<val1<<" and value(2) "<<val2<<" is: "<<val2*val1<<endl;
				push(stack, val2 * val1);
				break; 
	            case '/':
				cout<<"Division of value(1) "<<val1<<" and value(2) "<<val2<<" is: "<<val2/val1<<endl;
				push(stack, val2/val1);
				break; 
            } 
        } 
    } 
    return pop(stack); 
} 
 

int main() 
{ 
	char exp[10];
	cout<<"Enter any numbers with operation/s to perform: \n";
	for(int i=0; i<10; i++)
	cin>>exp[i];
	cout<<"Input is: (";
	for(int i=0; i<10; i++)
	cout<<exp[i]<<",";
	cout<<")"<<endl;
	cout<<"postfix evaluation: "<< evaluatePostfix(exp); 
	    
    return 0; 
}


