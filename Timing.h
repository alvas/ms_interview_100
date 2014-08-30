#include <iostream>

using namespace std;

void printTime(clock_t t)
{
    cout << "Time: " << t / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
}
