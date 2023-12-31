#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

typedef unsigned long long ull;

ull even_sum = 0;
ull odd_sum = 0;

void findEvenSum(ull start, ull end)
{
    cout << "step2" << endl;
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
    findEvenSum(start, end);
    cout << "step3" << endl;
    findOddSum(start, end);
    cout << "step5" << endl;
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "seconds:" << duration.count() / 1000000 << endl;
    cout << "Even :" << even_sum << endl;
    cout << "Odd :" << odd_sum << endl;
}