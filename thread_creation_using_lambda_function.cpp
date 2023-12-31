/* thread creation using lambda function*/
#include <iostream>
#include <thread>
using namespace std;
int main()
{
    auto x = [](int y)
    {
        while (y-- > 0)
        {
            cout << y << endl;
        }
    };
    std::thread t1(x, 10);
    t1.join();
}