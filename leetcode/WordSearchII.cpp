#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
    class TrieNode {
    public:
        TrieNode() : str("") {
            for (auto &a : child)
            {
                a = NULL;
            }
        }

        string str;
        TrieNode *child[26];
    };

    class Trie {
    public:
        Trie() : root(new TrieNode()) {
        }

        // Inserts a word into the trie.
        void insert(string word) {
            TrieNode *p = root;

            for (auto &a : word)
            {
                int i  = a - 'a';

                if (!p->child[i])
                {
                    p->child[i] = new TrieNode();
                }

                p = p->child[i];
            }

            p->str = word;
        }

        TrieNode* root;
    };

public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        int n = words.size(), row = board.size();
        vector<string> res;

        if (n == 0 || row == 0)
        {
            return res;
        }

        int col = board[0].size();

        if (col == 0)
        {
            return res;
        }

        vector<vector<bool> > visit(row, vector<bool>(col, false));
        Trie t;

        for (auto &a : words)
        {
            t.insert(a);
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (t.root->child[board[i][j] - 'a'])
                {
                    search(board, t.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }

        return res;
    }

    void search(vector<vector<char> > &board, TrieNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res)
    {
        if (!p->str.empty())
        {
            res.push_back(p->str);
            p->str.clear();
        }

        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        visit[i][j] = true;

        for (auto &a : d)
        {
            int nx = a[0] + i, ny = a[1] + j;

            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a'])
            {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }

        visit[i][j] = false;
    }
};

int main()
{
    Solution sln;

    const vector<string> a = {"oaan", "etae", "ihkr", "iflv"};
    vector<vector<char> > board;

    for (int i = 0; i < SIZE(a); ++i)
    {
        vector<char> row(a[i].begin(), a[i].end());
        board.push_back(row);
    }

    const vector<string> b = {"oath", "pea", "eat", "rain"};
    vector<string> words(b, b + SIZE(b));
    vector<string> v = sln.findWords(board, words);
    printVector<string>(v);
    return 0;
}
