#include <iostream>
using namespace std;

int main() {
	int a[] = {0,1,0,1,0,1,0,1};
	int size = sizeof(a)/sizeof(a[0]);
	int i = 0;
	int j=size-1;
	while(i < j)
	{
    	    while((a[i] != 1) && i < j)
    	    i++;
    	    while(a[j] != 0 && i <j)
    	    j--;
    	    
    	    if (i < j)
    	    {
    	        a[i] = 0;
    	        a[j] = 1;
    	        i++;
    	        j--;
    	    }
	}
	for( int i =0 ; i <size ; i++)
	cout << a[i];
	return 0;
}
