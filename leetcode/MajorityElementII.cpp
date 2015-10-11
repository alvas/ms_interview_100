#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int sz = nums.size();
        vector<int> v;
        
        if (sz == 0)
        {
            return v;
        }
        else if (sz == 1)
        {
            v.push_back(nums[0]);
            return v;
        }
        else if (sz == 2)
        {
            v.push_back(nums[0]);

            // be careful when two number equal
            if (nums[0] != nums[1])
            {
                v.push_back(nums[1]);
            }

            return v;
        }
        else if (sz == 3)
        {
            // be careful about 3 number
            if (nums[0] == nums[1] || nums[0] == nums[2])
            {
                v.push_back(nums[0]);
            }
            else if (nums[1] == nums[2])
            {
                v.push_back(nums[1]);
            }

            return v;
        }

        int elem1 = 0, elem2 = 0, elemC1 = 0, elemC2 = 0;

        for (int i = 0; i < sz; ++i)
        {
            if (elemC1 == 0)
            {
                // when reset elem1, be careful it should not be the same as elem2,
                // if elem2 exists
                if (elemC2 == 0 || elem2 != nums[i])
                {
                    elem1 = nums[i];
                    elemC1++;
                }
            }
            // be careful elem2 should not be the same as elem1
            else if (elemC2 == 0 && elem1 != nums[i])
            {
                elem2 = nums[i];
                elemC2++;
            }
            else
            {
                if (elem1 == nums[i])
                {
                    elemC1++;
                }
                else if (elem2 == nums[i])
                {
                    elemC2++;
                }
                else
                {
                    elemC1--;
                    elemC2--;
                }
            }
        }


        int count1 = 0, count2 = 0;

        // check whether elem1 and elem2 are both more than n / 3;
        // this is to block the case [1, 2, 3, 4]; 
        // 1 and 2 will be set to elem1 and elem2. then 3 clear them.
        // then 4 would be left.
        for (int i = 0; i < sz; ++i)
        {
            if (elemC1 > 0 && nums[i] == elem1)
            {
                count1++;
            }

            if (elemC2 > 0 && nums[i] == elem2)
            {
                count2++;
            }
        }

        if (count1 > sz / 3)
        {
            v.push_back(elem1);
        }

        if (count2 > sz / 3)
        {
            v.push_back(elem2);
        }

        return v;
    }
};

int main()
{
    Solution sln;
    //vector<int> a = {1, 1};
    //vector<int> a = {3, 2, 3};
    //vector<int> a = {1, 1, 2, 3};
    //vector<int> a = {1, 2, 3, 4};
    vector<int> a = {-1, 1, 1, 1, 2, 1};
    //vector<int> a = {1, 2, 1, 3};
    //vector<int> a = {1, 2, 1, 2, 3};
    //vector<int> a = {1, 1, 2, 2, 3};
    //vector<int> a = {3, 1, 1, 2, 2};
    //vector<int> a = {1, 2, 1, 2, 3, 3};
    //vector<int> a = {1, 1, 1, 2, 2, 3, 3};
    //vector<int> a = {2, 2, 3, 3, 1, 1, 1};
    //vector<int> a = {2, 2, 3, 3, 1, 1, 1};
    //vector<int> a = {2, 2, 1, 1, 1, 3, 3};
    //vector<int> a = {2, 2, 2, 1, 1, 1, 3, 3};
    //vector<int> a = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3};
    vector<int> nums(a, a + SIZE(a));
    //vector<int> nums;
    //initializeRandomVector(nums, 15);
    printVector<int>(nums);
    vector<int> v = sln.majorityElement(nums);
    printVector<int>(v);
    return 0;
}
