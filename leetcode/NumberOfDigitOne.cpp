#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
        {
            return 0;
        }

        // use long so we can avoid overflow, for test case: 1410065408
        long c = 0;
        long f = 1;

        while (n / f)
        {
            long l = n - (n / f) * f;
            long d = (n / f) % 10;
            long u = n / (f * 10);

            switch(d)
            {
                case 0:
                {
                    c += u * f;
                    break;
                }
                case 1:
                {
                    c += (l + 1) + u * f;
                    break;
                }
                default:
                {
                    c += (u + 1) * f;
                    break;
                }
            }

            f *= 10;
        }

        return c;
    }
};

int main()
{
    Solution sln;
    cout << "Please enter n: ";
    int n = 0;
    cin >> n;
    cout << sln.countDigitOne(n) << endl;
    return 0;
}
