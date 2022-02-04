/*
Always remember: A user-defined copy constructor is generally needed when an object owns pointers or non-shareable 
references, such as to a file, in which case a destructor and an assignment operator should also be written
*/

#include<iostream>

using namespace std;

class complex {

public:
complex(): real(nullptr), img(nullptr){} //default constructor
complex(int *real, int *img);   // parametrized constructor
~complex(); // destructor
complex( const complex &obj);   // copy constructor
complex(complex &&obj) noexcept;    // move constructor
complex& operator = (const complex &obj);   // copy assignment
complex& operator = (complex &&obj);    // move assignment

public:
    int *real;
    int *img;
};

//constructor
complex::complex(int *real , int *img)
: real(real)
, img(img)
{
    cout << "constructor called \n"; 
}

// destructor
complex::~complex()
{
    cout << "destructor called\n";
}

// copy constructor
complex::complex( const complex &obj)
{
    // shallow copy
    // real = obj.real;
    // img = obj.img;

    // deep copy
    cout << "copy constructor called \n";
    real = obj.real;
    img = obj.img;
    cout << "hello";
}

// copy assignment operator
complex& complex::operator = (const complex &obj)
{
    cout << "copy assignment operator called \n";
    // shallow assignment 
    // real = obj.real;
    // img = obj.img;

    // deep assignment
    *real = *obj.real;
    *img = *obj.img;
    return *this;
}

// move constructor
complex::complex(complex &&obj) noexcept
: real(std::move(obj.real))
, img(std::move(obj.img))
{
} 


int main()
{
    int x =3;
    int y =5;
    int *px = &x;
    int *py = &y;

    int *ppx = new int(7);
    int *ppy = new int(6);

    complex b(px, py);
    complex d = complex(ppx, ppy);

    cout << *b.real << "+  i" << *b.img;

    cout << endl;

    cout << *d.real << "+  i" << *d.img << endl;

    b = d; // copy assignment will be called

    cout << "testing copy construcotr\n";
    complex e = d; // copy constructor will be called

    cout << *b.real << "+  i" << *b.img << endl;

    cout << *b.real << "+  i" << *b.img << endl;

    return 0;
}