/*
Method 1 (Simple Solution) 
A simple solution is to sort the given array using an O(N log N) sorting algorithm like Merge Sort, Heap Sort, etc, and return the element at index k-1 in the sorted array. 
Time Complexity of this solution is O(N Log N)
Method 2 (using set from C++ STL)

we can find the kth smallest element in time complexity better than O(N log N). we know the Set in C++ STL is 
implemented using Binary Search Tree and we also know that the time complexity of all cases(searching, inserting, 
deleting ) in BST is log (n) in the average case and O(n) in the worst case. We are using set because it is 
mentioned in the question that all the elements in an array are distinct.

Method 3 (Using Min Heap – HeapSelect) 
We can find k’th smallest element in time complexity better than O(N Log N). A simple optimization is to create a 
Min Heap of the given n elements and call extractMin() k times. 
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    // method 1;
    int arr[] = {6,5,8,9,3,11,35,28,45,98};
    int nth = 4;
    int size = sizeof(arr)/sizeof(arr[0]);
    // stl sort method require begin and end address of array/container  
    sort(arr, arr + size); // here the complexity of sort method is O(n*Log(n))
    cout << "nth smallest element is : " << arr[nth-1] << endl;
    cout << "nth largest element is : " << arr[size-nth];
    return 0;
}

// Method:2
// #include <bits/stdc++.h>
// using namespace std;
 
// int main()
// {
 
//     int arr[] = { 12, 3, 5, 7, 19 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 4;
 
//     set<int> s(arr, arr + n);
//     set<int>::iterator itr
//         = s.begin(); // s.begin() returns a pointer to first
//                      // element in the set
//     advance(itr, k - 1); // itr points to kth element in set
 
//     cout << *itr << "\n";
 
//     return 0;
// }