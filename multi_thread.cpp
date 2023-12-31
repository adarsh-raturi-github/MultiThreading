#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;
using namespace std;

typedef unsigned long long ull;

ull even_sum = 0;
ull odd_sum = 0;

void findEvenSum(ull start, ull end)
{
    cout << "step3" << endl;
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
            even_sum += i;
        }
    }
}

void findOddSum(ull start, ull end)
{
    cout << "Step4" << endl;
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)
        {
            odd_sum += i;
        }
    }
}
int main()
{
    auto startTime = high_resolution_clock::now();

    cout << "step1" << endl;
    ull start = 0;
    ull end = 1900000000;
    std::thread t1(findEvenSum, start, end); // create thread and function excution start on t1 thread
    cout << "step2" << endl;
    // try to put t1.join() here it will result in same exection time as without thread
    std::thread t2(findOddSum, start, end); // create thread and function excution start on t2 thread
                                            // thus t1 and t2 runs parallel
    t1.join();                              // main thread waiting till t1 complete
    t2.join();                              // main thread waiting till t2 complete
    cout << "step5" << endl;
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "seconds:" << duration.count() / 1000000 << endl;
    cout << "Even :" << even_sum << endl;
    cout << "Odd :" << odd_sum << endl;
}