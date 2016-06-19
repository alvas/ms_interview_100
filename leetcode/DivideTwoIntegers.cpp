#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor)
        {
            return INT_MAX;
        }
        else if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        bool isNeg = false;

        if ((dividend > 0 && divisor < 0) ||
            (dividend < 0 && divisor > 0))
        {
            isNeg = true;
        }

        unsigned long long dvd = abs(dividend);
        unsigned long long dvs = abs(divisor);
        unsigned long long dvs_original = dvs;

        int i = 0;

        while (dvs << (i + 1) <= dvd)
        {
            i++;
        }

        int res = 0;

        // 32 / 3 = 10
        // 32 ~= 3 * 10 = 3 * (1 * (2 ^ 3) + 0 * (2 ^ 2) + 1 (2 ^ 1) + 0 * (2 ^ 0))
        // dvd = 32, dvs = 3
        while (dvd >= dvs_original)
        {
            if (dvd >= dvs << i)
            {
                dvd -= dvs << i;
                res += 1 << i;
            }

            i--;
        }

        return isNeg ? 0 - res : res;
    }

    int divide1(int dividend, int divisor) {
        if (divisor == 0)
        {
            return INT_MAX;
        }
        else if (dividend == 0)
        {
            return 0;
        }

        // use long long to avoid overflow
        long long sign = 1;

        if ((dividend > 0 && divisor < 0) ||
            (dividend < 0 && divisor > 0))
        {
            sign = -1;
        }

        long long a = dividend, b = divisor;
        a = abs(a);
        b = abs(b);

        // This condition is dangerous if we don't consider negative value.
        // It causes several bugs after I test negative value. It was at the
        // begining. But this checking should be here after abs.
        if (b == 1)
        {
            // if dividend = -2147483648 and divisor = -1, 1 * 2147483648 would overflow.
            // if sign is negative, -2147483647 is valid, it doesn't overflwo.
            if (a > INT_MAX && sign == 1)
            {
                return INT_MAX;
            }

            return a * sign;
        }
        else if (a < b)
        {
            return 0;
        }

        // These should be abs value.
        long long s = 1, e = a;

        while (s < e)
        {
            long long m = (s + e) >> 1;
            long long prod = m * b;

            if (prod <= a && a <= prod + b - 1)
            {
                return m * sign;
            }
            else if (prod < a)
            {
                s = m;
            }
            else if (a < prod)
            {
                e = m;
            }
        }
        
        return s * sign;
    }
};

int main()
{
    Solution sln;
    int dividend = 0, divisor = 0;
    std::cout << "Please enter dividend: ";
    cin >> dividend;
    std::cout << "Please enter divisor: ";
    cin >> divisor;
    std::cout << sln.divide(dividend, divisor) << endl;
    return 0;
}
