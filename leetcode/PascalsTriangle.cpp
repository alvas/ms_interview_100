#include <iostream>
#include <vector>

#include "../NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > tri;
        int initialArray[1] = {1};
        vector<int> tmp(initialArray, initialArray + 1);

        for (int i = 0; i < numRows; ++i)
        {
            if (i != 0)
            {
                vector<int> newRow;
                newRow.push_back(tmp[0]);
                int length = tmp.size();

                for (int j = 1; j < length; ++j)
                {
                    newRow.push_back(tmp[j - 1] + tmp[j]);
                }

                newRow.push_back(tmp[length - 1]);
                tmp = newRow;
            }

            tri.push_back(tmp);
        }

        return tri;
    }
};

int main()
{
    Solution sln;
    int rows = 0;
    std::cout << "Please enter n: ";
    cin >> rows;
    vector<vector<int> > tri = sln.generate(rows);
    print2DVector<int>(tri);
    return 0;
}
