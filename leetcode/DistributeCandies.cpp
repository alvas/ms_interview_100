#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> candySet(candies.begin(), candies.end());
        int sz1 = candySet.size(), sz2 = candies.size() / 2;
        return sz1 <= sz2 ? sz1 : sz2;
    }
};

int main()
{
    Solution sln;
    vector<int> candies = {1, 1, 2, 2, 3, 3};
    cout << sln.distributeCandies(candies) << endl;
    return 0;
}
