#include<bits/stdc++.h>

using namespace std;


class complex{
int x;
int y;
public:
// default constructor
complex() :x(10),y(45){};

// parametrized constructor
complex(int a, int b):x(a), y(b){};

// copy constructor
complex(const complex &rhsObj){
    x = rhsObj.x;
    y = rhsObj.y;
}

// + operator overloading
complex operator + (const complex &obj){
    complex res;
    res.x = x + obj.x;
    res.y = y + obj.y;
    return res;
}

// = operator overloading
complex& operator = (const complex &obj) {
    // assign source object values to destination obj
    x = obj.x;
    y = obj.y;
    return *this;
}
};