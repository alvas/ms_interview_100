#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int findPairs1(vector<int>& nums, int k) {
        int res = 0;
        map<int, int> m;
        int numDup = 0;

        for (auto i: nums) {
            m[i]++;
        }

        if (!k) {
            for (auto i: m) {
                if (i.second > 1) {
                    numDup++;
                }
            }

            return numDup;
        }
        else if (k < 0) {
            // absolute distance can't be negative
            return 0;
        }
        else {
            for (auto i: m) {
                if (m.find(i.first + k) != m.end()) {
                    res++;
                }
            }

            return res;
        }
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {3, 1, 4, 1, 5};
    //int k = 2;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = -1;
    cout << sln.findPairs(nums, k) << endl;
    return 0;
}
