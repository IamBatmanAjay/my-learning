// TOPIC: lvalue & rvalue

// lvalue:
// lvalue is anything whose address is accessible.

// rvalue:
// Rvalue is anything that is not lvalue. It means we cannot take address of rvalue,
// And it also doesn't persist beyond the single expression.

// An lvalue (locator value) represents an object that occupies some identifiable location in memory (i.e. has an address).

// rvalues are defined by exclusion. Every expression is either an lvalue or an rvalue, so, an rvalue is an expression that does not represent an object occupying some identifiable location in memory.

// For example, An assignment expects an lvalue as its left operand, so the following is valid −

//     int i = 10;
//     But this is not:
//     int i;
//     10 = i;
// This is because i has an address in memory and is a lvalue. While 10 doesn't have an identifiable memory location and hence is an rvalue. So assigning the value of i to 10 doesn't make any sense.

int main()
{
    
    return 0;
}
