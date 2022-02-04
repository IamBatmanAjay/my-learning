#include<iostream>
using namespace std;

bool isCyclic(string str1, string str2)
{
    if (str1.length() != str2.length()) return false;
    string tmp = str1 + str1;
    return (tmp.find(str2) !=string::npos);
}

int main()
{
    string str1 = "AJAY";
    string str2 = "JAYD";
    isCyclic(str1, str2) ? cout << "It is a cyclic string. \n" : cout << "Not a cyclic string \n";
    return 0;
}