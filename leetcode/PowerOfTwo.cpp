#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
        {
            return 0;
        }

        return (n & (n - 1)) == 0;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    std::cout << sln.isPowerOfTwo(n) << endl;
    return 0;
}
