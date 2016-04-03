#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        int m = num.size();

        if (m == 0)
        {
            return 0;
        }

        vector<int> v(m, 0);
        v[0] = num[0];

        if (m > 1)
        {
            v[1] = max(num[0], num[1]);
        }

        for (int i = 2; i < m; ++i)
        {
            v[i] = max(v[i - 2] + num[i], v[i - 1]);
        }

        return v[m - 1];
    }

    int rob3(vector<int> &num) {
        return rrob(num, 0);
    }

    int rrob(vector<int> &num, int i)
    {
        if (i > num.size())
        {
            return 0;
        }

        return max(num[i] + rrob(num, i + 2), rrob(num, i + 1));
    }

    int rob2(vector<int> &num) {
        int amount = 0, size = num.size();

        if (size == 1)
        {
            return num[0];
        }
        else if (size == 2)
        {
            return max(num[0], num[1]);
        }
        else if (size > 2)
        {
            vector<int> sum;
            sum.push_back(num[0]);
            sum.push_back(max(num[0], num[1]));

            // Dynamic Programming
            for (int i = 2; i < size; ++i)
            {
                sum.push_back(max(sum[i - 1], sum[i - 2] + num[i]));
            }

            return sum[size - 1];
        }

        return amount;
    }

    // Time exceed. Need to improve performance.
    int rob1(vector<int> &num) {
        int amount = DPRob(num, num.size() - 1);
        return amount;
    }

    int DPRob(vector<int> &num, int idx)
    {
        if (idx < 0)
        {
            return 0;
        }
        else if (idx == 0)
        {
            return num[0];
        }
        else if (idx == 1)
        {
            return max(num[0], num[1]);
        }

        return max(DPRob(num, idx - 1), DPRob(num, idx - 2) + num[idx]);
    }
};

int main()
{
    Solution sln;
    std::vector<int> num = {104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143};
    
    /*
    string  n;
    std::cout << "Please enter number: ";
    getline(cin, n);

    while (!n.empty())
    {
        num.push_back(atoi(n.c_str()));
        std::cout << "Please enter number: ";
        getline(cin, n);
    }
    */

    int a = sln.rob(num);
    int b = sln.rob2(num);
    std::cout << a << endl;
    std::cout << b << endl;
    assert(a == b);
    return 0;
}
