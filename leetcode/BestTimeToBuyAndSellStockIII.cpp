#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        return profit;
    }

    int maxProfit_slow(vector<int>& prices) {
        int profit = 0;
        int sz = prices.size();
        int local = 0;

        for (int i = 1; i < sz; ++i)
        {
            local = max(0, local + prices[i] - prices[i - 1]);
            profit = max(profit, local);
        }

        for (int i = 2; i < sz - 2; ++i)
        {
            int tmp = getProfit(prices, i, sz);
            profit = max(tmp, profit);
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

        for (int i = idx; i < sz; ++i)
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
    int a[] = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
    vector<int> prices(a, a + SIZE(a));
    cout << sln.maxProfit_slow(prices) << endl;
    cout << sln.maxProfit(prices) << endl;
    return 0;
}
