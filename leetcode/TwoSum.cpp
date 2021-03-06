#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "NormalData.h"
#include "UnitTest.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

        // a map from value to index
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (mp.count(target - nums[i]) != 0)
            {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
                return res;
            }

            mp[nums[i]] = i;
        }

        return res;
    }

    vector<int> twoSum_sort(vector<int>& nums, int target) {
        multimap<int, int> m;
        int size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            m.insert(make_pair(nums[i], i));
        }

        // sort the nums, this algorithm only work if the array is sorted.
        std::sort(nums.begin(), nums.end());

        int start = 0, end = size - 1;
        vector<int> result(2, 0);

        while (start < end)
        {
            int sum = nums[start] + nums[end];

            if (sum == target)
            {
                map<int, int>::iterator it = m.find(nums[start]);
                result[0] = it->second + 1;
                // There may be duplicated elements. Remove the index from map we have alreay found.
                m.erase(it);
                result[1] = m.find(nums[end])->second + 1;
                break;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        // index1 must less than index2
        std::sort(result.begin(), result.begin() + 2);
        return result;
    }
};

//int main()
//{
    //Solution sln;
    //std::vector<int> nums = {0, 4, 3, 0};
    //int target = 0;
    //std::cout << "Please enter target: ";
    //std::cin >> target;
    ////vector<int> v = sln.twoSum_sort(nums, target);
    //std::vector<int> v1 = sln.twoSum(nums, target);
    //printVector<int>(nums);
    ////printVector<int>(v);
    //printVector<int>(v1);
    //return 0;
//}


SUITE(TEST_CASES)
{
    class MyFixture
    {
    public:
        Solution sln;
    };

    TEST_FIXTURE(MyFixture, CASE1)
    {
        std::vector<int> nums = {0, 4, 3, 0};
        int target = 7;
        std::cout << "Please enter target: " << target << std::endl;
        //vector<int> v = sln.twoSum_sort(nums, target);
        std::vector<int> v1 = sln.twoSum(nums, target);
        std::vector<int> v2 = {1, 2};
        CHECK_EQUAL(v1 == v2, true);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        std::vector<int> nums = {0, 4, 3, 0};
        int target = 8;
        std::cout << "Please enter target: " << target << std::endl;
        //vector<int> v = sln.twoSum_sort(nums, target);
        std::vector<int> v1 = sln.twoSum(nums, target);
        std::vector<int> v2;
        CHECK_EQUAL(v1 == v2, true);
    }
}
