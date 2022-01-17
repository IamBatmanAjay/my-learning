// What are VTABLE and VPTR? 
// the vtable is a table of function pointers. It is maintained per class. 
// vptr is a pointer to vtable. It is maintained per object (See this for an example). 
// The compiler adds additional code at two places to maintain and use vtable and vptr. 
// 1) Code in every constructor. This code sets vptr of the object being created. This code sets vptr to point to vtable of the class. 
// 2) Code with polymorphic function call (e.g. bp->show() in above code). Wherever a polymorphic call is made, 
// the compiler inserts code to first look for vptr using a base class pointer or reference (In the above example, 
// since the pointed or referred object is of the derived type, vptr of a derived class is accessed). 
// Once vptr is fetched, vtable of derived class can be accessed. Using vtable, the address of the derived class 
// function show() is accessed and called.

#include<bits/stdc++.h>

using namespace std;

class A {
    public:
        A(){}
        ~A(){}
        int get(){return 1;}
    private:
};

class B : public A{
public:
    B(){}
    ~B(){}
    int get(){return 2;}
};


int main()
{
    A *a = new B();
    cout << a->get() << endl;
    return 0;
}