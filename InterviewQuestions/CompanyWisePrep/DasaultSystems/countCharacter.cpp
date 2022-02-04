/*
There could be two possible way to solve this:
    1. We can use bruteforce by iterating over string in nested way
    2. use hashing to store the count
*/

#include<bits/stdc++.h>


using namespace std;

int main()
{
    string s = "geeksforgeeks";
    unordered_map<char, int> d;

    for (char i : s)
    {
        d[i]++;
    }

    for (char i : s)
    {
        if (d[i] != 0)
        {
            cout << i << " " << d[i] << endl;
            d[i] = 0;
        }
    }
    return 0;
}