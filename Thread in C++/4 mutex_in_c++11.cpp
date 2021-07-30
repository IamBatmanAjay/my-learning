/*
Topic: Mutex in cpp threading 
Mutex: Mutual exclusion

Race condition:
0. Race condition is situation wherere two or more thread to access common data at same time
1. If therer is race condiotion then we have to protect it and the protected section is called critical section/ region

Mutex:
0. Mutexs is used to avod race condiotion
1. We use lock() unlock() on mutex to avoid race condition
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int myAmount = 0;
std::mutex m;
void addMoney(){
    m.lock(); // this is blocking call.. try_lock is used for non blocking call
    ++myAmount; // race condition can happen here so critical section or region
    m.unlock();
}
int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    t1.join();
    t2.join();
    cout << myAmount << endl;
    return 0;
}