#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int getSum(int a, int b) {
            if (b == 0) {
                return a;
            }

            int sum = a ^ b;
            int carry = (a & b) << 1;
            return getSum(sum, carry);

            // only one line solution
            // return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
        }

        int getSum2(int a, int b)
        {
            while (b)
            {
                int carry = (a & b) << 1;
                a = a ^ b;
                b = carry;
            }

            return a;
        }

        // Need to improve.
        int getSum1(int a, int b) {
            int sum = 0, c = 0, bit = 0;

            while (a || b) 
            {
                int a1 = a & 1, b1 = b & 1;
                // IMPORTANT, use unsigned shift, otherwise, it 1 would be added to the left end.
                a = (unsigned int)a >> 1;
                b = (unsigned int)b >> 1;

                if (c == 0)
                {
                    c = a1 & b1;
                    sum |= (a1 ^ b1) << bit;
                }
                else
                {
                    c = (a1 | b1) ? 1 : 0;
                    sum |= ((a1 ^ b1) ? 0 : 1) << bit;
                }

                bit++;
            }

            // Don't forget to add the carry to highest bit
            if (c != 0 && bit < sizeof(int) * 8)
            {
                sum |= 1 << bit;
            }

            return sum;
        }
};

int main() 
{
    Solution sln;
    vector<vector<int>> a = {
        {0, 0},
        {0, 1},
        {2, 0},
        {1, 2},
        {2, 3},
        {0, -1},
        {-2, 0},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {2, -3},
        {-2, -3},
        {-2, 3},
        {100, 200},
        {1381, 2348},
        {2147483640, 7},
        {-2147483647, -1}
    };

    for (auto i: a)
    {
        cout << sln.getSum(i[0], i[1]) << endl;
    }

    return 0;
}
