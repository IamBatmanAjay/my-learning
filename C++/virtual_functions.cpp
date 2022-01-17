// TOPIC: Introduction To Virtual Function

// NOTES:
// 1. WHY to use virtual function?
//    a. To achieve dynamic polymorphism. Which is the ability to call Derived class function using Base class pointer or reference.

// 2. HOW to use virtual function?
//    a. By declaring function as virtual in Base class and overriding that function in Derived class.
//       (Function signature should be same in Base and Dervied class)
//    b. Declaring a function as virtual in Base class is enough, Derived class function need not to be declared virtual.
//    c. Virtual functions should be accessed using pointer(*) or reference(&) of Base class type to achieve run time polymorphism.

// ADITIONAL NOTES:
// 1. Virtual functions cannot be static and also cannot be a friend function of another class.
// 2. A class can have virtual destructor but can't have virtual constructor.
// 3. There are two types of virtual functions in C++.
//    a. Virtual Function
//    b. Pure Virtual Function
// 4. A pure virtual function is a virtual function in C++ for which we need not to write any function definition and only we have to declare it. 
//    It is declared by assigning 0 in the declaration.
//     a. An abstract class is a class in C++ which have at least one pure virtual function.
//     b. Abstract class can have normal functions and variables along with a pure virtual function.
//     c. Abstract class cannot be instantiated, but pointers and references of Abstract class type can be created.
//     d. Abstract classes are mainly used for Upcasting, so that its derived classes can use its interface.
//     e. If an Abstract Class has derived class, they must implement all pure virtual functions, or else they will become Abstract too.
//     f. We can’t create object of abstract class as we reserve a slot for a pure virtual function in Vtable, but we don’t put any address, so Vtable will remain incomplete.

#include <iostream>
using namespace std;

class Animal {
public: 
    virtual void eat() = 0;
};

class Cat : public Animal {
public:
    void eat() {
        cout << "Eating Non-veg" << endl;
    }
};

class Cow : public Animal {
public:
    void eat() {
        cout << "Eating Veg" << endl;
    }
};

int main() {
    Animal *a = new Cat();
    a->eat();
    return 0;
}
