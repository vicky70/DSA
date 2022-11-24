#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
};

class DLL{
    private:
        node *start;
    public:
        DLL();
        void insertAtBeginning(int);
        void insertAtLast(int);
        int search(int);
        void insertInBetween(int ,int);
        void delFirstNode();
        void delLastNode();
        void delINBetween(int );
        ~DLL();
        void display(){
            node *t=start;
            while (t!=NULL)
            {
                cout<<t->data<<" \n";
                t=t->next;
            }
        }
};

DLL::~DLL(){
    node *t=start;
    while (t->next!=NULL){
        t = t->next;
        delete t->next->prev;
    }
    delete t;
}
void DLL::delINBetween(int index){
    
    int count=1;
    if (!start)     // If List is Empty:
        cout<<"List is Empty cann't delete:";
    else{
        node *t = start;
        while (t!=NULL)     //Finding position where user wants to delete:
        {
            count++;
            if (count==index)   //If position is founded. Deleting Node.
            {
                node *Ex = t->next;     //Ex pointer will contain address node that is being deleted....
                t->next = Ex->next;     // Now t pointer will point to the next of deleted node.... 
                if (t->next==NULL){     //Condition when user given last Index to delete... 
                    delete Ex;          // deleting last node..
                    break;          // breaking loop;
                }
                else{
                    Ex->next->prev=t;       
                    break;
                }
            }
            else
                t=t->next;  // Checking next node.
        }
        if (t==NULL)    // If Given Index is Invaild.
            cout<<"Invalid Index:\nCan't Delete:";
    }
}
void DLL::delLastNode(){
    if (!start)     // If List is empty...
        cout<<"List is Empty \n Can't Delete:";
    else{
        node *t=start;
        while (t->next!=NULL)   // finding Last node...
            t=t->next;
        t->prev->next=NULL; // Assigning NULL to the previous node of last node;
        delete t;       //Deleting Last Node;
    }
}
void DLL::delFirstNode(){
    if(!start)      // List is Empty...
        cout<<"List is Empty...";
    else{
        node *t=start;  
        start=t->next;      //start will point next node of the first node...
        if (t->next==NULL)  // If List have only one node...
            delete t;       // deleting node...
        else{
            start->prev=NULL;   //Assigning NUll in prev feild of second node of the list...
            delete t;       // deleting first node...
        }
    }
}
void DLL::insertInBetween(int Index, int value){
    if (!start)         //If List is Empty...
        cout<<"List is Empty:\n Can't insert at given position... ";
    else{
        int count=1;    // Counting Number of position... 
        node *t=start;      // t pointer to point different nodes...
        while (t!=NULL)     // Untill t have not NULL value...
        {
            count++;        //Increasing count value...
            if (count == Index) // Checking If given position equal or not...
            {
                node *temp= new node;   // Creating new node...
                temp->data=value;       // Adding value in New node...
                temp->next=t->next;     // From here New node will start pointing to next node of given position....
                temp->prev=t;           // from here New Node will start pointing to the Previous Node of given position...
                if (t->next != NULL)
                    temp->next->prev=temp;  // from here the next node of given position will start pointing to the New node... 
                t->next=temp;           // And from here the Prevous node of given position will start pointing to the new Node...
                break;          // Braking Loop;
            }
            else
                t=t->next;      // Going to next node...
        }
        if (t == NULL)  // If position is out of bound...
        {
            cout<<"Given position is out of bound \nInserting at Last:\n";
            insertAtLast(value);    //Inserting new node at last...
        }
    }
}
int DLL::search(int value){
    if (!start)     // If List is Empty...
        cout<<"Can't search Link-List is Empty:\n";
    else{
        node *t = start;
        while (t!=NULL)     //Traversing Nodes...
            if (t->data == value)       //Comparing every node(data feild) with given value...
                return 1;               //If value is Matched then returning 1;
            else
                t=t->next;          // Otherwise going to next node...
    }
    return 0;   // If value is Not Founded in Link-List...
}
void DLL::insertAtLast(int value){
    if (!start)         //If List is Empty...
        insertAtBeginning(value);   // New Inserting at Beginning...
    else{
        node *t = start;        // A pointer to point Last node...
        while (t->next!=NULL)   // Finding new Node...
            t = t->next;
        node *temp = new node;  // Creating new Node....
        temp->data = value;     // Assigning value in data feild of new node....
        temp->next=NULL;        // Assinging NULL in next pointer feild of new node...
        temp->prev=t;           // From here new will start pointing Link-List....
        t->next=temp;           // From here Link-list will start pointing new node...
    }
    
}
void DLL::insertAtBeginning(int value){
    node *temp = new node;      //Creating new Node...
    temp->data = value;         // Adding value in New node...
    temp->prev=NULL;            // Assignning NULL to the prev pointer in first node...
    if (!start)                 // If List is Empty...
    {
       temp->next=start;        // Assignning NULL to the next pointer of the new Node...
       start=temp;              // Now start will point to new node...(if List is empty...)
    }
    else{
        temp->next = start;     // From here new Node will point to Link-List...
        start->prev=temp;       // From here Link-List will point to the new Node...
        start = temp;           // Now start pointer will point to the new Node...(If Link-List is not empty...)
    }
}
DLL::DLL(){
    start=NULL;
}

int main(){
    DLL d1;
    d1.insertAtBeginning(20);
    d1.insertAtBeginning(10);
    d1.insertAtLast(30);
    // cout<<"Node founded:"<<d1.search(20)<<"\n";
    d1.insertInBetween(7, 40);
    d1.delINBetween(3);
    d1.display();
    return 0;
}