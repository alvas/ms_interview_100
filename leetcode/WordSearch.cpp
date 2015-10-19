#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    bool exist_recursive(vector<vector<char> >& board, string word) {
        int row = board.size(), col = 0, sz = word.size();

        if (sz == 0)
        {
            return true;
        }
        else if (row <= 0)
        {
            return false;
        }
        else
        {
            col = board[0].size();
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == word[0])
                {
                    board[i][j] = 0;

                    bool found = search(board, word, i, j, row, col, 1, sz);

                    if (found)
                    {
                        return true;
                    }

                    board[i][j] = word[0];
                }
            }
        }

        return false;
    }

    bool search(vector<vector<char> > &board, string &word, int i, int j, int row, int col, int idx, int sz)
    {
        if (idx == sz)
        {
            return true;
        }

        bool found = false;

        if (i > 0 && board[i - 1][j] != 0 && board[i - 1][j] == word[idx])
        {
            board[i - 1][j] = 0;
            found = search(board, word, i - 1, j, row, col, idx + 1, sz);
            board[i - 1][j] = word[idx];
        }

        if (!found && j > 0 && board[i][j - 1] && board[i][j - 1] == word[idx])
        {
            board[i][j - 1] = 0;
            found = search(board, word, i, j - 1, row, col, idx + 1, sz);
            board[i][j - 1] = word[idx];
        }

        // missing !found here causes exceed time limit.
        if (!found i < row - 1 && board[i + 1][j] && board[i + 1][j] == word[idx])
        {
            board[i + 1][j] = 0;
            found = search(board, word, i + 1, j, row, col, idx + 1, sz);
            board[i + 1][j] = word[idx];
        }

        if (!found && j < col - 1 && board[i][j + 1] && board[i][j + 1] == word[idx])
        {
            board[i][j + 1] = 0;
            found = search(board, word, i, j + 1, row, col, idx + 1, sz);
            board[i][j + 1] = word[idx];
        }

        return found;
    }
};

int main()
{
    Solution sln;

    vector<const char *> a = {"ABCE", "SFCS", "ADEE"};
    vector<vector<char> > board;

    for (int i = 0; i < a.size(); ++i)
    {
        const char *b = a[i];
        int len = strlen(b);

        vector<char> row(b, b + len);
        board.push_back(row);
    }

    //string word("ABCCED");
    //string word("SEE");
    string word("ABCB");
    //cout << "Please enter the word: ";
    //cin >> word;

    cout << sln.exist(board, word) << endl;
    return 0;
}
