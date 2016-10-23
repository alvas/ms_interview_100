#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // I didn't get this solution.
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1, 0);

        for (auto update: updates) {
            // add update[0] at the first
            res[update[0]] += update[2];
            // minus it at the end
            res[update[1] + 1] -= update[2];
        }

        for (int i = 1; i < length; ++i) {
            res[i] += res[i - 1];
        }

        res.resize(length);
        return res;
    }

    vector<int> getModifiedArray1(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        int sz = updates.size();

        for (int i = 0; i < sz; ++i) {
            int b = updates[i][0], e = updates[i][1], inc = updates[i][2];

            for (int j = b; j <= e; ++j) {
                res[j] += inc;
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    int len = 5;
    vector<vector<int>> updates = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}
    };

    vector<int> v = sln.getModifiedArray(len, updates);
    vector<int> v1 = sln.getModifiedArray1(len, updates);
    printVector<int>(v);
    return 0;
}
