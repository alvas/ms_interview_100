#include <iostream>

using namespace std;

class Solution {
public:
    // Need to improve.
    bool isPalindrome(int x) {
        bool isP = false;

        if (x >= 0)
        {
            int y = x % 10, z = x;
            x /= 10;

            while (x > 0)
            {
                y *= 10;
                y += (x % 10);
                x /= 10;
            }

            if (z == y)
            {
                isP = true;
            }
        }

        return isP;
    }
};

int main()
{
    Solution sln;
    int x = 0;
    cout << "Please input n: ";
    cin >> x;
    cout << sln.isPalindrome(x) << endl;
    return 0;
}

