#include<bits/stdc++.h>
using namespace std;

std::vector<char>comSequence;

int max(int a , int b)
{
    return a > b? a : b;
}

int lcs(char *str1, char *str2, int m, int n )
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    
    else if (str1[m-1] == str2[n-1])
    {
        comSequence.push_back(str1[m-1]);
        return  1 + lcs(str1, str2, m-1, n-1);
    }

    else 
    {
        return max(lcs(str1, str2, m-1, n), lcs(str1, str2, m , n-1));
    }
}

int main()
{
    char str1[] = "ajayyadav";
    char str2[] = "shilpayadav";
    int m = strlen(str1);
    int n = strlen(str2);
    cout << "Length of Longest common subsequence is : " << lcs(str1, str2, m, n) << endl;
    cout << "Longest common subsequence is : ";

    while(!comSequence.empty())
    {
        cout << comSequence.back();
        comSequence.pop_back();
    }
    cout << endl;
    return 0;
}