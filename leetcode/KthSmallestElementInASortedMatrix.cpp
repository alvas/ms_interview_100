#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();

        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);

            if (cnt < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }

    int search_less_equal(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;

        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                ++j;
            }
            else {
                --i;
            }
        }

        return res;
    }

    int kthSmallest2(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();

        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;

            for (int i = 0; i < matrix.size(); ++i) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (cnt < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }

    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        int ans = 0;
        int row = matrix.size();

        if (row == 0) {
            return ans;
        }

        int col = matrix[0].size();

        if (k > row * col || k <= 0) {
            return ans;
        }

        priority_queue<int> pq;

        for (int i = 0 ; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (k) {
                    pq.push(matrix[i][j]);
                    k--;
                }
                else {
                    if (pq.top() > matrix[i][j]) {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }

        return pq.top();
    }
};

int main() {
    Solution sln;
    int k = 1;
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11,  13},
        {12, 13, 15}
    };

    cout << sln.kthSmallest(matrix, k) << endl;
    return 0;
}
