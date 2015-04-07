#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(1, 1); 

        for (int i = 1; i <= rowIndex; ++i)
        {
            vector<int> newRow;
            newRow.push_back(1);
            int size = v.size();

            for (int j = 0; j < size - 1; ++j)
            {
                newRow.push_back(v[j] + v[j + 1]);
            }

            newRow.push_back(1);
            v.swap(newRow);
        }

        return v;
    }
};

int main()
{
    Solution sln;
    int r = 0;
    cout << "Please enter the number of row: ";
    cin >> r;
    vector<int> v = sln.getRow(r);
    printVector<int>(v);
    return 0;
}
