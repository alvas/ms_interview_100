#include <iostream>
#include <vector>
#include <utility>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
    }
};

int main() {
    Solution sln;
    vector<pair<int, int>> people = {
        {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
    };

    vector<pair<int, int>> res = sln.reconstructQueue(people);
    printVector<int>(res);
    return 0;
}
