#include <thread>
#include <iostream>
#include <string>


void myFunc()
{
    std::cout << "So, are we there yet ?" << std::endl;
}


class F
{
    public:

        void operator()(std::string message)
        {
            for(int i = 0; i > -10; i--){
                std::cout << " Starting at t1 " << message << std::endl;
            }
        }
};

int main()
{
    // myFunc();
    // thread can only be moved cannot copy 
    std::string s = "I've got work tomorrow";
    F functor;
    std::cout << std::this_thread::get_id() << std::endl; // the parent thread ID
    std::thread t1(functor, std::move(s));
    std::thread t2 = std::move(t1);
    std::cout << t2.get_id() << std::endl;
    t2.join();
    std::cout << std::thread::hardware_concurrency() << std::endl; // the parent thread ID
    // std::thread t1(myFunc); // t1 starts running
    // t1.join(); // main thread waits for t1 to finish
    //  t1.detach(); // t1 will run freely (dameno process)
    // join 智能一次，detach之后就不能在join了可以用joinable来判断是否可以join
    // if(t1.joinable())
    // {
    //     t1.join();
    // }

    // try
    // {
    //     for(int i = 0; i < 10; i++)
    //     {
    //         std::cout << " Message from main:  " << i << std::endl;
    //     }
    // }
    // catch(...)
    // {
    //     // t1.join();
    //     throw;
    // }

    // t1.join();
    
    return 0;
}
