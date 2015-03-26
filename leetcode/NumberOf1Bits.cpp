#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;

        while (n != 0)
        {
            if ((n & 1) != 0)
            {
                num++;
            }

            n >>= 1;
        }

        return num;
    }
};

int main()
{
    Solution sln;
    uint32_t n = 0;
    cout << "Please enter number: ";
    cin >> n;
    bitset<sizeof(n) * 8> b(n);
    cout << sln.hammingWeight(n) << " : " << b << endl;
    return 0;
}
