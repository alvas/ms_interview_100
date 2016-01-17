#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        std::vector<std::string> res;
        return res;
    }
};

int main()
{
    Solution sln;
    string num;
    int target = 0;
    vector<string> res = sln.addOperators(num, target);
    printVector<string>(res);
    return 0;
}
