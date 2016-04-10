#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int m = nums.size();

        unordered_set<int> s;

        for (int i = 0; i < k + 1 && i < m; ++i)
        {
            if (!s.insert(nums[i]).second)
            {
                return true;
            }
        }

        for (int i = k + 1; i < m; ++i)
        {
            s.erase(nums[i - k - 1]);

            if (!s.insert(nums[i]).second)
            {
                return true;
            }
        }

        return false;
    }

    // Need to improve.
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        map<int, vector<int> > m;

        int sz = nums.size();

        for (int i = 0; i < sz; ++i)
        {
            int a = nums[i];
            map<int, vector<int> >::iterator itr = m.find(a);

            if (itr == m.end())
            {
                vector<int> v;
                v.push_back(i);
                m.insert(make_pair(a, v));
            }
            else
            {
                // IMPORTANT!! Use reference so we can manipulate the vector v. Otherwise
                // the assignment operator would copy a vector for v and doesn't affect the
                // vector referenced by the map.
                vector<int> &v = itr->second;
                v.push_back(i);
            }
        }

        for (map<int, vector<int> >::iterator itr = m.begin(); itr != m.end(); ++itr)
        {
            vector<int> v = itr->second;
            int szv = v.size();
            int minDis = INT_MAX;

            for (int i = 1; i < szv; ++i)
            {
                int dis = v[i] - v[i - 1];
                minDis = min(minDis, dis);

                if (minDis <= k)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sln;
    //vector<int> a = {};
    //vector<int> a = {1, 2};
    //vector<int> a = {1, 1};
    //vector<int> a = {1, 2, 3};
    //vector<int> nums = {1, 2, 6, 7, 2, 3};
    vector<int> nums = {-1, -1};
    int k = 1;
    //std::cout << "Please enter k: ";
    //cin >> k;
    std::cout << sln.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}
