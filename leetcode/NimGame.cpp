#include <iostream>

class Solution {
public:
    // 1 v
    // 2 v
    // 3 v
    // 4 x
    // 5 v
    // 6 v
    // 7 v
    // 8 x
    // 9 v
    // 10 v
    // 11 v
    // 12 x
    bool canWinNim(int n) {
       //return n % 4 != 0;
       return n & 3;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << sln.canWinNim(n) << std::endl;
    return 0;
}
