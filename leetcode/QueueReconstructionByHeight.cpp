#include <iostream>
#include <list>
#include <vector>
#include <utility>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b) { 
                return a.first == b.first ? a.second < b.second : a.first > b.first;
                });

        vector<pair<int, int>> res;

        for (auto v: people) {
            res.insert(res.begin() + v.second, v);
        }

        return res;
    }

    vector<pair<int, int>> reconstructQueue1(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;

        int sz = people.size();

        if (sz == 0) {
            return res;
        }

        list<pair<int, int>> l;

        for (auto a: people) {
            auto itr = l.begin();

            while (itr != l.end() && itr->second <= a.second) {
                itr++;
            }

            l.insert(itr, a);
        }

        auto itr2 = l.begin();
        itr2++;

        // Need to be very careful about logic here.
        while (itr2 != l.end()) {
            auto itr3 = l.begin();
            int count = 0;

            while (itr3 != l.end()) {
                // need to check count and first both
                // otherwise we would get (2, 0) (1, 0)
                if (itr2->second <= count && itr3->first >= itr2->first) {
                    break;
                }

                if (itr3->first >= itr2->first) {
                    count++;
                }

                itr3++;
            }
            
            l.insert(itr3, *itr2);
            itr2 = l.erase(itr2);
        }

        res.insert(res.begin(), l.begin(), l.end());
        return res;
    }
};

int main() {
    Solution sln;
    vector<pair<int, int>> people = {
        {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
        //{1, 0}, {2, 0}
        //{2, 0}, {1, 0}
        //{1, 1}, {2, 0}
        //{1, 1}, {2, 1}, {3, 0}
        //{1, 0}, {2, 0}, {3, 0}
        //{3, 0}, {2, 1}, {1, 1}
        //{2, 1}, {1, 1}, {3, 0} 
        //{2, 1}, {3, 0}, {1, 1}
        //{3, 0}, {2, 1}, {1, 0}
    };

    vector<pair<int, int>> res = sln.reconstructQueue(people);
    printVector<int>(res);
    return 0;
}
