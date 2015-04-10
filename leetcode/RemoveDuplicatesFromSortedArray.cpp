#include <iostream>

using namespace std;

class Solution {
public:
    // Can be improved!
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
        {
            return n;
        }

        int i = 0;

        for (int j = 1; j < n; ++j)
        {
            if (A[i] != A[j])
            {
                A[++i] = A[j];
            }
        }

        return ++i;
    }
};

int main()
{
    Solution sln;
    const int LENGTH = 8;
    int A[LENGTH] = {1, 2, 2, 2, 3, 4, 5, 6};
    cout << sln.removeDuplicates(A, LENGTH) << endl;
    return 0;
}

