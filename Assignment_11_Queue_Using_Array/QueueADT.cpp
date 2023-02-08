#include<iostream>
using namespace std;

class QueueADT
{
private:
    int capacity, front, rear;
    int *ptr;
public:
    QueueADT(int );
    ~QueueADT();
    void insertAtRear(int );
    void deleteAtFornt();
    bool underFlow();
    bool overFlow();
    int viewRear();
    int viewFront();
    int countElement();
    void display();
};

void QueueADT::display(){
    for (int i = front; i != rear; i=(i+1)%capacity)
        cout<<endl<<ptr[i]<<" ";
    cout<<endl<<ptr[rear];
}
QueueADT::QueueADT(int value)
{
    capacity = value;
    ptr = new int[capacity];
    front=-1;
    rear=-1;
}
bool QueueADT::overFlow(){
    if ((rear+1)%capacity == front)
        return true;
    else
        return false;
}
bool QueueADT::underFlow(){
    if (front==-1 && rear == -1)
        return true;
    else
        return false;
}
void QueueADT::insertAtRear(int data){
    if (underFlow()){
        front=0;
        rear=0;
        ptr[rear]=data;
        // cout<<"10 is inserted at position"<<" "<<rear<<ptr[rear];
    }
    else if (!overFlow())
    {
        rear = (rear+1)%capacity;
        ptr[rear]=data;
        // cout<<endl<<"After 10 insertion other value will be insterted here:"<<rear<<" "<<ptr[rear];
    }
    else
        cout<<"Queue is Full Can't Insert new data in Queue:";
}
void QueueADT::deleteAtFornt(){
    if (underFlow())
        cout<<"Queue is empty Can't delete further:";
    else if (front == rear)
        front = rear= -1;
    else{
        front = (front+1)%capacity;
    }
}

int QueueADT::viewFront(){
    if (underFlow())
        return -999999;
    else
        return ptr[front];
}
int QueueADT::viewRear(){
    if (underFlow())
        return -999999;
    else
        return ptr[rear];
}
int QueueADT::countElement(){
    if (rear > front)
        return (rear+1) - front;
    else
        return -(rear - (front+1));
}

QueueADT::~QueueADT()
{
    delete []ptr;
}

int main(){
    QueueADT q1(5);
    q1.insertAtRear(10);
    q1.insertAtRear(20);
    q1.insertAtRear(50);
    q1.deleteAtFornt();
    q1.insertAtRear(60);
    q1.insertAtRear(70);
    cout<<endl<<q1.countElement();
    q1.display();
    return 0;
}
