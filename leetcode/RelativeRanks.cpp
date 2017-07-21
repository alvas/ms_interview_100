#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        int sz = nums.size();

        for (int i = 0; i < sz; ++i) {
            pq.push(make_pair(nums[i], i));
        }

        vector<string> price = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> res;

        while (!pq.empty()) {
            pair<int, int> tmp = pq.top();

            if (tmp.second < 3) {
                res.push_back(price[tmp.second]);
            }
            else {
                res.push_back(to_string(tmp.second + 1));
            }

            pq.pop();
        }

        return res;
    }

    vector<string> findRelativeRanks2(vector<int>& nums) {
        vector<string> price = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int sz = nums.size();
        vector<string> res;
        vector<int> copyNums(nums);
        sort(copyNums.begin(), copyNums.end(), greater<int>());
        map<int, int> m;

        for (int i = 0; i < sz; ++i) {
            m[copyNums[i]] = i;
        }

        for (auto i : nums) {
            int idx = m[i];

            if (idx < 3) {
                res.push_back(price[idx]);
            }
            else {
                res.push_back(to_string(idx + 1));
            }
        }

        return res;
    }

    vector<string> findRelativeRanks1(vector<int>& nums) {
        vector<string> price = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        set<int, std::greater<int>> numSet(nums.begin(), nums.end());
        vector<string> res;

        for (auto i: nums) {
            // be careful about the order of distance parameter. If find() and begin(), it would cause segment fault.
            auto dis = std::distance(numSet.begin(), numSet.find(i));

            if (dis < 3) {
                res.push_back(price[dis]);
            }
            else {
                res.push_back(to_string(dis + 1));
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<string> ranks = sln.findRelativeRanks(nums);
    printVector(ranks);
    return 0;
}
