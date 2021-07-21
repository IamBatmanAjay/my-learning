#include<iostream>
#include<thread>
using namespace std;


/*
There are 5 diff way to create thread in c++11
-- if we create multiple thread at same time, it doesnt gurantee which thread will start first
    1. function pointer
    2. lamda function
    3. function object
    4. Non static member functions
    5. Static memebr function
*/

/*
There are 5 ways to create thread in cpp
If we create multiple thread at the same time, It didnt gaurantee which one will start first
*/

// 1. Function pointer

// void fun(int x) {
//     while( x > 0){
//         x--;
//         std::cout << x << endl;
//     }
// }

// int main(){
//     std::thread t1(fun, 11);
//     std::thread t2(fun, 10);
//     t1.join();
//     t2.join();
//     return 0;
// }

// 2: Using lambda expression 
// EXAMPLE:
// int main(){
//     // auto fun = [](int x){
//     //     while( x-- > 0){
//     //     std::cout << x << endl;
//     // }
//     // };
//     std::thread t([](int x){
//         while( x-- > 0){
//         std::cout << x << endl;
//     }
//     }, 10);
//     t.join();
//     return 0;
// }



// 3. Using Functor( Function object)
// EXAMPLE
// class Base {
//     public:
//         void operator () (int x) {
//             while (x--> 0){
//                 cout << x << endl;
//             }
//         }
// };

// int main(){
//     std::thread t((Base()), 10);
//     t.join();
//     return 0;
// }


// 4 . Using Non static member function
// class Base {
//     public:
//         void run (int x) {
//             while (x--> 0){
//                 cout << x << endl;
//             }
//         }
// };

// int main(){
//     Base b;
//     std::thread t(&Base::run, &b, 10);
//     t.join();
//     return 0;
// }

//4 . Using Non static  function
class Base {
    public:
        static void run (int x) {
            while (x--> 0){
                cout << x << endl;
            }
        }
};

int main(){
    Base b;
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}