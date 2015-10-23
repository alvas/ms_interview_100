#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0)
        {
            return;
        }

        if (m == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                A[i] = B[i];
            }

            return;
        }

        bool increasing = true;

        if (A[0] > A[m - 1] || B[0] > B[n - 1])
        {
            increasing = false;
        }

        int C[m + n];
        int i = 0, j = 0, d = 0;


        for ( ; i < m && j < n; )
        {
            if (A[i] < B[j])
            {
                C[d++] = increasing ? A[i++] : B[j++];
            }
            else
            {
                C[d++] = increasing ? B[j++] : A[i++];
            }
        }

        if (i < m)
        {
            for ( ; i < m; )
            {
                C[d++] = A[i++];
            }
        }
        else
        {
            for ( ; j < n; )
            {
                C[d++] = B[j++];
            }
        }

        for (int i = 0; i < m + n; ++i)
        {
            A[i] = C[i];
        }
    }
};

int main()
{
    Solution sln;
    int A[500] = {1, 2, 3, 8, 19, 28};
    int B[500] = {4, 5, 9, 10, 20, 25, 30};
    int m = 6, n = 7;

    sln.merge(A, m, B, n);

    for (int i = 0; i < m + n; ++i)
    {
        std::cout << A[i] << "\t";

        if ((i + 1) % 10 == 0)
        {
            std::cout << endl;
        }
    }

    std::cout << endl;

    return 0;
}
