#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // greedy
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        // much simpler solution.
        // as long as the number is bigger than the previous one, 
        // we sum up the difference.
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }

    int maxProfit1(vector<int>& prices) {
        int size = prices.size();

        if (size <= 1)
        {
            return 0;
        }

        int max = 0;

        // Be careful here, i must bigger than 0, because j = i - 1.
        for (int i = size - 1; i > 0; --i)
        {
            int diff = 0;

            int j = i - 1;

            // Be careful about the index j here.
            for ( ; j >= 0; --j)
            {
                if (prices[j] > prices[j + 1])
                {
                    j++;
                    break;
                }

                diff = prices[i] - prices[j];
            }

            max += diff;
            i = j;
        }

        return max;
    }

    int maxProfit_no_recursive(vector<int>& prices) {
        int size = prices.size();

        if (size == 0)
        {
            return 0;
        }

        vector<int> v(size, 0);

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int diff = prices[i] - prices[j];

                if (diff > 0)
                {
                    int tmp = 0;

                    if (j == 0)
                    {
                        v[i] = diff;
                    }
                    else
                    {
                        // Need to find the local max before v[j] and add it to tmp.
                        int localMax = findMax(v, j - 1);
                        localMax = localMax > v[j - 1] ? localMax : v[j - 1];
                        tmp = diff + localMax;
                    }

                    if (tmp > v[i])
                    {
                        v[i] = tmp;
                    }
                }
            }
        }

        return v[size - 1];
    }

    int findMax(const vector<int> &v, int end)
    {
        int max = 0;

        for (int i = 0; i < end; ++i)
        {
            if (i == 0)
            {
                max = v[i];
            }
            else if (v[i] > max)
            {
                max = v[i];
            }
        }

        return max;
    }

    int maxProfit_naive(vector<int>& prices) {
        int max = 0;
        recursive_sum(prices, 0, 0, max);
        return max;
    }

    void recursive_sum(const vector<int> &price, int index, int tmp, int &max)
    {
        int size = price.size();

        if (index == size)
        {
            if (tmp > max)
            {
                max = tmp;
            }

            return;
        }

        // Two levels of loops. We also need to loop through the start.
        for (int start = index; start < size; ++start)
        {
            for (int j = start + 1; j < size; ++j)
            {
                int diff = price[j] - price[start];

                if (diff <= 0)
                {
                    continue;
                }

                tmp += diff;
                recursive_sum(price, j + 1, tmp, max);
                tmp -= diff;
            }
        }
    }
};

int main()
{
    Solution sln;
    std::vector<int> prices = {5, 4, 7, 9, 8, 1, 12, 4, 6, 6};
    //vector<int> prices = {1, 2};
    std::cout << sln.maxProfit(prices) << endl;
    std::cout << sln.maxProfit1(prices) << endl;
    std::cout << sln.maxProfit_naive(prices) << endl;
    return 0;
}
