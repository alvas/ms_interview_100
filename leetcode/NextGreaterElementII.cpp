#include <iostream>
#include <stack>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> ans(sz, -1);
        stack<int> s;

        for (int i = 0; i < sz * 2; ++i) {
            int num = nums[i % sz];

            while (!s.empty() && nums[s.top()] < num) {
                ans[s.top()] = num;
                s.pop();
            }

            if (i < sz) {
                s.push(i);
            }
        }

        return ans;
    }

    vector<int> nextGreaterElements2(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> ans;

        // be careful about empty array
        if (sz == 0) {
            return ans;

        }

        ans.resize(sz);
        int i = 0;

        for ( ; i < sz; ++i) {
            if (nums[i] > nums[sz - 1]) {
                ans[sz - 1] = nums[i];
                break;
            }
        }

        if (i == sz) {
            ans[sz - 1] = -1;
        }

        for (i = sz - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                ans[i] = nums[i + 1];
            }
            else {
                int j = i + 1;

                while (j < sz) {
                    if (ans[j] > nums[i]) {
                        ans[i] = ans[j];
                        break;
                    }

                    j++;
                }

                if (j == sz) {
                    j = 0;

                    for ( ; j < sz; ++j) {
                        if (nums[j] > nums[i]) {
                            ans[i] = nums[j];
                            break;
                        }
                    }

                    if (j == sz) {
                        ans[i] = -1;
                    }
                }
            }
        }

        return ans;
    }

    vector<int> nextGreaterElements1(vector<int>& nums) {
        vector<int> ans;
        size_t sz = nums.size();

        for (int i = 0; i < sz; ++i) {
            int value = nums[i];
            int j = 0;

            for ( ; j < sz; ++j) {
                int idx = (i + 1 + j) % sz;

                if (value < nums[idx]) {
                    ans.push_back(nums[idx]);
                    // don't forget the break;
                    break;
                }
            }

            if (j == sz) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {1, 2, 1};
    vector<int> ans = sln.nextGreaterElements(nums);
    vector<int> ans1 = sln.nextGreaterElements1(nums);
    printVector<int>(ans);
    printVector<int>(ans1);
    return 0;
}
