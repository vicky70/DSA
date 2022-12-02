#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
};

class CDLL{
    private:
        node *start;
    public:
        CDLL();
        void insertAtBeginning(int );
        void insertAtLast(int );
        node* search(int  );
        void insertInBetween(node* , int);
        void deleteAtFirst();
        void deleteLastNode();
        void deleteNode(node *);
        ~CDLL();
};
CDLL::~CDLL(){
    node *t=start->prev;    //t=3000
    if (start)
    {
        do
        {
           start=start->next;
           delete start->prev;
        }while (start!=t);
        delete start;
        start=NULL;
    }
}
void CDLL::deleteNode(node *t){
    if (start)
    {
       if (start == start->next)
       {
            delete start;
            start=NULL;
       }
       else{
            node *t = start->prev->prev;
            start->prev=t;
            t=t->next;
            t->prev->next=start;
            delete t;
        }
    }
    else
        cout<<"List is Empty:\nCan't Delete:";
}
void CDLL::deleteLastNode(){
    if (start)
    {
        if (start==start->next)
        {
            delete start;
            start=NULL;
        }
        else{
            node *t=start->prev->prev;
            start->prev=t;
            t=t->next;
            t->prev->next=start;
            delete t;
        }
    }
    else
        cout<<"List is Empty:\nCan't delete:";
    
}
void CDLL::deleteAtFirst(){
    if (start)
    {
        if (start==start->next)
        {
            delete start;
            start=NULL;
        }
        else{
            node *t=start;
            start=t->next;
            start->prev=t->prev;
            t->prev->next=start;
            delete t;
        }
    }
    else
        cout<<"List is Empty\nCan't Delete:";
}
void CDLL::insertInBetween(node *t, int value){
    if (start)
    {
        node *temp=new node;
        temp->data=value;
        temp->prev=t;
        temp->next=t->next;
        temp->next->prev=temp;
        t->next=temp;
    }
    else
        insertAtBeginning(value);
}
node* CDLL::search(int check){
    node *t=start;
    if (start)
    {
        do
        {
            if (t->data==check)
                return t;
            t=t->next;
        } while (t!=t->prev->next);
    }
    return NULL;
}
void CDLL::insertAtLast(int value){
    if (start)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=start;
        temp->prev=start->prev;
        start->prev->next=temp;
        start->prev=temp;
    }
    else
        insertAtBeginning(value);
}
void CDLL::insertAtBeginning(int value){
    node *temp=new node;
    temp->data=value;
    if (start)
    {
        temp->next=start;
        temp->prev=start->prev;
        start->prev->next=temp;
        start->prev=temp;
    }
    else{
        temp->next=temp;
        temp->prev=temp;
    }
    start=temp;
}
CDLL::CDLL(){
    start=NULL;
}