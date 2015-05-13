#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
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
    const int LOCAL_LENGTH = 12;
    int a[LOCAL_LENGTH] = {1, 1, 0, 0, -1, -1, 0, 0, -2, -2, 2, 2};
    vector<int> nums(a, a + LOCAL_LENGTH);
    int target = 0;
    cout << "Please enter target: ";
    cin >> target;
    vector<vector<int> > v = sln.fourSum_naive(nums, target);
    cout << "fourSum_naive:" << endl;
    print2DVector(v);
    vector<vector<int> > v1 = sln.fourSum(nums, target);
    cout << "better solution:" << endl;
    print2DVector(v1);
    return 0;
}
