#include<bits/stdc++.h>
using namespace std;

int myatoi(char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        res = res * 10 +  (str[i] - '0'); 
    }
    return res;
}

int main()
{
    char input[] = "45678";
    cout << myatoi(input) << endl;
    return 0;
}