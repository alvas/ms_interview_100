#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int numRow = picture.size();

        if (numRow == 0)
            return 0;

        int numCol = picture[0].size();
        vector<int> rows(numRow);
        vector<int> cols(numCol);


        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                rows[i] += picture[i][j] == 'B';
                cols[j] += picture[i][j] == 'B';
            }
        }

        for (int i = 0; i < numRow; ++i) {
            for (j = 0; j < numCol && rows[i] > 0; ++j) {
                res += picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1;
            }
        }

        return res;
    }

    int findLonelyPixel1(vector<vector<char>>& picture) {
        int numRow = picture.size();

        if (numRow == 0)
            return 0;

        int numCol = picture[0].size();

        int res = 0;

        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                if (picture[i][j] == 'B') {
                    int count = 0;

                    for (int ii = 0; ii < numRow; ++ii) {
                        if (picture[ii][j] == 'B')
                            count++;
                    }

                    for (int jj = 0; jj < numCol; ++jj) {
                        if (picture[i][jj] == 'B')
                            count++;
                    }

                    // be careful about the count, NOT 1.
                    if (count == 2)
                        res++;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<vector<char>> picture = {{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
    cout << sln.findLonelyPixel(picture) << endl;
    return 0;
}
