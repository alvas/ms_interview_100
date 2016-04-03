#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;

        while (n > 0)
        {
            n /= 5;
            result = result + n;
            // WATCH OUT!! Don't do this way, it is very slow.
            // int tmp = 5; n / tmp; tmp *= 5;
            //n /= 5;
        }

        return result;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    std::cout << "n! = " << tgamma(n + 1) << " : " << sln.trailingZeroes(n) << endl;
    return 0;
}
