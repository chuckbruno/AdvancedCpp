#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu;

using namespace std;

void shared_print(std::string message, int id)
{
    mu.lock();
    // std::unique_lock<std::mutex> guard(mu);
    cout << message << id << endl;
    mu.unlock();
}

void myFunc()
{
    for(int i=0; i > -10; i--)
    {
        shared_print(std::string("Call from t1: "), i);
    }
}



int main()
{

    thread t1(myFunc);
    thread t2(myFunc);
    for(int i=0; i < 10; i++)
    {
        shared_print("Call from main: ", i);
    }

    t1.join();
    t2.join();
    return 0;
}