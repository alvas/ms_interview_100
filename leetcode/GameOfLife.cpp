#include <iostream>
#include <random>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;

        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int count = 0;

                for (int k = 0; k < 8; ++k)
                {
                    int x = i + dx[k], y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2))
                    {
                        ++count;
                    }
                }

                if (board[i][j] && (count < 2 || count > 3))
                {
                    board[i][j] = 2;
                }
                else if (!board[i][j] && count == 3)
                {
                    board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                board[i][j] %= 2;
            }
        }
    }

    void gameOfLife1(vector<vector<int>>& board) {
        vector<vector<int>> v = board;
        int m = board.size(), n = 0;

        if (m > 0)
        {
            n = board[0].size();
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int c = 0;

                // rollover with module operation doesn't work if th size is smaller than 3.
                //int a1 = (i + m - 1) % m, a2 = (j + n - 1) % n,
                    //a3 = (i + 1) % m, a4 = (j + 1) % n;

                //c = board[a1][a2] + board[a1][j] + board[a1][a4] +
                    //board[i][a2] + board[i][a4] +
                    //board[a3][a2] + board[a3][j] + board[a3][a4];


                if (i > 0)
                {
                    if (j > 0)
                    {
                        c += board[i - 1][j - 1];
                    }

                    // don't use else if here, because j could satisfy both condition at the same time.
                    if (j < n - 1)
                    {
                        c += board[i - 1][j + 1];
                    }

                    c += board[i - 1][j];
                }

                if (j > 0)
                {
                    c += board[i][j - 1];
                }

                if (j < n - 1)
                {
                    c += board[i][j + 1];
                }

                if (i < m - 1)
                {
                    if (j > 0)
                    {
                        c += board[i + 1][j - 1];
                    }

                    if (j < n - 1)
                    {
                        c += board[i + 1][j + 1];
                    }

                    c += board[i + 1][j];
                }

                if (board[i][j])
                {
                    if (c < 2)
                    {
                        v[i][j] = 0;
                    }
                    else if (c == 2 || c == 3)
                    {
                        v[i][j] = 1;
                    }
                    else if (c > 3)
                    {
                        v[i][j] = 0;
                    }
                }
                else
                {
                    if (c == 3)
                    {
                        v[i][j] = 1;
                    }
                }
            }
        }

        board.swap(v);
    }
};

int main()
{
    Solution sln;
    //int m = 30, n = 20;
    //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //std::default_random_engine generator(seed);
    //std::uniform_int_distribution<int> distribution(0, m * n);
    //int a = distribution(generator) / 2;
    //vector<vector<int>> board(m, vector<int>(n, 0));

    //for (int i = 0; i < a; ++i)
    //{
        //int b = distribution(generator) - 1;
        //int col = b % n;
        //int row = b / n;
        //board[row][col] = 1;
    //}

    //vector<vector<int>> board = {{1, 1}, {1, 0}};
    vector<vector<int>> board = {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}};

    print2DVector<int>(board);
    std::cout << std:: endl;
    sln.gameOfLife(board);
    print2DVector<int>(board);
    return 0;
}
