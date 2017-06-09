#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int oldR = nums.size();

        if (oldR <= 0) {
            return nums;
        }

        int oldC = nums[0].size();

        if (oldC <= 0) {
            return nums;
        }

        if (oldR * oldC != r * c) {
            return nums;
        }

        //int count = 0;
        vector<vector<int>> res(r, vector<int>(c));
        vector<int> tmp(r * c);
        int k = 0;

        for (int i = 0; i < oldR; ++i) {
            for (int j = 0; j < oldC; ++j) {
                //res[count / c][count % c] = nums[i][j];
                //count++;
                tmp[k++] = nums[i][j];
            }
        }

        k = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = tmp[k++];
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    int r = 1, c = 4;
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    vector<vector<int>> matrix = sln.matrixReshape(nums, r, c);
    print2DVector<int>(matrix);
    return 0;
}
