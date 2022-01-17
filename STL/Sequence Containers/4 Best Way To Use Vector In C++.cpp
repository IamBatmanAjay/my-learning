/*
TOPIC: Best way to use vector in C++

Avoid unnecessary reallocate and copy cycles by reserving the size of vector ahead of time.

Use shrink_to_fit() to release memory consumed by the vector – clear() or erase() does not release memory.

When filling up or copying into a vector, prefer assignment over insert() or push_back().
The question is Why ???
Assignment is very efficient because it knows the size of the vector it is copying, and needs to call the memory 
manager only once to create the assigned vector’s internal buffer.

So, to fill up a vector efficiently, try assignment, insert() with iterators from another container, and push_back(), 
in that order. Of course, if you have to copy from another type of container into a vector, assignment is not an 
option. In this case, you’d want to do an iterator based insert.

While iterating through elements in a std::vector, avoid the std::vector::at() function.

Try to avoid inserting an element in front of the vector.

Prefer emplace_back() instead of push_back() while inserting into a vector

PROBLEM IN VECTOR ? The size get doubled once It crosses the reserved size

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> Vec;
    Vec.reserve(31);
    for(int i=0; i<32; ++i) { 
        Vec.push_back(i);
        cout << "Size:" << Vec.size() << "   Capacity:" << Vec.capacity() << endl;
    }
    return 0;
}