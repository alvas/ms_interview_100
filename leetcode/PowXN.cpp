#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            return 1.0 / power(x, -n);
        }
        else
        {
            return power(x, n);
        }
    }

    double power(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }

        double v = power(x, n / 2);
        v *= v;

        if (n % 2)
        {
            return v * x;
        }
        else
        {
            return v;
        }
    }

    double myPow1(double x, int n) {
        // When x is 0, then the result is always 0.
        if (x == 0.0)
        {
            return 0;
        }

        double r = 1.0;

        // Need to consider when n is positive and negative situations.
        if (n >= 0)
        {
            while (n > 0)
            {
                if (n & 1)
                {
                    r *= x;
                }

                x *= x;
                n >>= 1;
            }
        }
        else
        {
            n *= -1;

            while (n > 0)
            {
                if (n & 1)
                {
                    r *= x;
                }

                x *= x;
                n >>= 1;
            }

            r = 1 / r;
        }

        return r;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    double x = 0.0;
    std::cout << "Please enter x: ";
    cin >> x;
    std::cout << sln.myPow(x, n) << endl;
    return 0;
}
