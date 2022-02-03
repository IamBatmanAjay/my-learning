#include<iostream>
using namespace std;


class A
{
    public:
    int func(){return 0;}
};

class B
{
    public:
    int func(){return 1;}
};


class C: public A, virtual public B 
{
    public:
    int fun1() {return 2;}
};

int main()
{
    C c;
    // func is ambiguous
    c.func();
    return 0;
}