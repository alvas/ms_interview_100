#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int profit = 0;
        int sz = prices.size();
        
        if (sz <= 1 || k <= 0)
        {
            return profit;
        }

        // If k is bigger than sz, then it is only possible to make sz - 1 transaction.
        if (k >= sz / 2)
        {
            for (int i = 1; i < sz; ++i)
            {
                profit += max(prices[i] - prices[i - 1], 0);
            }

            return profit;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);

        for (int price : prices)
        {
            for (int i = 0; i < k; ++i) {
                buy[i] = max(buy[i], (i > 0 ? sell[i - 1] : 0) - price);
                sell[i] = max(sell[i], buy[i] + price);

            }
        }

        return sell.back();
    }

    int maxProfit1(int k, vector<int> &prices)
    {
        int profit = 0;
        int sz = prices.size();
        
        if (sz <= 1 || k <= 0)
        {
            return profit;
        }

        // If k is bigger than sz, then it is only possible to make sz - 1 transaction.
        if (k > sz)
        {
            return solveMaxProfit(prices);
        }

        // global[i][j]: on the ith day, having the jth transaction(the jth transaction may not be necessary happening on the ith day), the global max profit
        // local[i][j]: on the ith day, have the jth transaction on the ith day, the local max profit
        //
        // local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
        // global[i][j] = max(local[i][j], global[i - 1][j]);
        //
        // local[i- 1][j] + diff means on the (i- 1)th day, already have the j transaction, but if on the ith day, we are haveing transaction prices[i] - prices[i - 1], 
        // no matter it is earning money or loosing money, then we are still have j transaction, because it is continous.
        // g[0], l[0] are 0 because no transaction.
        // At most k trasaction, we have the array size k + 1.
        vector<int> g(k + 1, 0);
        vector<int> l(k + 1, 0);

        for (int i = 1; i < sz; ++i)
        {
            int diff = prices[i] - prices[i - 1];

            // calculating from k to 1. When we expanding the day, we can have more and more transaction.
            for (int j = k; j >= 1; --j)
            {
                // calculate local[i - 1][j], local[i - 1][j - 1]
                // then local[i][j], local[i][j - 1]
                // if g[i - 1][j] < l[i - 1][j], this means the j transaction happens on day i - 1.
                // And when we compute l[i][j], if g[i - 1][j] == l[i - 1][j], 
                // then g[i - 1][j - 1] could NOT happen on day i - 1.
                // If g[i - 1][j] equals to l[i - 1][j], then j transaction must happen on day i - 1.
                // then g[i - 2][j - 1] can happen on day i - 2.
                // If g[i - 1][j -1] != l[i - 1][j - 1], it means, on transaction happens on day i - 1.
                // then g[i - 2][j - 1] happens on day i - 2.
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);

                cout << l[j] << ", " << g[j] << "\t";
            }

            cout << endl;
        }

        return g[k];
    }

    int solveMaxProfit(vector<int> &prices)
    {
        int res = 0, sz = prices.size();

        for (int i = 1; i < sz; ++i)
        {
            if (prices[i] - prices[i - 1] > 0)
            {
                res += prices[i] - prices[i - 1];
            }
        }

        return res;
    }

    int maxProfit_memory_limit_exceed(int k, vector<int>& prices) {
        int profit = 0;
        int sz = prices.size();
        
        if (sz <= 1 || k <= 0)
        {
            return profit;
        }

        if (k > sz)
        {
            k = sz;
        }

        vector<vector<int> > global(sz, vector<int>(k + 1, 0));
        vector<vector<int> > local(sz, vector<int>(k + 1, 0));
        
        for (int i = 1; i < sz; ++i)
        {
            int diff = prices[i] - prices[i - 1];

            for (int j = 1; j <= k; ++j)
            {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }

        return global[sz - 1][k];
    }
};

int main()
{
    Solution sln;
    //int k = 0;
    //std::cout << "Please enter k: ";
    //std::cin >> k;
    std::vector<int> prices = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
    printVector<int>(prices);
    cout << endl;
    //long k = 1000000000; 
    long k = 5; 
    //std::vector<int> prices = {106,373,495,46,359,919,906,440,783,583,784,73,238,701,972,308,165,774,990,675,737,990,713,157,211,880,961,132,980,136,285,239,628,221,948,939,28,541,414,180,171,640,297,873,59,814,832,611,868,633,101,67,396,264,445,548,257,656,624,71,607,67,836,14,373,205,434,203,661,793,45,623,140,67,177,885,155,764,363,269,599,32,228,111,102,565,918,592,604,244,982,533,781,604,115,429,33,894,778,885,145,888,577,275,644,824,277,302,182,94,479,563,52,771,544,794,964,827,744,366,548,761,477,434,999,86,1000,5,99,311,346,609,778,937,372,793,754,191,592,860,748,297,610,386,146,220,7,113,657,438,482,700,158,884,877,964,777,139,809,489,383,92,581,970,899,947,864,443,490,825,674,906,402,270,416,611,949,476,775,899,837,796,227,232,226,11,266,889,215,6,182,430,5,706,994,128,359,841,439,263,491,689,638,485,763,695,135,800,763,54,569,387,112,316,193,675,546,531,954,571,208,282,557,892,469,875,765,592,374,276,892,843,625,180,249,292,477,882,837,112,46,667,187,93,418,790,903,12,978,510};
    std::cout << sln.maxProfit(k, prices) << endl;
    return 0;
}
