#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freqs;
        for (auto a: nums) {
            freqs[a]++;
        }

        int res = 0, lastNum = 0, lastFreq = 0;

        for (auto p: freqs) {
            int freq2 = 0;

            if (lastFreq && p.first == lastNum + 1) {
                freq2 = p.second + lastFreq;
            }

            res = max(res, freq2);
            lastNum = p.first;
            lastFreq = p.second;
        }

        return res;
    }

    int findLHS1(vector<int>& nums) {
        int sz = nums.size();
        
        if (sz == 0)
            return 0;

        std::sort(nums.begin(), nums.end());
        // be careful about the initial value of res, if all numbers equal
        int i = 1, idx1 = 0, idx2 = 0, res = 0;

        for (; i < sz; ++i) {
            if (nums[i] != nums[idx1]) {
                idx2 = i;
                break;
            }
        }

        for (; i < sz; ++i) {
            if (nums[idx2] != nums[i]) {
                if (nums[idx2] - nums[idx1] == 1) {
                    res = max(res, i - idx1);
                }

                idx1 = idx2;
                idx2 = i;
            }
        }

        // be careful about the index sz - 1 here, don't use i, it is out of boundary.
        if (nums[sz - 1] - nums[idx1] == 1) {
            res = max(res, i - idx1);
        }

        return res;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1, 1, 1, 1};
    vector<int> nums = {1, 2, 2, 1};
    //vector<int> nums = {1,3,2,2,5,2,3,7};
    //vector<int> nums = {1, 2, 3, 4};
    cout << sln.findLHS(nums) << endl;
    return 0;
}
