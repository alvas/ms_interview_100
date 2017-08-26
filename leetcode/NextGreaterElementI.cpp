#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;

        for (auto n: nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }

            s.push(n);
        }

        vector<int> res;

        for (auto n : findNums) {
            res.push_back(m.count(n) ? m[n] : -1);
        }

        return res;
    }

    vector<int> nextGreaterElement1(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        int sz1 = findNums.size(), sz2 = nums.size();
        unordered_map<int, int> idxMap;

        for (int i = 0; i < sz2; ++i) {
            idxMap[nums[i]] = i;
        }

        for (int i = 0; i < sz1; ++i) {
            int j = idxMap[findNums[i]] + 1;

            for (; j < sz2; ++j) {
                if (findNums[i] < nums[j]) {
                    res.push_back(nums[j]);
                    break;
                }
            }

            if (j == sz2) {
                res.push_back(-1);
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> findNums = { 4, 1, 2 };
    vector<int> nums = {1, 3, 4, 2};
    vector<int> res = sln.nextGreaterElement(findNums, nums);
    printVector<int>(res);
    return 0;
}
