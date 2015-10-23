#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0)
        {
            return 0;
        }

        // starting value
        int a = x / 2, b = sqrt(INT_MAX);
        int start = 0, end = a < b ? (a + 1) : b;

        while (start < end)
        {
            int mid = (start + end) / 2;
            int square = mid * mid;

            if (square == x)
            {
                return mid;
            }
            else if (square < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return (start + end) / 2;
    }

    // Borrow from wiki. Need to study it carefully.
    int mySqrt_bit(int x) {
        if (x <= 0)
        {
            return 0;
        }

        int res = 0;
        int bit = 1 << 30;

        while (bit > x)
        {
            bit >>= 2;
        }

        while (bit != 0)
        {
            if (x >= res + bit)
            {
                x -= res + bit;
                res = (res >> 1) + bit;
            }
            else
            {
                res >>= 1;
            }

            bit >>= 2;
        }

        return res;
    }

    int mySqrt_slow(int x) {
        if (x <= 0)
        {
            return 0;
        }

        int i = 1;

        for ( ; i < x; ++i)
        {
            if (i * i == x)
            {
                break;
            }
            else if (i * i > x)
            {
                i--;
                break;
            }
        }

        return i;
    }
};

int main()
{
    Solution sln;
    int x = 0;
    std::cout << "Please enter x: ";
    cin >> x;
    std::cout << sln.mySqrt(x) << endl;
    std::cout << sqrt(x) << endl;
    return 0;
}
