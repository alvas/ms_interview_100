#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> res;

        while (l < r)
        {
            int sum = numbers[l] + numbers[r];

            if (sum == target)
            {
                res.push_back(l + 1);
                res.push_back(r + 1);
                return res;
            }
            else if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    int target = 9;
    vector<int> num = {2, 7, 11, 15};
    vector<int> &&r = sln.twoSum(num, target);
    printVector<int>(r);
    return 0;
}
