#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int size = matrix.size();
        int half = size / 2;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < half; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][size - 1 - j];
                matrix[i][size - 1 - j] = tmp;
            }
        }

        for (int i = 0; i < size; ++i)
        {
            int len = size - 1 - i;

            for (int j = 0; j < len; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[size - 1 - j][size - 1 - i];
                matrix[size - 1 - j][size - 1 - i] = tmp;
            }
        }
    }

    void rotate_common(vector<vector<int> >& matrix) {
        vector<vector<int> > v = matrix;

        int size = matrix.size();
        matrix.clear();

        for (int i = 0; i < size; ++i)
        {
            vector<int> t;

            for(int j = size - 1; j >= 0; --j)
            {
                t.push_back(v[j][i]);
            }

            matrix.push_back(t);
        }
    }
};

int main()
{
    Solution sln;
    vector<vector<int> > matrix;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        vector<int> v;
        initializeRandomVector(v, n);
        matrix.push_back(v);
    }

    print2DVector<int>(matrix);
    //sln.rotate_common(matrix);
    sln.rotate(matrix);
    std::cout << endl;
    print2DVector<int>(matrix);
    return 0;
}

