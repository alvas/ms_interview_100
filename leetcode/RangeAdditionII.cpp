#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r = ops.size();

        if (r == 0) {
            return m * n;
        }

        int minR = INT_MAX, minC = INT_MAX;

        for (int i = 0; i < r; ++i) {
            minR = min(minR, ops[i][0]);
            minC = min(minC, ops[i][1]);
        }

        return minR * minC;
    }

    int maxCount1(int m, int n, vector<vector<int>>& ops) {
        int r = ops.size();
        vector<vector<int>> M(m, vector<int>(n));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < ops[i][0]; ++j) {
                for (int k = 0; k < ops[i][1]; ++k) {
                    M[j][k]++;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == M[0][0]) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution sln;
    int m = 3, n= 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};
    cout << sln.maxCount(m, n, ops) << endl;
    return 0;
}
