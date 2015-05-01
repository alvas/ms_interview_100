#include <iostream>
#include <map>
#include <vector>

#include "NormalData.h"

using namespace std;

const int LOCALLENGTH = 4;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        multimap<int, int> m;

        int size = nums.size();
        int start = 0, end = size - 1;

        for (int i = 0; i < size; ++i)
        {
            m.insert(make_pair(nums[i], i));
        }

        // sort the nums, this algorithm only work if the array is sorted.
        std::sort(nums.begin(), nums.begin() + size);

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
    int a[LOCALLENGTH] = {0, 4, 3, 0};
    vector<int> nums(a, a + LOCALLENGTH);
    int target = 0;
    cout << "Please enter target: ";
    cin >> target;
    vector<int> v = sln.twoSum(nums, target);
    printVector<int>(v);
    return 0;
}
