/*
The given task is to implement a class in C++ which behaves just like the Vector class.
Vectors are the same as dynamic arrays with the ability to resize themselves automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

We can also make the vector class generic using templates.
Certain functions associated with the Vector that we will implement are: 

void push(int data): This function takes one element and inserts it at the last. Amortized time complexity is O(1).
void push(int data, int index): It inserts data at the specified index. Time complexity is O(1).
int get(int index): It is used to get the element at the specified index. Time complexity is O(1).
void pop(): It deletes the last element. Time complexity is O(1).
int size(): It returns the size of the vector i.e, the number of elements in the vector. Time complexity is O(1).
int getcapacity(): It returns the capacity of the vector. Time complexity is O(1).
void print(): It is use
*/


#include"bits/stdc++.h"

using namespace std;


template<typename T>
class myVector {
T* arr;
int capacity = 1;
int counter = 0;


public:
myVector(){
    arr = new T[1];
    capacity = 1;
    counter = 0;
};
int vectorCapacity(){
 return capacity;
}

int size(){
    return counter + 1;
}

void push(T num){
    if (counter == capacity)
    {
        T* tmp = new T[2*capacity];
        for (int i = 0 ; i<counter; i++)
        {
            tmp[i] = arr[i];
        }
   
        delete [] arr;
        arr = tmp;
        capacity*=2;
    }
    arr[counter] = num;
    counter++;
}

void pop(){
    counter --;
}

void print(){
for (int i = 0 ; i <counter; i++)
{
    cout << arr[i] << " ";
}
}


T get(int idx){
return arr[idx];
}

void push(T num, int idx){
 if(idx == capacity){
     push(num);
 }
 arr[idx] = num;
}

};


int main()
{
    myVector<int>v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v.print();
    v.pop();
    v.print();
    return 0;
}