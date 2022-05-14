#include <iostream>
#include <thread>
#include <mutex>


using namespace std;
std::mutex mu;

void shared_print(std::string message, int id)
{
    // mu.lock();
    // std::unique_lock<std::mutex> guard(mu);
    cout << message << id << endl;
    // mu.unlock();
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
    std::thread t1(myFunc);
    for(int i=0; i < 10; i++)
    {
        shared_print("Call from main: ", i);
    }

    t1.join();
    return 0;
}

// std::mutex mtx;

// void print_block(int n, char c)
// {
//     std::unique_lock<std::mutex> lck(mtx);
//     for(int i = 0; i < n; i++)
//     {
//         std::cout << c;
//     }
//     std::cout << '\n';
// }

// int main()
// {
//     std::thread th1(print_block, 50, '*');
//     std::thread th2(print_block, 50, '$');

//     th2.join();
//     th1.join();

//     return 0;
// }