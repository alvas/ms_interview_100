#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                break;
            }
        }

        while (true) {
            slow = nums[slow];
            t = nums[t];

            if (slow == t) {
                break;
            }
        }

        return slow;
    }

    int findDuplicate2(std::vector<int>& nums) {
        int sz = nums.size();

        for (int i = 0; i < sz; ++i) {
            if (nums[i] == i + 1) {
                continue;
            }

            int oldIndex = i;
            int newIndex = nums[i] - 1;

            while (nums[oldIndex] != oldIndex + 1) {
                if (nums[oldIndex] == nums[newIndex]) {
                    return nums[oldIndex];
                }

                int temp = nums[newIndex];
                nums[newIndex] = nums[oldIndex];
                nums[oldIndex] = temp;
                newIndex = nums[oldIndex] - 1;
            }
        }

        return 0;
    }

    int findDuplicate1(std::vector<int>& nums) {
        int sz = nums.size();

        if (sz < 2) {
            return 0;
        }

        int l = 1, r = sz - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (countNum(nums, m) > m) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }

        return l;
    }

    int countNum(vector<int> &nums, int a) {
        return count_if(nums.begin(), nums.end(), [a](int i) { return i <= a; });
    }

    // This solution doesn't qualify because it modifies the array.
    int findDuplicate_sort(std::vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int dup = nums[0];

        for (int i = 1; i < sz; ++i) {
            if (dup == nums[i]) {
                break;
            }

            dup = nums[i];
        }

        return dup;
    }
};

int main()
{
    Solution sln;
    std::vector<int> nums = {1, 2, 3, 4, 5, 3, 7, 3};
    std::cout << sln.findDuplicate(nums) << std::endl;
    return 0;
}
