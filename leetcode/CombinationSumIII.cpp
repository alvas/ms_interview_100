#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > v;

        if (k <= 0 || k > n || k * 9 > n)
        {
            return v;
        }

        return v;
    }
};

int main()
{
    Solution sln;
    int k = 0, n = 0;
    cout << "Please enter k: ";
    cin >> k;
    cout << "Please enter n: ";
    cin >> n;
    vector<vector<int> > v = sln.combinationSum3(k, n);
    return 0;
}
