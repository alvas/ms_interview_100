#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = A.size();
        // initialization would impact the B[i] == B[i - 1]
        vector<int> B(sz, 0);
        int dup = 0;
        int res = 0;

        for (int i = 1; i < sz; ++i) {
            B[i] = A[i] - A[i - 1];

            // Important, skip B[0] here, because this doesn't make sense.
            if (i > 1 && B[i] == B[i - 1]) {
                dup++;
                res += dup;
            }
            else {
                dup = 0;
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    //vector<int> A = {1, 2, 3, 4};
    //vector<int> A = {1,1,1,1};
    vector<int> A = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << sln.numberOfArithmeticSlices(A) << endl;
    return 0;
}
