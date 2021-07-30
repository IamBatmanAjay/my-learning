
/*
Rule of three & Rule of five: It says if any these are created the all off them need to defined

Rule of three:
    Destructor
    Copy constructor
    Copy assignment operator

Rule of five(Rule of big five) post C++11
    Destructor
    Copy construcotr
    Copy assignment operator
    Move constructor
    Move assignment operator
*/

#include <iostream>

class A{};
class B: public A{
    public:
    B() {}
    B(const B&){}
    B* operator = (const B&) {
        return this;
    }
};
int main() {
    B b;
    return 0;
}