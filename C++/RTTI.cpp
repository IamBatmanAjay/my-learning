/*
In C++, RTTI (Run-time type information) is a mechanism that exposes information about an object’s data type at 4
runtime and is available only for the classes which have at least one virtual function. It allows the type of an 
object to be determined during program execution.

Runtime Casts: The runtime cast, which checks that the cast is valid, is the simplest approach to ascertain 
the runtime type of an object using a pointer or reference. This is especially beneficial when we need to 
cast a pointer from a base class to a derived type. When dealing with the inheritance hierarchy of classes, 
the casting of an object is usually required. There are two types of casting: 

    Upcasting: When a pointer or a reference of a derived class object is treated as a base class pointer.
    Downcasting: When a base class pointer or reference is converted to a derived class pointer.
    
Using dynamic_cast: In an inheritance hierarchy, it is used for downcasting of a base class pointer to a child class. 
On successful casting, it returns a pointer of the converted type and, however, it fails if we try to cast an 
invalid type such as an object pointer which is not of the type of the desired subclass.



For example, dynamic_cast uses RTTI and the following program fails with the error “cannot dynamic_cast `b’ 
(of type `class B*’) to type `class D*’ (source type is not polymorphic) ” because there is no virtual 
function in the base class B.

*/
// CPP program to illustrate
// Run Time Type Identification
// #include <iostream>
// using namespace std;
// class B {
// };
// class D : public B {
// };
  
// // Driver Code
// int main()
// {
//     B* b = new D;
//     D* d = dynamic_cast<D*>(b);
//     if (d != NULL)
//         cout << "works";
//     else
//         cout << "cannot cast B* to D*";
//     getchar();
//     return 0;
// }

// It throws error as ::
// RTTI.cpp:37:30: error: cannot dynamic_cast ‘b’ (of type ‘class B*’) to type ‘class D*’ (source type is not polymorphic)
//      D* d = dynamic_cast<D*>(b);
//Adding a virtual function to the base class B makes it work.
// CPP program to illustrate
// Run Time Type Identification
#include <iostream>
using namespace std;
class B {
    virtual void fun() {}
};
class D : public B {
    virtual void test() {}
};
  
// Driver Code
int main()
{
    B* b = new D;
    D* d = dynamic_cast<D*>(b);
    if (d != NULL)
        cout << "works";
    else
        cout << "cannot cast B* to D*";
    B *bb = dynamic_cast<B*>(d);
    if (!bb)
    {
        cout << "works";
    }
    else{
        cout << endl <<"fail";
    }
    return 0;
}