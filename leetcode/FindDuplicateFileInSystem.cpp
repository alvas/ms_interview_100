#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        return ans;
    }
};

int main()
{
    Solution sln;
    vector<string> paths;
    vector<vector<string>> ans = sln.findDuplicate(paths);
    print2DVector<string>(ans);
    return 0;
}
