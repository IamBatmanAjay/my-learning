#include <iostream>
#include <string>
using namespace std;


/*
Notes: string.find() returns the first index from where the word starts
string.replace(old_word_start_index, size_of_old_word, new_word);
*/

int main()
{
    string s("Your homework is bad. Really bad.");
    //cout << s.find("bad") << " " << s[17] << " " ;
   
    while (s.find("bad") != string::npos)
        s.replace(s.find("bad"), s.length(), "good");

    cout << s << endl;

    return 0;
}