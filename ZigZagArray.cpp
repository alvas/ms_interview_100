#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

void zigZag(vector<vector<int>> &v, vector<int> &ans) {
    int row = v.size();

    if (row == 0) {
        return;
    }
    else if (row == 1) {
        ans = v[0];
        return;
    }

    int col = v[0].size();

    if (col == 0) {
        return;
    }
    else if (col == 1) {
        for (int k = 0; k < row; ++k) {
            ans.push_back(v[k][0]);
        }

        return;
    }

    const int dir[4][2] = {{1, 0}, {-1, 1}, {0, 1}, {1, -1}};
    int i = 0, j = 0, idx = 3;

    while (i < row && j < col) {
        ans.push_back(v[i][j]);

        if (j == 0) {
            if (i == row - 1) {
                if (idx == 0) {
                    idx = 1;
                }
                else if (idx == 3) {
                    idx = 2;
                }
            }
            else {
                if (idx == 3) {
                    idx = 0;
                }
                else if (idx == 0) {
                    idx = 1;
                }
            }
        }
        else if (j == col - 1){
            if (i == 0) {
                if (idx == 1) {
                    idx = 0;
                }
                else if (idx == 2) {
                    idx = 3;
                }
            }
            else {
                if (idx == 1) {
                    idx = 0;
                }
                else if (idx == 0) {
                    idx = 3;
                }
            }
        }
        else if (i == 0) {
            if (idx == 1) {
                idx = 2;
            }
            else if (idx == 2) {
                idx = 3;
            }
        }
        else if (i == row - 1) {
            if (idx == 3) {
                idx = 2;
            }
            else if (idx == 2) {
                idx = 1;
            }
        }

        j += dir[idx][1];
        i += dir[idx][0];

    }
}

int main() {
    vector<vector<int>> v = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
        //
        //{1, 2, 3, 4, 5, 6},
        //{7, 8, 9, 10, 11, 12},
        //{13, 14, 15, 16, 17, 18},
        //{19, 20, 21, 22, 23, 24},
        //{25, 26, 27, 28, 29, 30}
        //
        //{1, 2, 3, 4, 5},
        //{6, 7, 8, 9, 10},
        //{11, 12, 13, 14, 15},
        //{16, 17, 18, 19, 20},
        //{21, 22, 23, 24, 25},
        //{26, 27, 28, 29, 30}
        //
        //{1, 2, 3, 4, 5},
        //
        //{1, 2, 3, 4, 5},
        //{6, 7, 8, 9, 10},
        //
        //{1},
        //{2},
        //{3},
        //{4},
        //{5}
        //
        //{1, 2},
        //{3, 4},
        //{5, 6},
        //{7, 8},
        //{9, 10}
    };

    vector<int> ans;
    zigZag(v, ans);
    printVector<int>(ans);
    return 0;
}
