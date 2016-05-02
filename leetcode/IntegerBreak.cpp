#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2)
        {
            return 1;
        }

        vector<int> v = {1, 1, 2, 4, 6, 9};
        // don't forget to allocate space for elements. Otherwise, we can't 
        // directly set value for v[i]. We have to use v.push_back().
        v.reserve(n);

        for (int i = 6; i < n; ++i)
        {
            v[i] = max(v[i - 2] * 2, v[i - 3] * 3);
        }

        return v[n - 1];       
    }
};

int main()
{
    Solution sln;
    int n = 10;
    std::cin >> n;
    std::cout << sln.integerBreak(n) << std::endl;
    return 0;
}
