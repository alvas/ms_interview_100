#include <cmath>
#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
        {
            return false;
        }

        int maxPow3 = log10(INT_MAX) / log10(3);
        int maxPow3Val = pow(3, maxPow3);
        return maxPow3Val % n == 0;
    }

    bool isPowerOfThree_naive(int n) {
        bool res = false;

        if (n == 1)
        {
            return true;
        }

        while (n != 0)
        {
            if (n % 3 != 0)
            {
                res = false;
                break;
            }
            else
            {
                n /= 3;

                if (n == 1)
                {
                    res = true;
                    break;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter num: ";
    std::cin >> n;
    std::cout << sln.isPowerOfThree(n) << std::endl;
    return 0;
}
