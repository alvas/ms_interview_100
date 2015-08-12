#include <deque>
#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Why I didn't think off using deque at the first place.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> r;
        int sz = nums.size();

        if (sz <= 0 || k <= 0)
        {
            return r;
        }
        else if (k > sz)
        {
            k = sz;
        }

        deque<int> d;

        for (int i = 0; i < sz; ++i)
        {
            // if we are adding k + 1 element to the window, remove the first element
            if (!d.empty() && d.front() == i - k)
            {
                d.pop_front();
            }

            // remove elements smaller than nums[i], because we are adding nums[i] to the window and 
            // any previous smaller elements are useless.
            // if nums[d.back()] is not removed, then it is bigger than nums[i]
            // d could have only one elements. and it could be clean up  and become empty here
            // and one element would be added below.
            // smaller elements could be added to d.
            // if there is no bigger element added later, smaller elements would be added one by one.
            // but as long as a bigger element is added, smaller elements are cleaned up.
            // elements left in d are bigger than nums[i]
            while (!d.empty() && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }

            // we are actually adding the index to the deque
            d.push_back(i);

            // because only nums[d.front()] is bigger than nums[i] can survive, nums[d.front()] must be the biggest
            if (i >= k - 1)
            {
                r.push_back(nums[d.front()]);
            }
        }

        return r;
    }

    vector<int> maxSlidingWindow_find_max(vector<int>& nums, int k) {
        vector<int> r;
        int sz = nums.size();

        if (sz <= 0 || k <= 0)
        {
            return r;
        }
        else if (k > sz)
        {
            k = sz;
        }

        r.push_back(*std::max_element(nums.begin(), nums.begin() + k));

        for (int i = k; i < sz; ++i)
        {
            r.push_back(*std::max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
        }

        return r;
    }

    vector<int> maxSlidingWindow_heap(vector<int>& nums, int k) {
        vector<int> r;
        int sz = nums.size();

        if (sz <= 0 || k <= 0)
        {
            return r;
        }
        else if (k > sz)
        {
            k = sz;
        }

        vector<int> v;
        v.insert(v.end(), nums.begin(), nums.begin() + k);
        make_heap(v.begin(), v.end());
        r.push_back(v[0]);
        vector<int>::iterator itr = std::find(v.begin(), v.end(), nums[0]);
        v.erase(itr);

        for (int i = k; i < sz; ++i)
        {
            v.push_back(nums[i]);
            make_heap(v.begin(), v.end());
            r.push_back(v[0]);
            itr = std::find(v.begin(), v.end(), nums[i - k + 1]);
            v.erase(itr);
        }

        return r;
    }
};

int main()
{
    Solution sln;
    //int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int a[] = {1,-9,8,-6,6,4,0,5};
    vector<int> nums(a, a + SIZE(a));
    printVector<int>(nums);
    int k = 0;
    cout << "Please enter k(1 <= k <= " << SIZE(a) << "): ";
    cin >> k;
    vector<int> v = sln.maxSlidingWindow(nums, k);
    printVector<int>(v);
    return 0;
}
