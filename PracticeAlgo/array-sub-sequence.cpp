#include<iostream>

using namespace std;

void printSubArraySequence(int arr[], int n, int m /*subArray size*/)
{
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (j-i== m-1)
            {
                for (int k = i; k <=j; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main()
{

    int arr[] = {1,2,3,4,5};
    printSubArraySequence(arr, sizeof(arr)/sizeof(arr[0]), 3);
}