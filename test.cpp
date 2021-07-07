#include<iostream>
using namespace std;

bool ValidateEui(uint64_t eui)
{
    cout << "|Eui is|"  << eui << endl;
    uint64_t current_eui = 0xbc33acfffe6399b7;
    // if node exists, check if either existing or joining node has last byte 0xff
    if (((eui & 0xff) == 0xff) || ( (current_eui & 0xff) == 0xff))
    {
        // check if starting 3 bytes are same
        if ((eui & 0xffffffffffffff00) == (current_eui & 0xffffffffffffff00))
        {
            cout << "|Node with bad Eui is trying to join|" << endl;
            return false;
        }
    }
	return true;
}
int main()
{
    cout << ValidateEui(0xbc33acfafe6399ff) << endl;
    return 0;
}