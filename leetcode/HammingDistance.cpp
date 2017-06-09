#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> z(x ^ y);
        return z.count();

        //return __builtin_popcount(x^y);
    }
};

int main() {
    Solution sln;
    int x = 1, y = 4;
    cout << sln.hammingDistance(x, y) << endl;
    return 0;
}
