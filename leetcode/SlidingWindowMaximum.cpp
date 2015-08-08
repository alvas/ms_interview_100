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

        deque<int> d(nums.begin(), nums.begin() + k);
        r.push_back(*std::max_element(d.begin(), d.end()));
        d.pop_front();

        for (int i = k; i < sz; ++i)
        {
            d.push_back(nums[i]);
            r.push_back(*std::max_element(d.begin(), d.end()));
            d.pop_front();
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
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> nums(a, a + SIZE(a));
    printVector<int>(nums);
    int k = 0;
    cout << "Please enter k(1 <= k <= " << SIZE(a) << "): ";
    cin >> k;
    vector<int> v = sln.maxSlidingWindow(nums, k);
    printVector<int>(v);
    return 0;
}
