/* code to create thread using function pointer */

#include <iostream>
#include <thread>
using namespace std;

void fun(int x)
{
    while (x-- > 0)
    {
        cout << x << endl;
    }
}

int main()
{

    std::thread t1(fun, 10);
    t1.join();
}