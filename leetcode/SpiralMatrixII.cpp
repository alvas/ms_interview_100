#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));

        int half = n / 2;
        int val = 1;

        for (int i = 0; i < half; ++i)
        {
            int last = n - 1 - i;

            for (int j = i; j < last; ++j)
            {
                ret[i][j] = val++;
            }

            for (int j = i; j < last; ++j)
            {
                ret[j][last] = val++;
            }

            for (int j = last; j > i; --j)
            {
                ret[last][j] = val++;
            }

            for (int j = last; j > i; --j)
            {
                ret[j][i] = val++;
            }
        }

        if (n % 2 == 1)
        {
            ret[half][half] = val;
        }

        return ret;
    }

    vector<vector<int> > generateMatrix1(int n) {
        vector<vector<int> > v(n, vector<int>(n, 0));
        int count = 1, start = 0, end = n;

        while (start < end)
        {
            for (int k = start; k < end; ++k)
            {
                v[start][k] = count++;
            }

            for (int k = start + 1; k < end; ++k)
            {
                v[k][end - 1] = count++;
            }

            end--;

            // Be careful about the end index, because it has been decrease 1 already.
            for (int k = end - 1; k >= start; --k)
            {
                v[end][k] = count++;
            }

            start++;

            for (int k = end - 1; k >= start; --k)
            {
                v[k][start - 1] = count++;
            }

        }

        return v;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    vector<vector<int> > v = sln.generateMatrix(n);
    print2DVector<int>(v);
    return 0;
}
