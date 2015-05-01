#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;

        if (n <= 1)
        {
            return count;
        }

        // Be careful about the requirement "less than n"
        for (int i = 2; i < n; ++i)
        {
            int root = sqrt(i);
            bool isPrime = true;

            for (int j = 2; j <= root; ++j)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n: ";
    cin >> n;
    cout << sln.countPrimes(n) << endl;
    return 0;
}
