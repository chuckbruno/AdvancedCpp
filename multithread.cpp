#include <thread>
#include <iostream>


void myFunc()
{
    std::cout << "So, are we there yet ?" << std::endl;
}

int main()
{
    // myFunc();
    std::thread t1(myFunc); // t1 starts running
    // t1.join(); // main thread waits for t1 to finish
    t1.detach(); // t1 will run freely (dameno process)
    return 0;
}
