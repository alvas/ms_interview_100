#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<int> vs;

        for (int i = 0; i < N; ++i)
            vs.push_back(i + 1);

        return counts(N, vs);
    }

    int counts(int n, vector<int> &vs) {
        if (n <= 0)
            return 1;

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (vs[i] % n == 0 || n % vs[i] == 0) {
                swap(vs[i], vs[n - 1]);
                ans += counts(n - 1, vs);
                swap(vs[i], vs[n - 1]);
            }
        }

        return ans;
    }

    int countArrangement1(int N) {
        vector<bool> usedNum(N, false);
        vector<int> nums;
        int res = 0;

        for (int i = 0; i < N; ++i) {
            nums.push_back(i + 1);
            usedNum[i] = true;
            arrangeNum(usedNum, nums, res);
            nums.pop_back();
            usedNum[i] = false;
        }

        return res;
    }

    void arrangeNum(vector<bool> &usedNum, vector<int> &nums, int &res) {
        if (nums.size() == usedNum.size()) {
            res++;
            return;
        }

        for (int i = 0; i < usedNum.size(); ++i) {
            if (!usedNum[i]) {
                if ((nums.size() + 1) % (i + 1) != 0 && (i + 1) % (nums.size() + 1) != 0) {
                    continue;
                }

                usedNum[i] = true;
                nums.push_back(i + 1);
                arrangeNum(usedNum, nums, res);
                nums.pop_back();
                usedNum[i] = false;
            }
        }
    }
};

int main()
{
    Solution sln;
    int N = 11;
    cout << sln.countArrangement(N) << endl;
    return 0;
}
