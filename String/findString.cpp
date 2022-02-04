#include<iostream>

using namespace std;
int length(char *str)
{
    int i = 0;
    while(str[i]!='\0')
    {
       i++; 
    }
    return i;
}

int find_string(char *str1, char *str2)
{
    int k = 0, c = 0;
    for (int i = 0 ; str1[i]!='\0'; i++)
    {
        if(str1[i] == str2[k])
        {
            k++;
        }
        else
        {
            k = 0;
        }
        if (k == length(str2))
        {
            c++;
            k = 0;
        }
    }
    return c;
}

int main()
{
    char str1[] = "ajayjaykjaya";
    char str2[] = "jay";
    cout << find_string(str1, str2) ;

    return 0;
}