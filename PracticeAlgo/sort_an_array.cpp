//Sort an array of 0s, 1s and 2s
/*
This problem is variation of famous Dutch national flag problem
The problem was posed with three colours, here `0′, `1′ and `2′. The array is divided into four sections: 
    a[1..Lo-1] zeroes (red)
    a[Lo..Mid-1] ones (white)
    a[Mid..Hi] unknown
    a[Hi+1..N] twos (blue)
    If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
    Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
    If the element is 2 then swap it with an element in high range.
*/

#include<bits/stdc++.h>
using namespace std;


void sort012(int arr[], int size)
{
    int lo = 0;
    int mid = 0;
    int hi = size - 1;

    while(mid <= hi)
    {
        switch(arr[mid])
        {
            case 0:
            {
                swap(arr[lo++], arr[mid++]);
                break;
            }
            case 1:
            {
                mid++;
                break;
            }
            case 2:
            {
                swap(arr[mid], arr[hi--]);
                break;
            }
        }
    }
}

int main()
{
    int input_size = 5;
    int arr[5];
    cout << "Enter an array" << endl;
    for (int i = 0 ; i < input_size; i++)
    {
        cin >> arr[i];
    }
    cout << "Sorting the array..." << endl;
    int tmp;
    sort012(arr, input_size);
    
    for (int i = 0 ; i < input_size; i++)
    {
        cout << arr[i] << "|";
    }
    return 0;
}