#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;

        for (auto a: nums) {
            top3.insert(a);

            if (top3.size() > 3) {
                top3.erase(top3.begin());
            }
        }

        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }

    int thirdMax1(vector<int>& nums) {
        unordered_set<int> s;
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int i = 0;

        for (; i < nums.size() && s.size() < 3; ++i) {
            if (s.count(nums[i]) == 0) {
                pq.push(nums[i]);
                s.insert(nums[i]);
            }
        }

        for (; i < nums.size(); ++i) {
            if (pq.top() < nums[i] && s.count(nums[i]) == 0) {
                pq.pop();
                pq.push(nums[i]);
                s.insert(nums[i]);
            }
        }

        if (s.size() < 3) {
            return *max_element(nums.begin(), nums.end());
        }
        else {
            return pq.top();
        }
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {3, 2, 1};
    //vector<int> nums = {2, 1};
    //vector<int> nums = {2, 2, 3, 1};
    vector<int> nums = {1, 2, 2, 5, 3, 5};
    cout << sln.thirdMax(nums) << endl;
    return 0;
}
