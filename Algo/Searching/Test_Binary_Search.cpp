#include<iostream>
using namespace std;


int binary_search(int arr[], int l, int r, int key)
{
    if (r >= l){
        int mid = l + (r-l)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key )
        {
            l = mid+1;
            return binary_search(arr, mid+1, r, key);
        }
        return binary_search(arr, l,  mid-1, key);
    }
    return -1;
}

int main()
{
    //int arr[] = {1,2,3,4,5,6,8};
    int arr[20];
    int key;
    int total_input;
    cout << "Enter total no of element!";
    cin >> total_input;
    for(int i=0; i<total_input; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key?";
    cin >> key;
    int result = binary_search(arr, 0, total_input-1, key);
    (result == -1) 
            ? cout << "key missing!\n" 
            : cout << "Key found!\n";
    return 0;
}