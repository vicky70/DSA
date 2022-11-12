#include<iostream>
using namespace std;
class DynArray
{
private:
   int capacity, lastIndex;
   int *ptr;
public:
    DynArray(int );
    void doubleArray();
    void halfArray();
    int SizeOfArray();
    bool isEmpty();
    void append(int );
    void insert(int , int );
    void edit(int , int);
    void del(int );
    bool isFull();
    int getElement(int );
    int count();
    int find(int );
    ~DynArray();
    void display(){
        for (int i = 0; i <= lastIndex; i++)
            cout<<ptr[i]<<" ";
    }
};
DynArray::DynArray(int size){
    ptr = new int(size);
    capacity = size;
    lastIndex = -1;
}
void DynArray::doubleArray(){
    int *temp = new int(2*capacity);
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    
    delete ptr;
    ptr = temp;
    capacity = 2*capacity;
}
void DynArray::halfArray(){
    int *temp = new int(capacity/2);
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete ptr;
    ptr = temp;
    capacity = capacity/2;
}
int DynArray::SizeOfArray(){
    return capacity;
}
bool DynArray::isEmpty(){
    return lastIndex == -1;
}
void DynArray::append(int data){
    if (lastIndex < capacity-1)
    {
        lastIndex++;
        ptr[lastIndex] = data;
    }
    else{
        doubleArray();
        lastIndex++;
        ptr[lastIndex] = data;
    }
}
void DynArray::insert(int data, int index){
    index -= 1;
    if (index >= 0 && index < capacity+1)
    {
        if (lastIndex == capacity -1)
        {
            doubleArray();
            for (int i = lastIndex; i >= index; i--) 
                ptr[i+1] = ptr[i];

            lastIndex++;
            ptr[index] = data;
        }
        else{
            for (int i = lastIndex; i >= index; i--) 
                ptr[i+1] = ptr[i];

            lastIndex++;
            ptr[index] = data;
        }
    }
    else{
        cout<<"Error: Invalid Index.";
    }
}
void DynArray::edit(int data, int index){
    ptr[index] = data;
}
void DynArray::del(int index){
    index -= 1;
    if (capacity == 1)
        if (lastIndex == -1)
            cout<<"Error: Array is Empty:";
        else
            lastIndex--;
    else if (index == lastIndex){
        lastIndex--;
        if (lastIndex+1 <= capacity/2)
            halfArray();
    }
    else if (index >= 0 && index < lastIndex)
    {
        for (int i = index; i <= lastIndex-1; i++)
            ptr[i] = ptr[i+1];
        lastIndex--;

        if (lastIndex+1 <= capacity/2)
            halfArray();
    }
    else
        cout<<"Error: Invaild Index";
}
bool DynArray::isFull(){
    return lastIndex == capacity-1;
}
int DynArray::getElement(int index){
    index -= 1;
    if (index >= 0 && index <= lastIndex)
        return ptr[index];
    else{
        cout<<"Error: Invaild Index";
        return -1;
    }
}
int DynArray::count(){
    return lastIndex+1;
}
int DynArray::find(int data){
    for (int i = 0; i <= lastIndex; i++)
        if (ptr[i] == data)
            return i+1;

    return -1;
}
DynArray::~DynArray(){
    delete[] ptr;
}

int main(){
    DynArray d1(2);
    d1.append(7);
    d1.append(9);
    d1.append(3);

    cout<<d1.getElement(3)<<endl;
    // cout<<d1.isFull()<<"\n";
    cout<<"Size of array is: "<<d1.SizeOfArray()<<endl;
    cout<<d1.count()<<endl;
    d1.display();
    return 0;
}