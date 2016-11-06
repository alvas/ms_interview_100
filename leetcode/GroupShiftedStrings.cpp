#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m; 

        for (auto s: strings) {
            string tmp = transformString(s);
            auto itr = m.find(tmp);

            if (itr == m.end()) {
                vector<string> v(1, s);
                m[tmp] = v;
            }
            else {
                vector<string> &v = itr->second;
                v.push_back(s);
            }
        }

        vector<vector<string>> res;

        for (auto itr = m.begin(); itr != m.end(); ++itr) {
            res.push_back(itr->second);
        }

        return res;
    }

    string transformString(string s) {
        if (s.empty()) {
            return string();
        }

        int sz = s.size();
        int diff = s[0] - 'a';

        for (int i = 0; i < sz; ++i) {
            s[i] = (s[i] - diff + 26) % 26;
        }

        return s;
    }
};

int main() {
    Solution sln;
    vector<string> s = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> r = sln.groupStrings(s);
    print2DVector<string>(r);
    return 0;
}
