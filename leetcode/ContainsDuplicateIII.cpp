#include <iostream>
#include <map>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();

        if (n <= 1 || t <0 || k < 1)
        {
            return false;
        }

        map<int, int> m;

        for (int i = 0, j = 0; i < n; ++i)
        {
            if (i - j > k && m[nums[j]] == j)
            {
                m.erase(nums[j++]);
            }

            auto a = m.lower_bound(nums[i] - t);

            if (a != m.end() && abs(a->first - nums[i]) <= t)
            {
                return true;
            }

            m[nums[i]] = i;
        }

        return false;
    }

    bool containsNearbyAlmostDuplicate_slow(vector<int>& nums, int k, int t) {
        int n = nums.size();

        if (n <= 1 || t < 0 || k < 1)
        {
            return false;
        }

        for (int i = 1; i <= k; ++i)
        {
            for (int j = 0; j + i < n; ++j)
            {
                if (abs(nums[j] - nums[j + i]) <= t)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sln;
    int k = 0, t = 0;
    cout << "Please enter k: ";
    cin >> k;
    cout << "Please enter t: ";
    cin >> t;
    //vector<int> a = {1, 100, 1000, 10000, 100000, 1000000};
    //vector<int> nums(a, a + SIZE(a));

    const int A = 1000, B = 10000;

    srand(unsigned(time(0)));
    int LEN = random() % A;

    vector<int> nums;
    nums.reserve(LEN);

    for (int i = 0; i < LEN; ++i)
    {
        nums.push_back(random() % B);
    }

    printVector<int>(nums);

    cout << sln.containsNearbyAlmostDuplicate(nums, k, t) << endl;
    cout << sln.containsNearbyAlmostDuplicate_slow(nums, k, t) << endl;
    return 0;
}
