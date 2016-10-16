#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = A.size();
        vector<int> B(sz, 0);

        for (int i = 1; i < sz; ++i) {
            B[i] = A[i] - A[i - 1];
        }
    }
};

int main() {
    Solution sln;
    vector<int> A = {1, 2, 3, 4};
    cout << sln.numberOfArithmeticSlices(A) << endl;
    return 0;
}
