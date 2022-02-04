#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n <=1) return false;

    // Trick is instead of iteration over all element we can iterate over square root of no
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0) return false;
    }

    return true;
}

int main()
{
    int count, in;
    cin >> count;
    while(count)
    {
        cin >> in;
        isPrime(in) ? cout << "Prime no.\n" : cout << "Not a prime no.\n";
        count--;
    }
    return 0;
}

// Complexity would be O(sqrt(n));