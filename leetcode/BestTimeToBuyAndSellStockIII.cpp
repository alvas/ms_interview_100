#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int sz = prices.size();
        
        if (sz <= 1)
        {
            return profit;
        }

        vector<int> g(3, 0);
        vector<int> l(3, 0);

        for (int i = 1; i < sz; ++i)
        {
            int diff = prices[i] - prices[i - 1];

            for (int j = 2; j >= 1; --j)
            {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
    }

    int maxProfit_two_way(vector<int>& prices) {
        int profit = 0;
        int sz = prices.size();
        
        if (sz <= 1)
        {
            return profit;
        }

        // Initialization is important.
        int minV = prices[0], maxV = prices[sz - 1];
        vector<int> forwardMax(sz, 0);
        vector<int> backwardMax(sz, 0);

        // Analyse carefully, we know that the max profit could not be
        // from the same i such that forwardMax[i] + backwardMax[i]

        // boundary
        // minV is the min among [1, i)
        for (int i = 1; i < sz; ++i)
        {
            forwardMax[i] = max(forwardMax[i - 1], prices[i] - minV);

            // after the we calculate forwardMax[i]
            minV = min(minV, prices[i]);
        }

        printVector<int>(forwardMax);

        // boundary
        // maxV is the max among (i, sz - 1]
        for (int i = sz - 2; i >= 0; --i)
        {
            backwardMax[i] = max(backwardMax[i + 1], maxV - prices[i]);

            // aver we calculate backwardMax[i]
            maxV = max(maxV, prices[i]);
        }

        printVector<int>(backwardMax);

        for (int i = 0; i < sz; ++i)
        {
            profit = max(profit, forwardMax[i] + backwardMax[i]);
        }

        return profit;
    }

    int maxProfit_slow(vector<int>& prices) {
        int profit = 0;
        int sz = prices.size();
        int local = 0;

        // Be careful about the boundary here, i < sz - 1.
        for (int i = 2; i < sz - 1; ++i)
        {
            local = getProfit(prices, i, sz);
            profit = max(profit, local);
        }

        return profit;
    }

    int getProfit(vector<int> &prices, int idx, int sz)
    {
        int sum1 = 0, sum2 = 0;
        int local = 0;

        for (int i = 0; i < idx; ++i)
        {
            local = max(0, local + prices[i] - prices[i - 1]);
            sum1  = max(sum1, local);
        }

        local = 0;

        for (int i = idx + 1; i < sz; ++i)
        {
            local = max(0, local + prices[i] - prices[i - 1]);
            sum2  = max(sum2, local);
        }

        return sum1 + sum2;
    }
};

int main()
{
    Solution sln;
    //int a[] = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
    //int a[] = {2, 1, 2, 0, 1};
    int a[] = {1,2,4,2,5,7,2,4,9,0};
    vector<int> prices(a, a + SIZE(a));
    cout << sln.maxProfit_slow(prices) << endl;
    cout << sln.maxProfit(prices) << endl;
    return 0;
}
