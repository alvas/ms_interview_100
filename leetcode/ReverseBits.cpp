#include <iostream>

using namespace std;

class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        const unsigned char lookup[16] = {
            0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
            0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf };
        // Be careful about bit shifting!!
        return lookup[n & 0xf] << 28 |
               lookup[(n & (0xf << 4)) >> 4] << 24 |
               lookup[(n & (0xf << 8)) >> 8] << 20 |
               lookup[(n & (0xf << 12)) >> 12] << 16 |
               lookup[(n & (0xf << 16)) >> 16] << 12 |
               lookup[(n & (0xf << 20)) >> 20] << 8 |
               lookup[(n & (0xf << 24)) >> 24] << 4 |
               lookup[(n & (0xf << 28)) >> 28];
    }
};

int main()
{
    Solution sln;
    uint32_t n = 0;
    std::cout << "Please input n: ";
    cin >> n;
    bitset<32> r(n);
    std::cout << r << endl;
    n = sln.reverseBits(n);
    bitset<32> r2(n);
    std::cout << n << "\t" << r2 << endl;
    return 0;
}

