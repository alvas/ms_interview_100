#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int sz = costs.size();

        if (sz == 0) {
            return 0;
        }

        vector<vector<int>> res(sz, vector<int>(3));
        res[0][0] = costs[0][0];
        res[0][1] = costs[0][1];
        res[0][2] = costs[0][2];

        for (int i = 1; i < sz; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }

        return min(costs[sz - 1][0], min(costs[sz - 1][1], costs[sz - 1][2]));
    }

    void recursiveMinCost(vector<vector<int>> &costs, int i, int j, int sum, int &res) {
        if (j == costs.size() && sum < res) {
            res = sum;
            return;
        }


    }
};

int main()
{
    Solution sln;
    vector<vector<int>> costs = {{1, 2, 3}, {2, 2, 3}, {1, 3, 3}, {2, 2, 4}};
    cout << sln.minCost(costs) << endl;
    return 0;
}
