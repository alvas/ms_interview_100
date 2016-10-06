#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int profit = 0;

        for (int i = 0; i < sz; ++i) {
        }

        return profit; 
    }
};

int main()
{
    Solution sln;
    vector<int> prices = {1, 2, 3, 0, 2};
    std::cout << sln.maxProfit(prices) << std::endl;
    return 0;
}
