#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // When convert int to string, don't need to reverse it.
    // int 12345 convert to string b, it is "123", b[0] = 1, b[1] = 2, b[2] = 3.
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        int sz = nums.size();

        // Need to consider when all number are 0.
        string zero = to_string(0);
        bool allZero = true;

        for (int i = 0; i < sz; ++i)
        {
            string n = to_string(nums[i]);

            if (n != zero)
            {
                allZero = false;
            }

            s.push_back(n);
        }

        if (allZero)
        {
            return zero;
        }

        sort(s.begin(), s.end(), myfunction);

        string r;

        for (int i = 0; i < sz; ++i)
        {
            string n = s[i];
            r += n;
        }

        return r;
    }

    static bool myfunction(string a, string b)
    {
        int sz1 = a.size(), sz2 = b.size();
        string zero = to_string(0);

        // Either of a or b is zero, it is smaller, so it goes later.
        if (a == zero)
        {
            return false;
        }
        else if (b == zero)
        {
            return true;
        }

        for (int i = 0; i < sz1 && i < sz2; ++i)
        {
            if (a[i] < b[i])
            {
                return false;
            }
            else if (a[i] > b[i])
            {
                return true;
            }
        }

        // Be careful when there is no gcd. len would be 1.
        int len = std::__gcd(sz1, sz2);

        // Then we need to use the multiple of sz1 and sz2 as len.
        if (len == 1)
        {
            len = sz1 * sz2;
        }

        int t1 = len / sz1, t2 = len / sz2;
        string a2, b2;

        for (int i = 0; i < t1; ++i)
        {
            a2 += a;
        }

        for (int i = 0; i < t2; ++i)
        {
            b2 += b;
        }

        for (int i = 0; i < len; ++i)
        {
            if (a2[i] < b2[i])
            {
                return false;
            }
            else if (a2[i] > b2[i])
            {
                return true;
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    int a[] = {3, 30, 34, 5, 9};
    //int a[] = {3, 303, 3034, 5, 9};
    //int a[] = {3, 303};
    //int a[] = {0, 0, 0};
    //int a[] = {20, 1};
    string b = to_string(12345);

    for (int i = 0; i < b.size(); ++i)
    {
        cout << b[i] << "\t";
    }

    cout << endl;

    vector<int> nums(a, a + SIZE(a));
    printVector<int>(nums);
    cout << sln.largestNumber(nums) << endl;
    return 0;
}
