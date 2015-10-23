#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // be careful, don't use sequential scan to do this,
    // because it doesn't work if it is a maze
    void solve(vector<vector<char> >& board) {
        int size1 = board.size(), size2 = 0;

        if (size1 > 0)
        {
            size2 = board[0].size();
        }

        queue<pair<int, int> > q;

        if (size1 > 0)
        {
            for (int i = 0; i < size2; ++i)
            {
                if (board[0][i] == 'O')
                {
                    board[0][i] = 'V';

                    // be careful about the function
                    // make_pair() NOT make_pari<int, int>().
                    // The later format would cause compile error in some compiler.
                    q.push(make_pair(0, i));
                }
            }
        }

        if (size1 > 1)
        {
            int index = size1 - 1;
            
            for (int i = 0; i < size2; ++i)
            {
                if (board[index][i] == 'O')
                {
                    board[index][i] = 'V';
                    q.push(make_pair(index, i));
                }
            }
        }

        if (size2 > 0)
        {
            for (int i = 0; i < size1; ++i)
            {
                if (board[i][0] == 'O')
                {
                    board[i][0] = 'V';
                    q.push(make_pair(i, 0));
                }
            }
        }

        if (size2 > 1)
        {
            int index = size2 - 1;

            for (int i = 0; i < size1; ++i)
            {
                if (board[i][index] == 'O')
                {
                    board[i][index] = 'V';
                    q.push(make_pair(i, index));
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> coor = q.front();
            q.pop();

            int i = coor.first, j = coor.second;

            if (i - 1 > 0 && board[i - 1][j] == 'O')
            {
                board[i - 1][j] = 'V';
                q.push(make_pair(i - 1, j));
            }

            if (i + 1 < size1 && board[i + 1][j] == 'O')
            {
                board[i + 1][j] = 'V';
                q.push(make_pair(i + 1, j));
            }

            if (j - 1 > 0 && board[i][j - 1] == 'O')
            {
                board[i][j - 1] = 'V';
                q.push(make_pair(i, j - 1));
            }

            if (j + 1 < size2 && board[i][j + 1] == 'O')
            {
                board[i][j + 1] = 'V';
                q.push(make_pair(i, j + 1));
            }
        }

        for (int i = 0; i < size1; ++i)
        {
            for (int j = 0; j < size2; ++j)
            {
                if (board[i][j] == 'V')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    Solution sln;
    const int LOCAL_WIDTH = 20, LOCAL_HEIGHT = 20;

    //char a[LOCAL_HEIGHT][LOCAL_WIDTH] =
    //{
        //{'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'O'},
        //{'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'X'},
        //{'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X'},
        //{'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O'},
        //{'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O'},
        //{'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        //{'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O', 'X'},
        //{'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
        //{'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O'}
    //};

    // Warning: conversion from string literal to 'char *' is deprecated
    // We need to declare a as "const" char *
    const char *a[LOCAL_HEIGHT] =
    {
        "OXOOXXXOOOOOXOOOOXOX",
        "XOXOOXXOOXOXOXOXXOOO",
        "OXOOOXXXXOOOOOXXXXOX",
        "XXOOOXXOOOXXXOOXOXXO",
        "OXOXXOXOOOXOOXOOOOOX",
        "XOOXOXOOOXXOXOOXOOOO",
        "XOOOXXOOOOOXOOXOOOOX",
        "XOOOXOXXXOXOXXXXOOOX",
        "XOOXOOOXOOOOOOOOOXOX",
        "OOOXOXXXXXXXXXOOOOXO",
        "XOXOXOOXXXOXXOOXXOOO",
        "OXOOXOOOOOOXXXXOOOXO",
        "XOOOXXXOXOOOXOXOXOOX",
        "OOOOXOXXOXOXOXXXXOOO",
        "OXXOOOOXOOXXXOOXXOXO",
        "XOXXXXXXOXXOXOOXOOOX",
        "XOOOXOXOOXOXOOXOOXXX",
        "OOXOOOOXOOXXOXXXOOOO",
        "OOXOOOOOOXXOXOXOOOXX",
        "XOOOXOXXXOOXOXOXXOOO"
    };

/*
    const char *a[LOCAL_HEIGHT] =
    {
        "OXXXXXOO",
        "OOOXXXXO",
        "XXXXOOOO",
        "XOXOOXXX",
        "OXOXXXOO",
        "OXXOOXXO",
        "OXOXXXOO",
        "OXXXXOXX"
    };
*/

    vector<vector<char> > board(LOCAL_HEIGHT, vector<char>(LOCAL_WIDTH, 'X'));

    for (int i = 0; i < LOCAL_HEIGHT; ++i)
    {
        // be careful board[i].assign().
        board[i].assign(a[i], a[i] + LOCAL_WIDTH);
    }

    print2DVector<char>(board);
    std::cout << endl;

    sln.solve(board);
    //print2DVector<char>(board);
    return 0;
}

