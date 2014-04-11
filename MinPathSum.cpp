#include <iostream>
#include <vector>

using namespace std;

const int X = 12;
const int Y = 18;

// !!This is bad bad performance!!
void findMinPathRecursive(const vector< vector<int> > &grid, int x, int y, int sum, int &min)
{
    // if the array is empty
    if (grid.size() == 0 || grid[0].size() == 0)
    {
        return;
    }
    // get to the bottom right
    else if (x == grid.size() - 1 && y == grid[0].size() - 1)
    {
        sum += grid[x][y];
#ifdef DEBUG
        cout << "sum = " << sum << endl;
#endif
        if (min == 0 || sum < min)
        {
            min = sum;
        }
    }
    // get to the right, but not reach the bottom
    else if (x < grid.size() - 1 && y == grid[0].size() - 1)
    {
        sum += grid[x][y];
#ifdef DEBUG
        cout << "x = " << x << "; y = " << y << endl;
#endif
        findMinPathRecursive(grid, x + 1, y, sum, min);
    }
    // get to the bottom, but not reach the right
    else if (x == grid.size() - 1 && y < grid[0].size() - 1)
    {
        sum += grid[x][y];
#ifdef DEBUG
        cout << "x = " << x << "; y = " << y << endl;
#endif
        findMinPathRecursive(grid, x, y + 1, sum, min);
    }
    // in the middle somewhere
    else
    {
        sum +=grid[x][y];
#ifdef DEBUG
        cout << "x = " << x << "; y = " << y << endl;
#endif
        findMinPathRecursive(grid, x + 1, y, sum, min);
        findMinPathRecursive(grid, x, y + 1, sum, min);
    }
}

int findMinPath(vector<vector<int> > &grid)
{
    if (grid.size() == 0)
    {
        return 0;
    }

    int x = grid.size();
    int y = grid[0].size();

    for (int i = 1; i < x; ++i)
    {
        grid[i][0] = grid[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < y; ++i)
    {
        grid[0][i] = grid[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < x; ++i)
    {
        for (int j = 1; j < y; ++j)
        {
            int sum1 = grid[i][j] + grid[i - 1][j];
            int sum2 = grid[i][j] + grid[i][j - 1];

            grid[i][j] = sum1 < sum2 ? sum1 : sum2;
        }
    }

    return grid[x - 1][y - 1];
}

// assume all inner vectors have the same size
int minPathSum(vector< vector<int> > &grid)
{
    int min = 0;
//    findMinPathRecursive(grid, 0, 0, 0, min);
    min = findMinPath(grid);
    return min;
}

#ifndef EXPORTED
int main()
{
//    int a[X][Y] = {{9, 6, 5}, {4, 3, 2}, {7, 2, 1}};
    int a[X][Y] = 
                {{7,1,3,5,8,9,9,2,1,9,0,8,3,1,6,6,9,5}, \
                 {9,5,9,4,0,4,8,8,9,5,7,3,6,6,6,9,1,6}, \
                 {8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8}, \
                 {6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4}, \
                 {7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4}, \
                 {9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9}, \
                 {1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4}, \
                 {3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2}, \
                 {1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3}, \
                 {5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7}, \
                 {2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7}, \
                 {0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9}};
    
//    int a[X][Y] = {};
//    int a[X][Y] = {{0}};
//    int a[X][Y] = {{9, 6, 5}};
//    int a[X][Y] = {{9}, {6}, {5}};
    vector< vector<int> > grid ;

    grid.resize(X);

    for (int i = 0; i < X; ++i)
    {
        grid[i].assign(a[i], a[i] + Y);
    }

    for (vector<vector<int> >::iterator itr = grid.begin(); itr != grid.end(); ++itr)
    {
        vector<int> row = *itr;

        for (vector<int>::iterator itr2 = (*itr).begin(); itr2 != (*itr).end(); ++itr2)
        {
            cout << *itr2 << "\t";
        }

        cout << endl;
    }

    cout << "The min path sum is : " << minPathSum(grid) << endl;
    return 0;
}
#endif
