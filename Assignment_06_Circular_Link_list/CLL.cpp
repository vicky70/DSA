#include<iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};

class CLL{
    private:
        node *last;
    public:
        CLL();
        void insertAtBegnning(int );
        void insertAtLast(int );
        node* search(int );
        void insertInBetween(node*, int );
        void deleteFirstNode();
        void deleteLastNode();
        void deleteNode(node *);
        ~CLL();
};
CLL::~CLL(){
    node *t=last->next;
    while (t != last)
    {
        t=last->next;
        last->next=t->next;
        delete t;
    }
}
void CLL::deleteNode(node *t){
    if (last)
    {
        if (last == t)
        {
            delete t;
            last=NULL;
        }
        else{
            node *i=last->next;
            while (i->next!=t)
                t=t->next;
            i->next=t->next;
            delete t;
        }
    }
    else{
        cout<<"Can't delete:";
    }
}
void CLL::deleteLastNode(){
    if (last)
    {
        node *t=last->next;
        if (t == last)
        {
            delete last;
            last=NULL;
        }
        while (t->next!=last)
            t=t->next;
        t->next=last->next;
        delete last;
        last=t;
    }
    else{
        cout<<"Can't delete:";
    } 
}
void CLL::deleteFirstNode(){
    if (last)
    {
        if (last == last->next)
        {
            delete last;
            last=NULL;
        }
        else{
            node *t=last->next;
            last->next=t->next;
            delete t;
        }
    }
    else
        cout<<"Can't delete:";
}
void CLL::insertInBetween(node *t, int value){
    if (last)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=t->next;
        t->next=temp;
    }else{
        cout<<"Invalid Address:";
    }
}
node* CLL::search(int value){
    if (last)
    {
        node *t=last->next;
        do
        {
            if (t->data == value)
                return t;
            else
                t=t->next;
        } while (t!=last->next);
        return NULL;
    }
    return NULL;
}
void CLL::insertAtLast(int value){
    if (last)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=last->next;
        last->next=temp;
    }
    else
        insertAtBegnning(value);
}
void CLL::insertAtBegnning(int value){
    node *temp = new node;
    temp->data=value;
    if (last)
    {
        temp->next=last->next;
        last->next=temp;
    }
    else{
        temp->next=temp;
        last=temp;
    }
}
CLL::CLL(){
    last=NULL;
}