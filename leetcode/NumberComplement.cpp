#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;

        while (num & mask) {
            mask <<= 1;
        }

        return ~mask & ~num;
    }

    int findComplement1(int num) {
        int i = 31;

        for ( ; i >= 0; --i) {
            if ((1 << i) & num) {
                break;
            }
        }

        if (i >= 30) {
            return INT_MAX & ~num;
        }
        else {
            // (1 << (i + 1)) - 1 would cause overflow because -2147483648 - 1;
            int b = (1 << (i + 1)) - 1;
            return b & INT_MAX & ~num;
        }
    }
};

int main() {
    Solution sln;
    //int num = 5;
    //int num = 1;
    //int num = 37;
    //int num = 2147483647;
    int num = 2147483646;
    cout << sln.findComplement(num) << endl;
    return 0;
}
