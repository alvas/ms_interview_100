#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    }
};

int main()
{
    Solution sln;
    string s, e;
    unordered_set<string> dict;
    vector<vector<string> > v = sln.findLadders(s, e, dict);
    print2DVector<string>(v);
    return 0;
}
