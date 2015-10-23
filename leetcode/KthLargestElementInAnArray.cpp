#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    struct myClass
    {
        bool operator() (int a, int b)
        {
            return a > b;
        }
    } myObject;

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();

        if (size == 0 || size < k)
        {
            return 0;
        }

        vector<int> v;
        v.assign(nums.begin(), nums.begin() + k);

        for (int i = k; i < size; ++i)
        {
            make_heap(v.begin(), v.end(), myObject);

            if (v[0] < nums[i])
            {
                v.push_back(nums[i]);

                // All of this need to be done only if v[0] < nums[i], new element is added to the heap. Otherweise, no need to adjust the heap.
                make_heap(v.begin(), v.end(), myObject);
                // Be careful about the index k here.
                v[0] = v[k];
                v.resize(k);
            }
        }

        // Be careful. Remember to make heap at the end and get the smallest number from the heap.
        make_heap(v.begin(), v.end(), myObject);
        return v[0];
    }

};

int main()
{
    Solution sln;
    int n = 0, k = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    std::cout << "Please enter k: ";
    cin >> k;
    vector<int> nums;
    initializeRandomVector(nums, n);
    printVector<int>(nums);
    std::cout << sln.findKthLargest(nums, k) << endl;
    sort(nums.begin(), nums.end());
    printVector<int>(nums);
    return 0;
}
