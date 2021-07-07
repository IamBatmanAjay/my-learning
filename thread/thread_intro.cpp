/*
Introduced in c++ 11
-- In every application there is a default thread which is main(), inside this we create main thread
-- A thread is light weight process, the idea is to attain paralleism by devideing a process into multiple thread
-- for example: The browser has multiple tab s that can be different thread
-- 
ways to create thread:
    Function pointer
    lambda functions
    memeber functions
    static member function

Problem: Find the addn of all odd number from 0 to 1900000000 and even no
*/

#include <iostream>
#include<thread>
#include<chrono>
#include<algorithm>
typedef unsigned long long ull;
using namespace std;
using namespace std::chrono;

ull oddsum = 0;
ull evensum = 0;

ull findOddSum( ull start, ull end )
{
    for (ull i=start; i<=end; i++)
    {
        if ((i & 1) == 1){
            oddsum += i;
        }
    }
    return oddsum;
}

ull findEvenSum( ull start, ull end )
{
    for (ull i=start; i<=end; i++)
    {
        if ((i & 1) == 0){
            evensum += i;
        }
    }
    return evensum;
}
int main()
{
    ull start = 0; ull end = 1900000000;
    auto startTime = high_resolution_clock::now();
    // findOddSum(start, end);
    // findEvenSum(start, end);
    std::thread t1(findEvenSum, start, end);
    std::thread t2(findOddSum, start, end);
    t1.join();
    t2.join();
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << duration.count()/1000000 << endl;
    cout << evensum << endl;
    cout << oddsum << endl;
}