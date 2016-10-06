#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        return res;
    }
};

int main() {
    Solution sln;
    vector<pair<string, string>> equations;
    vector<double> values;
    vector<pair<string, string>> queries;
    vector<double> ans = sln.calcEquation(equations, values, queries);
    printVector<double>(ans);
    return 0;
}
