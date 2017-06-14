#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sz1 = list1.size(), sz2 = list2.size();
        unordered_map<string, int> indexMap;

        for (int i = 0; i < sz1; ++i) {
            indexMap[list1[i]] = i;
        }

        vector<string> res;
        int indexSum = INT_MAX;

        for (int i = 0; i < sz2; ++i) {
            if (indexMap.count(list2[i]) != 0) {
                int sum = i + indexMap[list2[i]];

                if (sum < indexSum) {
                    res.clear();
                    res.push_back(list2[i]);
                    indexSum = sum;
                }
                else if (sum == indexSum) {
                    res.push_back(list2[i]);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    vector<string> res = sln.findRestaurant(list1, list2);
    printVector<string>(res);
    return 0;
}
