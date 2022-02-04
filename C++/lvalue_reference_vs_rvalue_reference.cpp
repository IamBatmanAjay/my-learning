/*
“l-value” refers to a memory location that identifies an object. “r-value” refers to the data value that is 
stored at some address in memory. References in C++ are nothing but the alternative to the already existing 
variable. They are declared using the ‘&’ before the name of the variable.

Example: 

int a = 10;

// Declaring lvalue reference
int& lref = a;

// Declaring rvalue reference
int&& rref = 20;


References for the values can also be declared which is called r-value references.

rvalue references have two properties that are useful: 
    rvalue references extend the lifespan of the temporary object to which they are assigned.
    Non-const rvalue references allow you to modify the rvalue.

Important: lvalue references can be assigned with the rvalues but rvalue references cannot be assigned to the lvalue. 

Uses of the lvalue references: 
    lvalue references can be used to alias an existing object.
    They can also be used to implement pass-by-reference semantics.

Uses of rvalue references: 
    They are used in working with the move constructor and move assignment.
    cannot bind non-const lvalue reference of type ‘int&‘ to an rvalue of type ‘int’.
    cannot bind rvalue references of type ‘int&&‘ to lvalue of type ‘int’.
*/

// C++ program to illustrate the
// lvalue and rvalue
#include <iostream>
using namespace std;

// Driver Code
int main()
{
	int a = 10;

	// Declaring lvalue reference
	// (i.e variable a)
	int& lref = a;

	// Declaring rvalue reference
	int&& rref = 20;

	// Print the values
	cout << "lref = " << lref << endl;
	cout << "rref = " << rref << endl;

	// Value of both a
	// and lref is changed
	lref = 30;

	// Value of rref is changed
	rref = 40;
	cout << "lref = " << lref << endl;
	cout << "rref = " << rref << endl;

	// This line will generate an error
	// as l-value cannot be assigned
	// to the r-value references
	// int &&ref = a;
	return 0;
}

        /*
        Output: 
        lref = 10
        rref = 20
        lref = 30
        rref = 40
        */


// // C++ program to illustrate lvalue
// #include <iostream>
// using namespace std;
 
// // lvalue reference to the lvalue
// // passed as the parameter
// void printReferenceValue(int& x)
// {
//     cout << x << endl;
// }
 
// // Driver Code
// int main()
// {
//     // Given value
//     int a{ 10 };
 
//     // Function call is made lvalue & can
//     // be assigned to lvalue reference
//     printReferenceValue(a);
//     return 0;
// }


// // C++ program to illustrate rvalue
// #include <iostream>
// using namespace std;

// // Declaring rvalue reference to the
// // rvalue passed as the parameter
// void printReferenceValue(int&& x)
// {
// 	cout << x << endl;
// }

// // Driver Code
// int main()
// {
// 	// Given value a
// 	int a{ 10 };

// 	// Works fine as the function is
// 	// called with rvalue
// 	printReferenceValue(100);
// 	return 0;
// }
