#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
        {
            return 0;
        }

        long m = n;

        return (m & (m - 1)) == 0;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n: ";
    cin >> n;
    cout << sln.isPowerOfTwo(n) << endl;
    return 0;
}
