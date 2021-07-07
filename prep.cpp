#include<iostream>
using namespace std;

class Base {
int x;
public:
    Base() {}
    Base (int a ):x{a} {}
    friend void set(Base&, int);
    friend int get(Base&);
};

void set(Base& obj, int x)
{
    obj.x = x;
}

int get (Base&obj){return obj.x;}
int main(){
    Base b;
    set(b, 5);
    cout << get(b) << endl;
    return 0;
}