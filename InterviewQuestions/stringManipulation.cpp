#include<iostream>

using namespace std;


char* remSpclChar(char *str)
{
    char *tmpStr = (char*)malloc(sizeof(10)); // here the memory is allocated in heap so we can return the point to memory address
    int j = 0;
    for (int i = 0 ; str[i]!='\0'; i++)
    {
        if ((str[i] > 48 && str[i] <= 57) ||
            (str[i] > 65 && str[i] <= 91) || 
            (str[i] > 97 && str[i] <= 123))
            {
                tmpStr[j++] = str[i] ;
            }
    }
    tmpStr[j] = '\0';
    return tmpStr;
}


void removeSpclChar( char *str)
{
    int j = 0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        if ((str[i] > 48 && str[i] <= 57) ||
            (str[i] > 65 && str[i] <= 91) || 
            (str[i] > 97 && str[i] <= 123))
            {
                str[j++] = str[i] ;
            }
    }
    str[j] = '\0';
    // even though we are passing input string as pass by value, still it prints updated input in main(), because this is how array passing works, pass by reference
}


// This is method is do the same job as above meth
// void removeSpclChar( char str[])
// {
//     int j = 0;
//     for (int i = 0; str[i]!='\0'; i++)
//     {
//         if ((str[i] > 48 && str[i] <= 57) ||
//             (str[i] > 65 && str[i] <= 91) || 
//             (str[i] > 97 && str[i] <= 123))
//             {
//                 str[j++] = str[i] ;
//             }
//     }
//     str[j] = '\0';
//     // even though we are passing input string as pass by value, still it prints updated input in main(), because this is how array passing works, pass by reference
// }

int main()
{
    char input[] =  "Hi@123";
    cout << "Hi I am a bot.. give me an input" << endl;
    //cin >> input;
    cout << sizeof(input) << endl;

    removeSpclChar(input);

    cout << input;

    cout << remSpclChar(input);
}