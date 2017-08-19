#include <iostream>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        long a = 0, b = 0;
    }

    bool isPalindrome(int n) {
        if (n < 0) {
            return false;
        }

        int a = n, b = 0;

        while (a) {
            b *= 10;
            b += a % 10;
            a /= 10;
        }

        return b == n;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << sln.largestPalindrome(n) << endl;
    return 0;
}
