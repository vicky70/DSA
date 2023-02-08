#include "singly_linklist.cpp"
#include<iostream>
using namespace std;

class Stack_Linklist:private SLL{
    public:
        Stack_Linklist();
        void push(int );
        int peek();
        void pop();
        void reverseStack();
        // int stackEmpty();
        ~Stack_Linklist();
};
Stack_Linklist::Stack_Linklist():SLL(){ }
Stack_Linklist::~Stack_Linklist(){ }

// int Stack_Linklist::stackEmpty(){
//     if (retFirst()==-1)
//         return 1;
//     else{
        
//     }
// }
void Stack_Linklist::push(int data){
    insertAtBegnning(data);
}
int Stack_Linklist::peek(){
    return retFirst();
}
void Stack_Linklist::pop(){
    delFirstNode();
}
void Stack_Linklist::reverseStack(){
    cout<<"Inside reverseStack funtion:"<<endl;
    reverseSt();
    cout<<"Function is ending :"<<endl;
}

int main(){
    cout<<"Inside main function\n";
    Stack_Linklist s3, s4;
    s3.push(10);
    s3.push(20);
    s3.push(30);
    s3.push(40);
    s3.push(50);

    s4.push(100);
    s4.push(200);
    s4.push(300);
    s4.push(400);
    s4.push(500);
    cout<<"All the Data is pushed in stack\n";
    cout<<s3.peek()<<endl;
    cout<<"Calling reverseStack functrion:"<<endl;

    s3.reverseStack();
    s4.reverseStack();
    cout<<s3.peek()<<endl;
    cout<<s4.peek()<<endl;
    s3.pop();
    s4.pop();
    cout<<s3.peek()<<endl;
    cout<<s4.peek()<<endl;
    return 0;
}
