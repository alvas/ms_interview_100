#include <cassert>
#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> v;
        // soritng is important
        sort(nums.begin(), nums.end());
        kSum(nums, target, 4, 0, v, res);
        return res;
    }

    void kSum(vector<int> &nums, int target, int k, int s, vector<int> &v, vector<vector<int>> &res) {
        if (k <= 0)
        {
            return;
        }

        int m = nums.size();

        if (k == 1)
        {
            assert(false);

            for (int i = s; i < m; ++i)
            {
                if (nums[i] == target)
                {
                    v.push_back(nums[i]);
                    res.push_back(v);
                }
            }

            return;
        }
        else if (k == 2)
        {
            twoSum(nums, target, s, v, res);
            return;
        }

        int i = s;

        while (i < m - k + 1)
        {
            v.push_back(nums[i]);

            // new start value i + 1, new target - nums[i]
            kSum(nums, target - nums[i], k - 1, i + 1, v, res);
            v.pop_back();

            // remove duplicated
            while (++i < m - k + 1 && nums[i] == nums[i - 1])
            {
                ;
            }
        }
    }

    void twoSum(vector<int>& nums, int target, int s, vector<int> &v, vector<vector<int>> &res) {
        int m = nums.size();
        int l = s, r = m - 1;

        while (l < r)
        {
            int t = nums[l] + nums[r];

            if (t == target)
            {
                v.push_back(nums[l]);
                v.push_back(nums[r]);
                res.push_back(v);

                // be careful to pop out the element
                v.pop_back();
                v.pop_back();

                while (++l < r && nums[l] == nums[l - 1])
                {
                    ;
                }

                while (l < --r && nums[r] == nums[r + 1])
                {
                    ;
                }
            }
            else if (t < target)
            {
                while (++l < r && nums[l] == nums[l - 1])
                {
                    ;
                }
            }
            else
            {
                while (l < --r && nums[r] == nums[r + 1])
                {
                    ;
                }
            }
        }
    }

    // We can recursive solve k sum problem through k - 1 sum.
    vector<vector<int> > fourSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int m = nums.size(), i = 0;
        
        while (i < m - 3)
        {
            int j = i + 1;

            while (j < m - 2)
            {
                int t = target - nums[i] - nums[j];

                int l = j + 1, r = m - 1;

                while (l < r)
                {
                    int s = nums[l] + nums[r];

                    if (s == t)
                    {
                        vector<int> v = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(v);

                        while (++l < r && nums[l] == nums[l - 1])
                        {
                            ;
                        }

                    }
                    else if (s < t)
                    {
                        while (++l < r && nums[l] == nums[l - 1])
                        {
                            ;
                        }
                    }
                    else
                    {
                        while (l < --r && nums[r] == nums[r + 1])
                        {
                            ;
                        }
                    }
                }

                while (++j < m - 2 && nums[j] == nums[j - 1])
                {
                    ;
                }
            }

            while (++i < m - 3 && nums[i] == nums[i - 1])
            {
                ;
            }
        }

        return res;
    }

    vector<vector<int> > fourSum1(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int> > sum;

        if (size < 4)
        {
            return sum;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; )
        {
            for (int j = i + 1; j < size; )
            {
                int k = j + 1, l = size - 1;

                while (k < l)
                {
                    int t = nums[i] + nums[j] + nums[k] + nums[l];

                    if (t == target)
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[l]);
                        sum.push_back(v);

                        k++;

                        while (k < l && nums[k] == nums[k - 1])
                        {
                            k++;
                        }
                    }
                    else if (t < target)
                    {
                        k++;

                        while (k < l && nums[k] == nums[k - 1])
                        {
                            k++;
                        }
                    }
                    else
                    {
                        l--;

                        while (k < l && nums[l] == nums[l + 1])
                        {
                            l--;
                        }
                    }
                }
                
                j++;

                while (i< size && nums[j] == nums[j - 1])
                {
                    j++;
                }
            }

            i++;

            while (i < size && nums[i] == nums[i - 1])
            {
                i++;
            }
        }

        return sum;
    }

    vector<vector<int> > fourSum_naive(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int> > sum;

        if (size < 4)
        {
            return sum;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; ++i)
        {
            // skip duplicate quadruplets
            if (i != 0 && nums[i - 1] == nums[i])
            {
                continue;
            }

            for (int j = i + 1; j < size; ++j)
            {
                if (j != i + 1 && nums[j - 1] == nums[j])
                {
                    continue;
                }

                for (int k = j + 1; k < size; ++k)
                {
                    if (k != j + 1 && nums[k - 1] == nums[k])
                    {
                        continue;
                    }

                    for (int l = k + 1; l < size; ++l)
                    {
                        if (l != k + 1 && nums[l - 1] == nums[l])
                        {
                            continue;
                        }

                        int t = nums[i] + nums[j] + nums[k] + nums[l];

                        if (t == target)
                        {
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(nums[l]);
                            sum.push_back(v);
                        }
                    }
                }
            }
        }

        return sum;
    }
};

int main()
{
    Solution sln;
    std::vector<int> nums = {1, 1, 0, 0, -1, -1, 0, 0, -2, -2, 2, 2};
    std::vector<int> targets = {0, 1, 2, 3, 4, 5, 6};

    for (auto t : targets)
    {
        std::cout << "target is : " << t << std::endl;
        vector<vector<int> > v = sln.fourSum1(nums, t);
        std::cout << "fourSum_naive:" << endl;
        print2DVector(v);
        vector<vector<int> > v1 = sln.fourSum(nums, t);
        std::cout << "better solution:" << endl;
        print2DVector(v1);
    }
    return 0;
}
