/*
TOPIC: std::vector    


Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can 
also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike 
arrays, their size can change dynamically, with their storage being handled automatically by the container.

Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated 
in order to grow in size when new elements are inserted, which implies allocating a new array and moving all 
elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate 
each time an element is added to the container.

Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container 
may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size). Libraries 
can implement different strategies for growth to balance between memory usage and reallocations, but in any case, 
reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual 
elements at the end of the vector can be provided with amortized constant time complexity (see push_back).

Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow 
dynamically in an efficient way.

Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient 
accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. 
For operations that involve inserting or removing elements at positions other than the end, they perform worse 
than the others, and have less consistent iterators and references than lists and forward_lists.


NOTES:
1. std::vector is a sequence container and also known as Dynamic Array or Array List.
2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

ELEMENT ACCESS
at(), [], front(), back(), data()

MODIFIERS:
insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear(), capacity()

CAPACITY:
size(), empty(), capacity(), resize(), max_size()
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Declarations
    std::vector<int> arr1; 
    std::vector<int> arr2 (5, 20);
    std::vector<int> arr3 = { 1, 2, 3, 4, 5 }; // initializer list 
    std::vector<int> arr4 { 1, 2, 3, 4, 5 };   // uniform initialization

    // Accessing Elements
    arr2[3] = 10;
    arr2.at(3) = 10;

    for(int i=0; i<=10; ++i) { arr1.push_back(i); }
    for(const auto& vec: arr1) { cout << vec << endl; }
    cout << arr1[11]; // It returns 0 if index is not yet set
    cout << arr1.at(11); // throws exceptions if idx is out of range
    return 0;
}