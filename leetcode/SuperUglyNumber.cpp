#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();

        if (k == 0)
        {
            return 0;
        }

        vector<int> nums(1, 1);
        vector<int> index(k, 0);

        for (int i = 1; i < n; ++i)
        {
            vector<int> p2;
            int minV = INT_MAX;

            for (int j = 0; j < k; ++j)
            {
                int a = nums[index[j]] * primes[j];
                p2.push_back(a);
                minV = min(minV, a);
            }

            nums.push_back(minV);

            for (int j = 0; j < k; ++j)
            {
                if (minV == p2[j])
                {
                    index[j]++;
                }
            }
        }

        return nums.back();
    }
};

int main()
{
    Solution sln;
    int n = 5;
    vector<int> primes = {2, 7, 13, 19};
    std::cout << sln.nthSuperUglyNumber(n, primes) << std::endl;
    return 0;
}
