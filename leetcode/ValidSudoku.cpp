#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return verifyRows(board) && verifyColumns(board) && verifyBlocks(board);
    }

    bool verifyRows(vector<vector<char> > &A)
    {
        for (int i = 0; i < 9; ++i)
        {
            int bits = 0;

            for (int j = 0; j < 9; ++j)
            {
                if (A[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    int mask = 1 << (A[i][j] - 48);

                    if (bits & mask)
                    {
                        return false;
                    }
                    else
                    {
                        bits |= mask;
                    }
                }
            }
        }

        return true;
    }

    bool verifyColumns(vector<vector<char> > &A)
    {
        for (int j = 0; j < 9; ++j)
        {
            int bits = 0;

            for (int i = 0; i < 9; ++i)
            {
                if (A[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    int mask = 1 << (A[i][j] - 48);

                    if (bits & mask)
                    {
                        return false;
                    }
                    else
                    {
                        bits |= mask;
                    }
                }
            }
        }

        return true;
    }

    bool verifyBlocks(vector<vector<char> > &A)
    {
        for (int k = 0; k < 3; ++k)
        {
            int startRow = 3 * k;

            for (int l = 0; l < 3; ++l)
            {
                int startColumn = 3 * l;
                
                // Watch out for the location of bits in this function!!
                int bits = 0;

                for (int i = startRow; i < startRow + 3; ++i)
                {
                    for (int j = startColumn; j < startColumn + 3; ++j)
                    {
                        if (A[i][j] == '.')
                        {
                            continue;
                        }
                        else
                        {
                            int mask = 1 << (A[i][j] - 48);

                            if (bits & mask)
                            {
                                return false;;
                            }
                            else
                            {
                                bits |= mask;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    int A[9][9] = 
        {{5, 3, 0, 0, 7, 0, 0, 0, 0},
         {6, 0, 0, 1, 9, 5, 0, 0, 0},
         {0, 9, 8, 0, 0, 0, 0, 6, 0},
         {8, 0, 0, 0, 6, 0, 0, 0, 3},
         {4, 0, 0, 8, 0, 3, 0, 0, 1},
         {7, 0, 0, 0, 2, 0, 0, 0, 6},
         {0, 6, 0, 0, 0, 0, 2, 8, 0},
         {0, 0, 0, 4, 1, 9, 0, 0, 5},
         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    vector<vector<char> > board;

    for (int i = 0; i < 9; ++i)
    {
        vector<char> row;

        for (int j = 0; j < 9; ++j)
        {
            if (A[i][j] == 0)
            {
                row.push_back('.');
            }
            else
            {
                row.push_back(A[i][j] + 48);
            }
        }

        board.push_back(row);
    }

    std::cout << sln.isValidSudoku(board) << endl;
    return 0;
}

