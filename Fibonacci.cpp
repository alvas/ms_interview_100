#include <iostream>
#include <vector>
#include "NormalData.h"
#include "RandomData.h"

using namespace std;

const int N = 8;

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

int FibonacciMatrix(int n)
{
    // Initialize A as identity matrix in order to calculate the first result.
    // otherwise, the first result would be wrong. Don't use {1, 1, 1, 1}.
    const int s[4] = {1, 0, 1, 0};
    vector<int> A(s, s + 4);

    // Initialize B matrix, which will be used to calculate the result
    const int r[4] = {1, 1, 1, 0};
    vector<int> B(r, r + 4);

    // C is used to save temporary result. Don't save the temporary result
    // to A[i] or B[i], because it would tamper the result.
    vector<int> C(4);

    // for the first 3 results
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }

    // need to calculate matrix^(n-1)
    n -= 1;

    while (n > 0)
    {
        if ((n & 1) == 1)
        {
            C[0] = A[0] * B[0] + A[1] * B[2];
            C[1] = A[0] * B[1] + A[1] * B[3];
            C[2] = A[2] * B[0] + A[3] * B[2];
            C[3] = A[2] * B[1] + A[3] * B[3];
            A = C;
        }

        C[0] = B[0] * B[0] + B[1] * B[2];
        C[1] = B[0] * B[1] + B[1] * B[3];
        C[2] = B[2] * B[0] + B[3] * B[2];
        C[3] = B[2] * B[1] + B[3] * B[3];
        B = C;

        n >>= 1;
        printVector(A);
        printVector(B);
    }

    return A[0];
}

#ifndef EXPORT
int main()
{
//    Fibonacci(N);
//    cout << FibonacciRecursive(N) << endl;
    cout << FibonacciMatrix(N) << endl;
    return 0;
}
#endif
