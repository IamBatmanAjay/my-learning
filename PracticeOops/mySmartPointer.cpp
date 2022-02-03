#include<iostream>
using namespace std;

template<typename T>
class mySmartPtr{
    T *ptr;
    public:
    // default constructor
    mySmartPtr():ptr(nullptr){}

    //my constructor
    mySmartPtr(T *ptr):ptr(ptr){}

    // override destrucutor
    ~mySmartPtr(){
        delete ptr;
        cout << "Destructor called ..." << endl;
        ptr = NULL;
    }

    // overload *operator
    T& operator * (){
        return *ptr;
    }
};

int main()
{
    mySmartPtr<int>intptr(new int(10));
    cout << *intptr << endl;
    *intptr = 11;
    cout << *intptr << endl;
}
