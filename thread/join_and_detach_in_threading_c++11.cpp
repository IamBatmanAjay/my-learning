/*
Join Notes:
    Once a thread is started we wait for this thread to finish by calling join() function on thread object
    Double join will lead in program termination
    If needed we should check if thread is joinable before joining. (using joinable() function)

Detach Notes:
    This is used to detach newly created thread from the parent thread
    Always check before detaching a thread that it is joinable otherwise we may end up double detaching 
        double detach willl result in program termination
    If we have detached thread and main functiuon is returning then the detached thread execution is suspended

Notes:
Either join() or detach() should be called on thread object, otherwise during thread object destructor it will ..
.. terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program
*/

#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

void run(int count){
    while(count --> 0)
        cout << "Ajay.. playing with cpp" << endl;
  //  std::this_thread::sleep_for(chrono::seconds(3));
    cout << "thread finish";
}
int main(){
    std::thread t1(run, 10);
    cout << "main() before" << endl;
    // t1.join();
    // if (t1.joinable())
    //     t1.join();
    t1.detach();
    cout << "main() after" << endl;
    std::this_thread::sleep_for(chrono::seconds(3));


    return 0;
}