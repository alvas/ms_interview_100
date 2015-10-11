#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "NormalData.h"

using namespace std;

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
                res.push_back(mp[target - nums[i]] + 1);
                res.push_back(i + 1);
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

int main()
{
    Solution sln;
    vector<int> nums = {0, 4, 3, 0};
    int target = 0;
    cout << "Please enter target: ";
    cin >> target;
    //vector<int> v = sln.twoSum_sort(nums, target);
    vector<int> v1 = sln.twoSum(nums, target);
    printVector<int>(nums);
    //printVector<int>(v);
    printVector<int>(v1);
    return 0;
}
