#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x != 0)
        {
            // checking overflow/underflow
            if (abs(res) > 214748364)
            {
                return 0;
            }

            res = res * 10 + x % 10;

            x /= 10;
        }

        return res;
    }

    // !!Be careful about overflow!!
    // Need to improve!!
    int reverse1(int x) {
        // abs cant' is undefined for -2147483648 
        long y = x, z = 0;


        // actually, we don't need to get abs here and set the sign
        // because % operation would get the right sign for us.
        // if x = -25, then x % 10 = -5
        y = labs(y);

        z = y % 10;
        y /= 10;

        while (y > 0)
        {
            int t = z * 10;

            //cout << "z: " << z << " t: " << t << endl;

            // Be careful!! Overflow
            // checking addtion overflow a + b < b, a and b are both positive
            // checking multiplication overflow a * b = c, b != 0, c / b != a
            if (t / 10 != z)
            {
                return 0;
            }

            z = t + y % 10;

            //cout << "z: " << z << " y: " << y << endl;

            y /= 10;
        }

        if (x < 0)
        {
            z *= -1;
        }

        return z;
    }
};

int main()
{
    Solution sln;
    int x = 0;
    cout << "Please enter x: ";
    cin >> x;
    // 1534236469 and -2147483648 would cause overflow
    cout << sln.reverse(x) << endl;
    return 0;
}
