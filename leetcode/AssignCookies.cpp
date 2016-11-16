#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int sz1 = g.size(), sz2 = s.size();
        int res = 0;

        for (int i = 0, j = 0; i < sz1 && j < sz2; ++j) {
            if (s[j] >= g[i]) {
                res++;
                i++;
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    //vector<int> g = {1, 2};
    //vector<int> s = {1, 2, 3};
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << sln.findContentChildren(g, s) << endl;
    return 0;
}
