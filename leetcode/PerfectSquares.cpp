#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> v(1, 0);

        while (v.size() <= n)
        {
            int m = v.size(), val = INT_MAX;

            for (int i = 1; i * i <= m; ++i)
            {
                val = min(val, v[m - i * i] + 1);
            }

            v.push_back(val);
        }

        return v.back();
    }

    int numSquares_slow(int n) {
        std::vector<int> v = {0, 1};
        int i = 1;

        while (++i <= n)
        {
            int j = sqrt(i);
            int j2 = j * j;

            if (j2 == i)
            {
                v.push_back(1);
            }
            else
            {
                // Be careful about the k here. It is not i - j2. It is v[i - j2].
                int k = v[i - j2];

                while (--j > 0)
                {
                    j2 = j * j;
                    k = min(k, v[i - j2]);
                }

                v.push_back(1 + k);
            }

        }

        return v[n];
    }
};

int main()
{
    Solution sln;
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 20, 34, 57, 486, 712, 1263, 2836, 6666, 26343, 98364, 388606};

    for (auto a : v)
    {
        int n1 = sln.numSquares_slow(a), n2 = sln.numSquares(a);
        std::cout << a << ": " << n1 << std::endl;
        std::cout << a << ": " << n2 << std::endl;
        assert(n1 == n2);
    }

    return 0;
}
