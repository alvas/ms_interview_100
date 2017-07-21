#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> maxlhs(n), minrhs(n);

        for (int i = sz - 1, minr = INT_MAX; i >= 0; --i) {
            minrhs[i] = minr = min(minr, nums[i]);
        }

        for (int i = 0, maxl = INT_MIN; i < sz; ++i) {
            maxlhs[i] = maxl = max(maxl, nums[i]);
        }

        int i = 0, j = n - 1;

        while (i < n && nums[i] <= minrhs[i])
            i++;

        while (j > i && nums[j] >= maxlhs[j])
            j--;

        return j + 1 - i;
    }

    int findUnsortedSubarray1(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int i = 0, j = nums.size() - 1;

        for (; i < nums.size(); ++i) {
            if (nums[i] != tmp[i]) {
                break;
            }
        }

        for (; j >= 0; --j) {
            if (nums[j] != tmp[j]) {
                break;
            }
        }

        // be careful about ascending array [1, 2, 3, 4]
        return j > i ? j - i + 1 : 0;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << sln.findUnsortedSubarray(nums) << endl;
    return 0;
}
