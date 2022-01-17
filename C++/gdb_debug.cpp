#include<iostream>

using namespace std;
extern int test;
test = 10;
void function3()
{
    int function3Variable = 10;
}

void function2()
{
    int function3Variable = 10;
    function3();
}

void function1()
{
    int function1Variable = 10;
    function2();
}

int main()
{
    //cout << test;
    int mainVariable = 10;
    cout << "Here I am : " << mainVariable;
    function1();
    return 0;
}