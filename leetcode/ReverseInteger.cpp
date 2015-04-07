#include <iostream>

using namespace std;

class Solution {
public:
    // !!Be careful about overflow!!
    // Need to improve!!
    int reverse(int x) {
        // abs cant' is undefined for -2147483648 
        long y = x, z = 0;
        y = labs(y);

        z = y % 10;
        y /= 10;

        while (y > 0)
        {
            int t = z * 10;

            cout << "z: " << z << " t: " << t << endl;

            // Be careful!! Overflow
            // checking addtion overflow a + b < b, a and b are both positive
            // checking multiplicatio overflow a * b = c, b != 0, c / b != a
            if (t / 10 != z)
            {
                return 0;
            }

            z = t + y % 10;

            cout << "z: " << z << " y: " << y << endl;

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
