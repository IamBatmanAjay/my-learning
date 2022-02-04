// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     std::vector<int>vec;
//     int n ;
//     std::cin >> n;
//     for (int i=0; i < n; i++)
//     {
//         int tmp;
//         std::cin >> tmp;
//         vec.push_back(tmp);  
//     }
//     sort(vec.rbegin(), vec.rend());
//     do {
//        std::cout << vec.back();
//        vec.pop_back();
//     }while (vec.size() >0);

//     // while(vec.size())
//     // {

//     // }
    
//     return 0;
// }
#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void run(int counter)
{
    cout << "thread start" << endl;
    while (counter)
    {
        cout << counter-- << endl;
        std::this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "thread complete" << endl;
}

int main()
{
    cout << "Main thread start" << endl;
    std::thread t1(run, 10);
    std::thread t2(run, 3);
    t1.detach();
    t2.detach();
    std::this_thread::sleep_for(chrono::seconds(20));
    cout << "Main thread done.";
    return 0;
}


