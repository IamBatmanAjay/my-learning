#include<iostream>

using namespace std;


int factorial(int n)
{
    if(n == 1) return 1;
    return n * factorial(n-1);
}


int iterativeFactorial(int n)
{
    int result = 1;
    while(n>0)
    {
        result = result *n;
        n--;
    }
    return result;
}

int main()
{
    cout << factorial(5) << endl;
    cout << iterativeFactorial(5);
    return 0;
}