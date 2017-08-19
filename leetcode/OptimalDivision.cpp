#include <limits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        //vector<vector<vector<double>>> bp(2, vector<vector<double>>(nums.size(), vector<double>(nums.size())));

        //for (int i = 0; i < nums.size(); ++i) {
            //bp[0][i][i] = nums[i];
            //bp[1][i][i] = nums[i];
        //}

        //for (int i = 1; i < nums.size(); ++i) {
            //for (int j = i - 1; j >= 0; --j) {
                //double minV = std::numeric_limits<double>::max();
                //double maxV = std::numeric_limits<double>::min();

                //for (int k = j; k + 1 <= i; ++k) {
                    //double tmp1 = bp[0][j][k] / bp[1][k + 1][i], minV;
                    //double tmp2 = bp[1][j][k] / bp[0][k + 1][i], maxV;

                    //if (tmp1 < minV)
                    //{
                        //minV = tmp1;
                    //}

                    //if (maxV < tmp2)
                    //{
                        //maxV = tmp2;
                    //}
                //}

                //bp[0][j][i] = minV;
                //bp[1][j][i] = maxV;
            //}
        //}

        // the solution is always X1/(X2/X3/X4.../XN)
        string res;

        if (nums.empty())
            return res;

        res += to_string(nums[0]);

        if (nums.size() > 1)
            res += "/";

        if (nums.size() > 2)
            res += "(";

        for (int i = 1; i < nums.size(); ++i) {
            res += to_string(nums[i]);

            if (i != nums.size() - 1) {
                res += "/";
            }
        }

        if (nums.size() > 2)
            res += ")";

        return res;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1000,100,10,2};
    vector<int> nums = {1000};
    //vector<int> nums = {2, 3, 4};
    cout << sln.optimalDivision(nums) << endl;
    return 0;
}
