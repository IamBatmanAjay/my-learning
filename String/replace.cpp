#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("Your homework is bad. Really bad.");

    while (s.find("bad") != string::npos)
        s.replace(s.find("bad"), 3, "good");

    cout << s << endl;

    return 0;
}