#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int a[3] = {0, 1, 2};
        vector<int> v(a, a + 3);

        // Be careful about the index i
        for (int i = 3; i <= n; ++i)
        {
            // Be careful about the index i
            int sum = 2 * v[i - 1];

            // Be careful about the index i and j
            for (int j = 1; j < i; ++j)
            {
                // Be careful about the index i and j
                sum += v[j] * v[i - j - 1];
            }

            v.push_back(sum);
        }

        return v[n];
    }

    int numTrees_recursive(int n) {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }

        int sum = 2 * numTrees(n - 1);

        for (int i = 1; i < n; ++i)
        {
            sum += numTrees(i) * numTrees(n - i - 1);
        }

        return sum;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n: ";
    cin >> n;
    cout << sln.numTrees_recursive(n) << endl;
    cout << sln.numTrees(n) << endl;
    return 0;
}

