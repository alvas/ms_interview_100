#include <iostream>
#include <set>
#include <utility>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > res;

        int n = buildings.size();

        if (n == 0)
        {
            return res;
        }

        vector<pair<int, int> > heights;

        for (auto &b : buildings)
        {
            heights.push_back({b[0], -b[2]});
            heights.push_back({b[1], b[2]});
        }

        sort(heights.begin(), heights.end());

        multiset<int> hp;
        hp.insert(0);

        int pre = 0, cur = 0;

        for (auto &h : heights)
        {
            if (h.second < 0)
            {
                hp.insert(-h.second);
            }
            else
            {
                hp.erase(hp.find(h.second));
            }

            // get the highest building.
            cur = *hp.rbegin();

            // if the highest building is changed(insert a higher one or highest is removed,
            // insert a new point in the result.
            if (cur != pre)
            {
                res.push_back({h.first, cur});
                pre = cur;
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    int a[][3] = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int> > buildings;

    for (int i = 0; i < SIZE(a); ++i)
    {
        vector<int> b(a[i], a[i] + SIZE(a[i]));
        buildings.push_back(b);
    }

    vector<pair<int, int> > v = sln.getSkyline(buildings);
    printVector<int>(v);
    return 0;
}
