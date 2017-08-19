#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class NumMatrix {
public:
    // a better solution would be save column sum
    NumMatrix(vector<vector<int>> matrix) {
        int row = matrix.size();
        
        if (row == 0) {
            return;
        }

        // be careful about how to initialize the matrix
        m_matrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        int col = matrix[0].size();
        m_matrix[0][0] = matrix[0][0];

        for (int i = 1; i < col; ++i) {
            m_matrix[0][i] += m_matrix[0][i - 1] + matrix[0][i];
        }

        for (int i = 1; i < row; ++i) {
            m_matrix[i][0] += m_matrix[i - 1][0] + matrix[i][0];
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                m_matrix[i][j] = matrix[i][j] + m_matrix[i - 1][j] + m_matrix[i][j - 1] - m_matrix[i - 1][j - 1];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int origVal = sumRegion(row, col, row, col);
        int diff = val - origVal;

        for (int i = row; i < m_matrix.size(); ++i) {
            for (int j = col; j < m_matrix[0].size(); ++j) {
                m_matrix[i][j] += diff;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return m_matrix[row2][col2];
        }
        else if (row1 == 0) {
            return m_matrix[row2][col2] - m_matrix[row2][col1 - 1];
        }
        else if (col1 == 0) {
            return m_matrix[row2][col2] - m_matrix[row1 - 1][col2];
        }
        else {
            return m_matrix[row2][col2] + m_matrix[row1 - 1][col1 - 1] - m_matrix[row1 - 1][col2] - m_matrix[row2][col1 - 1];
        }
    }

    void update1(int row, int col, int val) {
        m_matrix[row][col] = val;
    }
    
    int sumRegion1(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                sum += m_matrix[i][j];
            }
        }

        return sum;
    }

private:
    vector<vector<int>> m_matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
int main()
{
    //vector<vector<int>> v = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    vector<vector<int>> v = {{1, 2}};
    NumMatrix matrix(v);
    //cout << matrix.sumRegion(2, 1, 4, 3) << endl;
    //matrix.update(3, 2, 2);

    cout << matrix.sumRegion(0, 0, 0, 0) << endl;
    cout << matrix.sumRegion(0, 1, 0, 1) << endl;
    cout << matrix.sumRegion(0, 0, 0, 1) << endl;
    matrix.update(0, 0, 3);
    matrix.update(0, 1, 5);
    cout << matrix.sumRegion(0, 0, 0, 1) << endl;
    return 0;
}
