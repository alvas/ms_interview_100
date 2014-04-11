#include <iostream>

using namespace std;

const int N = 5;

void Fibonacci(const int n)
{
    int x[3] = {0, 1, 0};

#ifdef DEBUG
    cout << 0 << endl << 1 << endl;
#endif

    for (int i = 2; i <= n; ++i)
    {
        x[i % 3] = x[(i - 2) % 3] + x[(i - 1) %3];

#ifdef DEBUG
        cout << x[i % 3] << endl;
#endif
    }

    cout << x[n % 3] << endl;
}

int FibonacciRecursive(const int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1; 
    }
    else
    {
        return FibonacciRecursive(n - 2) + FibonacciRecursive(n - 1);
    }
}

#ifndef EXPORT
int main()
{
//    Fibonacci(N);
    cout << FibonacciRecursive(N) << endl;
    return 0;
}
#endif
