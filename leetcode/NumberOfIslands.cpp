#include <iostream>
#include <queue>
#include <utility>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Need to improve!!
    int numIslands(vector<vector<char> >& grid) {
        int h = grid.size(), w = 0;

        if (h > 0)
        {
            w = grid[0].size();
        }

        int num = 0;
        queue<pair<int, int> > q;

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    grid[i][j] = '2';
                    q.push(make_pair(i, j));
                }

                while (!q.empty())
                {
                    pair<int, int> t = q.front();
                    q.pop();
                    int r = t.first, c = t.second;

                    if (0 <= r - 1)
                    {
                        if (grid[r - 1][c] == '1')
                        {
                            grid[r - 1][c] = '2';
                            q.push(make_pair(r - 1, c));
                        }
                    }

                    if (r + 1 < h)
                    {
                        if (grid[r + 1][c] == '1')
                        {
                            grid[r + 1][c] = '2';
                            q.push(make_pair(r + 1, c));
                        }
                    }

                    if (0 <= c - 1)
                    {
                        if (grid[r][c - 1] == '1')
                        {
                            grid[r][c - 1] = '2';
                            q.push(make_pair(r, c - 1));
                        }
                    }

                    if (c + 1 < w)
                    {
                        if (grid[r][c + 1] == '1')
                        {
                            grid[r][c + 1] = '2';
                            q.push(make_pair(r, c + 1));
                        }
                    }

                }
            }
        }

        return num;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_WIDTH = 5;
    const int LOCAL_HEIGHT = 4;
    //const char *a[LOCAL_HEIGHT] = 
    //{
        //"11110",
        //"11010",
        //"11000",
        //"00000"
    //};

    const char *a[LOCAL_HEIGHT] = 
    {
        "11000",
        "11000",
        "00100",
        "00011"
    };

    vector<vector<char> > grid(LOCAL_HEIGHT, vector<char>(LOCAL_WIDTH, '0'));

    for (int i = 0; i < LOCAL_HEIGHT; ++i)
    {
        grid[i].assign(a[i], a[i] + LOCAL_WIDTH);
    }

    print2DVector<char>(grid);
    std::cout << sln.numIslands(grid) << endl;
    return 0;
}
