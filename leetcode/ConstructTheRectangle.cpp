#include <cmath>
#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        vector<int> res;

        while (w > 0) {
            if (area % w == 0) {
                int l = area / w;
                res.push_back(l, w);
                res.push_back(w, l);
                break;
            }

            w--;
        }

        return res;
    }
};

int main()
{
    Solution sln;
    //int area = 4;
    int area = 126;
    vector<int> res = sln.constructRectangle(area);
    printVector<int>(res);
    return 0;
}
