/*
    In question 1, define a method to find an element in the array.
    returning index if the element found, otherwise return -1.
*/


#include<iostream>
using namespace std;
class Array{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int );
        bool arrEmpty();
        void append(int );
        void insert(int , int );
        void del(int );
        bool arrFull();
        int getElement(int );
        int count();
        int find(int);
        ~Array();
};
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
        cout<<"{]{#{]{ ERROR Illegal memory access:"<<endl;
    }
}
void Array::insert(int x, int indexNum){
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
int main(){
    Array arr(5);
    arr.append(34);
    arr.append(45);
    arr.append(76);
    arr.append(37);
    arr.insert(67, 2);
    arr.del(2);
    // cout<<arr.arrFull()<<endl;
    cout<<arr.getElement(3)<<endl;
    return 0;
}