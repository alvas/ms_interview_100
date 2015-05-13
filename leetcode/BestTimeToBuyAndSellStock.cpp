#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // DP
    int maxProfit(vector<int>& prices) {
        int profit = 0, size = prices.size();

        if (size <= 1)
        {
            return profit;
        }

        int local = 0;

        for (int i = 0; i < size; ++i)
        {
            // when ever we meet a new local min, local will be reset to 0
            local = max(0, local + prices[i + 1] - prices[i]);

            // the global max
            profit = max(local, profit);
        }

        return profit;
    }

    int maxProfit1(vector<int>& prices) {
        int profit = 0, size = prices.size();

        if (size <= 1)
        {
            return profit;
        }

        int minV = INT_MAX;

        for (int i = 0; i < size; ++i)
        {
            // update min
            if (prices[i] < minV)
            {
                minV = prices[i];
            }

            int diff = prices[i] - minV;

            // update global max
            if (profit < diff)
            {
                profit = diff;
            }
        }

        return profit;
    }

    // This implementation is supper buggy. Got a lot of failure during the testing.
    int maxProfit_stupid(vector<int>& prices) {
        int profit = 0, size = prices.size();

        if (size <= 1)
        {
            return profit;
        }

        int minIdx = -1, maxIdx = -1;

        if (prices[0] < prices[1])
        {
            //int a[LOCAL_LENGTH] = {1, 4, 3, 5, 2};
            minIdx = 0;
            maxIdx = 1;
            profit = prices[1] - prices[0];
        }
        else
        {
            //int a[LOCAL_LENGTH] = {7, 2, 4, 1};
            minIdx = 1;
        }

        for (int i = 2; i < size; ++i)
        {
            if (maxIdx == -1)
            {
                if (prices[minIdx] < prices[i])
                {
                    //int a[LOCAL_LENGTH] = {7, 2, 4, 1};
                    maxIdx = i;
                    profit = prices[maxIdx] - prices[minIdx];
                }
                else if (prices[i] < prices[minIdx])
                {
                    //int a[LOCAL_LENGTH] = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
                    minIdx = i;
                }
            }
            else if (prices[maxIdx] <= prices[i])
            {
                //int a[LOCAL_LENGTH] = {2, 1, 2, 1, 0, 1, 2};
                maxIdx = i;
                profit = prices[maxIdx] - prices[minIdx];
            }
            else if (prices[i] < prices[minIdx])
            {
                //int a[LOCAL_LENGTH] = {2, 1, 2, 1, 0, 1, 2};
                minIdx = i;
            }
            else
            {
                int diff = prices[i] - prices[minIdx];

                if (profit < diff)
                {
                    //int a[LOCAL_LENGTH] = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
                    maxIdx = i;
                    profit = diff;
                }
            }
        }

        return profit;
    }

    // This implementation use only one dimension vector, it reduces the space requiement. But time limit exceed.
    int maxProfit_naive2(vector<int>& prices) {
        int profit = 0, size = prices.size();

        if (size <= 1)
        {
            return profit;
        }

        vector<int> v(size, 0);

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int diff = prices[i] - prices[j];

                if (diff > profit)
                {
                    profit = diff;
                }
            }
        }

        return profit;
    }

    // this simple implementation doesn't satisfy memory requirement. Got memory limit exceed error.
    int maxProfit_naive(vector<int>& prices) {
        int profit = 0, size = prices.size();

        if (size <= 1)
        {
            return profit;
        }

        vector<vector<int> > v(size, vector<int>(size, 0));

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                v[i][j] = prices[i] - prices[j];

                if (v[i][j] > profit)
                {
                    profit = v[i][j];
                }
            }
        }

        return profit;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 13;
    //int a[LOCAL_LENGTH] = {5, 11, 7, 9, 8, 6, 12, 4, 6, 6};
    //int a[LOCAL_LENGTH] = {2, 1, 2, 0, 1};
    //int a[LOCAL_LENGTH] = {12, 4, 7, 2, 1};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5};
    //int a[LOCAL_LENGTH] = {5, 4, 3, 2, 1};
    //int a[LOCAL_LENGTH] = {5, 4, 5, 4, 5};
    //int a[LOCAL_LENGTH] = {4, 5, 4, 5, 4};
    //int a[LOCAL_LENGTH] = {5, 3, 4, 2, 1};
    //int a[LOCAL_LENGTH] = {5, 5, 5, 5, 5};
    //int a[LOCAL_LENGTH] = {5, 3, 1, 2, 4};
    //int a[LOCAL_LENGTH] = {5, 1, 3, 2, 4};
    //int a[LOCAL_LENGTH] = {5, 1, 2, 3, 4};
    //int a[LOCAL_LENGTH] = {3, 1, 2, 5, 4};
    //int a[LOCAL_LENGTH] = {3, 4, 2, 5, 1};
    //int a[LOCAL_LENGTH] = {3, 4, 1, 5, 2};
    //int a[LOCAL_LENGTH] = {1, 4, 3, 5, 2};
    //int a[LOCAL_LENGTH] = {1, 5, 3, 5, 2};
    //int a[LOCAL_LENGTH] = {7, 2, 4, 1};
    //int a[LOCAL_LENGTH] = {2, 1};
    //int a[LOCAL_LENGTH] = {1, 1};
    //int a[LOCAL_LENGTH] = {1, 2};
    //int a[LOCAL_LENGTH] = {2, 1, 2, 1, 0, 1, 2};
    //int a[LOCAL_LENGTH] = {3, 3, 5, 0, 0, 3, 1, 4};
    int a[LOCAL_LENGTH] = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
    vector<int> prices(a, a + LOCAL_LENGTH);
    cout << sln.maxProfit(prices) << endl;
    return 0;
}
