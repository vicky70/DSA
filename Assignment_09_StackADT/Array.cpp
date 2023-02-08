#include<iostream>
using namespace std;
class Array{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int );
        Array(Array &);
        bool arrEmpty();
        void append(int );
        void insert(int , int );
        void del(int );
        bool arrFull();
        int getElement(int );
        int count();
        int find(int);
        int getCapacity();
        ~Array();
};
Array::Array(Array &arr){
    this->capacity = arr.capacity;
    this->lastIndex = arr.lastIndex;
    this->ptr = new int[capacity];
    for (int i = 0; i < capacity; i++)
        this->ptr[i] = arr.ptr[i];
}
int Array::getCapacity(){
    return capacity;
}
Array::Array(int size){
    ptr = new int(size);
    lastIndex = -1;
    capacity = size;
}
bool Array::arrEmpty(){
    return lastIndex == -1;
}
void Array::append(int x){
    if (lastIndex < capacity)
    {
        lastIndex++;
        *(ptr + lastIndex) = x;
    }
    else{
        cout<<"{ERROR Illegal memory access:"<<endl;
    }
}
void Array::insert(int x, int indexNum){
    indexNum -=1;
    lastIndex++;
    if (indexNum > 0 && indexNum < capacity)
    {
        for (int i = lastIndex; i >= indexNum; i--)
            ptr[i] = ptr[i-1];
        ptr[indexNum] = x;
    }
    else{
        cout<<"Invalid Index:";
    } 
}
void Array::del(int index){
    for (int i = index; i < lastIndex; i++)
        ptr[i] = ptr[i+1];
    lastIndex--;
}
bool Array::arrFull(){
    return lastIndex == capacity-1;
}
int Array::getElement(int position){
    if (position >= 0 && position < capacity)
        return ptr[position];
    else
        cout<<"Invaild Index:"<<endl;
        return 0;
}
int Array::count(){
    return lastIndex;
}
int Array::find(int data){
    for (int i = 0; i <= lastIndex; i++)
        if (ptr[i] == data)
            return i+1;
    return -1;   
}
Array::~Array(){
    delete[] ptr;
}