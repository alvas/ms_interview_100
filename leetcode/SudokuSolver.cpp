#include <iostream>
#include <set>
#include <vector>

#include "NormalData.h"

using namespace std;

const int SIZE = 9;

class Solution {
public:
    // Need to improve.
    void solveSudoku(vector<vector<char> >& board) {
        set<char> rowS[9];
        set<char> colS[9];
        set<char> blckS[9];

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    char a = board[i][j];
                    rowS[i].insert(a);
                    colS[j].insert(a);
                    
                    // The idx of blckS is kind of tricky. Be careful.
                    int idx = ((i / 3) * 3) + (j / 3);
                    blckS[idx].insert(a);
                }
            }
        }

        bool finished = false;
        solve(board, 0, 0, rowS, colS, blckS, finished);
    }

    void solve(vector<vector<char> > &board, int r, int c, set<char> rowS[9], set<char> colS[9], set<char> blckS[9], bool &finished)
    {
        // use finished to terminate the algorithem when it finds the solution.
        if (finished)
        {
            return;
        }

        //int r = 0, c = 0;
        //bool found = false;

        //for (int i = 0; i < 9 && !found; ++i)
        //{
            //for (int j = 0; j < 9 && !found; ++j)
            //{
                //if (board[i][j] == '.')
                //{
                    //r = i;
                    //c = j;
                    //found = true;
                //}
            //}
        //}

        //if (!found)
        //{
            //finished = true;
            //return;
        //}

        while (r < 9 && board[r][c] != '.')
        {
            c++;

            if (c >= 9)
            {
                c = 0;
                r++;
            }
        }

        if (r >= 9)
        {
            finished = true;
            return;
        }

        for (int i = 1; i <= 9; ++i)
        {
            char a = i + 48;
            int idx = ((r / 3) * 3) + (c / 3);

            if (rowS[r].find(a) == rowS[r].end() &&
                colS[c].find(a) == colS[c].end() &&
                blckS[idx].find(a) == blckS[idx].end())
            {
                board[r][c] = a;
                rowS[r].insert(a);
                colS[c].insert(a);
                blckS[idx].insert(a);
                solve(board, r, c + 1, rowS, colS, blckS, finished);

                if (finished)
                {
                    return;
                }

                rowS[r].erase(a);
                colS[c].erase(a);
                blckS[idx].erase(a);
                board[r][c] = '.';
            }
        }

        return;
    }
};

int main()
{
    Solution sln;

    int A[SIZE][SIZE] = 
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

    for (int i = 0; i < SIZE; ++i)
    {
        vector<char> row;

        for (int j = 0; j < SIZE; ++j)
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

    print2DVector<char>(board);
    cout << endl << endl;
    sln.solveSudoku(board);
    print2DVector<char>(board);

    return 0;
}
