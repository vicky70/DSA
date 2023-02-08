#include<iostream>
/*
    Adding Array Data structure to Impelement Stack Data Structure 
*/
#include"Array.cpp"
using namespace std;

// Stack Class
// Inherting Array Class in Stack Class with private access specifier...
class Stack:private Array{  
    public:
        Stack(int );  // Stack parameterized Construtor.
        Stack(Stack &); // Stack Copy Construtor.
        // Some Stack Member Function.
        void push(int );
        int peek();
        void pop();
        bool checkOverFlow();
        bool checkUnderFlow();
        void reverseStack();
        int getStackSize();
        // Operator '=' Overloading...
        void operator=(Stack );
        // Stack Destrutor...
        ~Stack();
};

// Copy Construtor Defination...
/* 
    Calling Array Copy Construtor...
*/
Stack::Stack(Stack &cp):Array(cp){ }

// Defination of Operator'=' Overloading... 
void Stack::operator=(Stack st){ // Creating 'st' Stack object.. And Calling Stack Copy Construtor here Stack Copy Construtor will be called Automatically...
    int value;
    for (int i = 0; i <= st.getStackSize()-1; i++){
        value = st.getElement(i);
        this->push(value);
    }
}
// Return stack Size...
int Stack::getStackSize(){
    return count()+1;
}
// Reverse Stack Function Defination...
void Stack::reverseStack(){
    Stack s6(this->getStackSize());
    while (!this->arrEmpty())
    {
        s6.push(this->peek());
        this->pop();
    }
    this->operator=(s6);
}
// Checking Underflow Condition...
bool Stack::checkUnderFlow(){
    return arrEmpty();
}
// Checking Overflow Condition...
bool Stack::checkOverFlow(){
    return arrFull();
}
// Stack Destructor Defination...
Stack::~Stack(){ };
void Stack::pop(){
    if (arrEmpty())
        cout<<"Stack UnderFlow: ";
    else
        del(count());
}
// Defination of peek Funtion...
int Stack::peek(){
    if (!arrEmpty())
        return getElement(count());
    return 0;
}
// defination of push Function...
void Stack::push(int data){
    if (arrFull())
        cout<<"Overflow Condition: ";
    else
        append(data);
}
int minValueInStack(Stack s2){
    Stack s3(s2.getStackSize());
    if(s2.checkUnderFlow())
        return -99999;
    while (!s2.checkUnderFlow())
    {
        if (s3.checkUnderFlow())
            s3.push(s2.peek());
        else
            if (s3.peek() > s2.peek())
                s3.push(s2.peek());
            else
                s3.push(s3.peek());
        s2.pop();
    }
    return s3.peek();
}
// Stack Parameterized Construtor...
Stack::Stack(int size):Array(size){ };
int main(){
    Stack s1(5);
    s1.push(11);
    s1.push(23);
    s1.push(2);

    s1.reverseStack();
    cout<<s1.peek()<<endl;
    cout<<minValueInStack(s1)<<endl;
    return 0;
}