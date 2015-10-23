#include <iostream>

using namespace std;

class Solution {
public:
    // wiki digital root
    int addDigits(int num) {
        if (num <= 0)
        {
            return 0;
        }
        else if (num < 10)
        {
            return num;
        }

        // This implementation is much simpler, but it is slower than the algorithm below in leetcode data set.
        //return num - (num - 1) / 9 * 9;

        // This implementation is almost the same as the naive algorithm below in leetcode data set.
        return 1 + (num - 1) % 9;
    }

    int addDigits_naive(int num) {
        if (num <= 0)
        {
            return 0;
        }
        else if (num < 10)
        {
            return num;
        }

        while (num >= 10)
        {
            int tmp = num;
            num = tmp % 10;
            tmp /= 10;

            while (tmp != 0)
            {
                num += tmp % 10;
                tmp /= 10;
            }
        }

        return num;
    }
};

int main()
{
    Solution sln;
    int num = 0;
    std::cout << "Please enter num: ";
    cin >> num;
    std::cout << sln.addDigits_naive(num) << endl;
    std::cout << sln.addDigits(num) << endl;
    return 0;
}
