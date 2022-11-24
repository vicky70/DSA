#include<iostream>
using namespace std;

struct node{
        int data;
        node *next;
};

class SLL{
    private:
        node *start;
    public:
        SLL();
        void insertAtBegnning(int );
        void insertAtLast(int );
        int search(int );
        void insertInBetween(int , int);
        void delFirstNode();
        void delLastNode();
        void deleteInBetween(int );
        ~SLL();
        void display(){
            node *t=start;
            while(t!=NULL)
            {
                cout<<t->data<<" ";
                t=t->next;
            }
        }
};

SLL::SLL(){
    start=NULL;
}
void SLL::insertAtBegnning(int value){  //Insert at begnning:
    node *temp = new node;
    temp->data = value;
    if (!start)   // if linkList is Empty:
    {
        temp->next = NULL;
        start = temp;
    }
    else{       // if listList is not Empty:
        temp->next = start;
        start = temp;
    }
}
void SLL::insertAtLast(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (!start)     //  when List is Empty:
        insertAtBegnning(value);
    else{       //  when List is not Empty:
        node *t = start;
        while (t->next != NULL)     // Finding Last Node of List:
            t = t->next;
        t->next = temp;     // Adding New node at the end of List. Because pointer 't' is holding address of last node:
    }
}
int SLL::search(int value){
    int count=1;
    if (!start){
        return 0;
    }
    else{
        node *temp = start;
        while (temp != NULL)
            if (temp->data == value)
                return count;
            else{
                count++;
                temp = temp->next;
            }    
    }
    return -1;
}
void SLL::insertInBetween(int index, int value){
    int count=1;
    if (!start)     // If list is Empty.
        insertAtBegnning(value);    //Inserting New node at First position.
    else{
        node *t = start;
        /*  Finding position where user wants to insert new node.

          ----> If the given position is vaild then while-loop will end by the 'break' keyword.
                If loop is ended by 'break' keyword then pointer 't' will be pointing to the position
                where user want to insert new node.

            Otherwise while-loop will end when 't' pointer have 'NULL' value.
            If pointer 't' have 'NULL' then given Index is not valid and We are Inserting New node at last place.
        */ 
        while (t!=NULL)   
        {
            count++;
            if (count==index)
                break;
            else
                t=t->next;
        }
        /*Inserting new Node at spacified position*/
        if (t!=NULL)
        {
            node *temp = new node;
            temp->data=value;
            temp->next=t->next;
            t->next=temp;
        }
        /*Inserting at last position.
          when spacified position is Invalid.
        */
        else{
            cout<<"Given Index is out of range: \n Inserting New Node at Last:";
            insertAtLast(value);
        }
    }
}
void SLL::delFirstNode(){
    if (start == NULL)      // If list is Empty
        cout<<"List is Empty cann't delete";
    else{
        node *temp=start;
        start = temp->next;
        delete temp;
    }
}
void SLL::delLastNode(){
    if (!start)     // Checking list is Empty Or not.
        cout<<"List is Empty:";
    else{       
        node *t = start;
        if (t->next == NULL)    // If list have only one node.
        {
            start=NULL;
            delete t;
        }
        else{
            while (t->next->next !=NULL)    //Finding Last node.
                t=t->next;
            node *L=t->next;    // For deleting the last node.
            t->next=NULL;       // assigning null to just previous node of last node.
            delete L;       // Deleting last node.
        }
    }
}
void SLL::deleteInBetween(int index){
    int count=1;
    if (!start)     // If List is Empty:
        cout<<"List is Empty cann't delete:";
    else{
        node *t = start;
        while (t!=NULL)     //Find position where user wants to delete:
        {
            count++;
            if (count==index)   //If position is founded. Deleting Node.
            {
                node *Ex = t->next;
                t->next = Ex->next;
                delete Ex;
                break;
            }
            else
                t=t->next;  // Checking next node.
        }
        if (t==NULL)    // If Given Index is Invaild.
            cout<<"Invalid Index:\nCan't Delete:";
    }
}
SLL::~SLL(){
    node *t=start;
    while (t!=NULL)
    {
       t=t->next;
       delete start;
       start=t;
    }
}