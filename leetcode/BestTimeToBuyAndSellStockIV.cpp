#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    }
};

int main()
{
    Solution sln;
    int k = 0;
    cout << "Please enter k: ";
    cin >> k;
    int a[] = {};
    vector<int> prices(a, a + SIZE(a));
    cout << sln.maxProfit(k, prices) << endl;
    return 0;
}
