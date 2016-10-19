#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
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

    vector<int> v = sln.getModifiedArray1(len, updates);
    vector<int> v = sln.getModifiedArray(len, updates);
    printVector<int>(v);
    return 0;
}
