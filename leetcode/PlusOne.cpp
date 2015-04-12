#include <iostream>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        int carry = 1, size = digits.size();

        if (size < 1)
        {
            return result;
        }

        for (vector<int>::reverse_iterator rit = digits.rbegin();
             rit != digits.rend(); ++rit)
        {
            int a = *rit + carry;
            carry = a / 10;
            result.push_back(a % 10);
        }

        // Don't forget the carry digit!!
        if (carry != 0)
        {
            result.push_back(carry);
        }

        // Remember to reverse correctly.
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution sln;
    int num = 0;
    cout << "Please enter num: ";
    cin >> num;

    vector<int> d;

    if (num == 0)
    {
        d.push_back(0);
    }
    else
    {
        while (num != 0)
        {
            d.push_back(num % 10);
            num /= 10;
        }
    }

    reverse(d.begin(), d.end());
    vector<int> r = sln.plusOne(d);
    printVector<int>(r);
    return 0;
}
