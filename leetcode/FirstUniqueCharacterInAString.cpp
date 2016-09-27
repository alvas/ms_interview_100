#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;

        for (char c: s) {
            ++m[c];
        }

        int sz = s.size();

        for (int i = 0; i < sz; ++i) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sln;
    //string s("leetcode");
    //string s("loveleetcode");
    //string s("");
    string s("aabbccdd");
    cout << sln.firstUniqChar(s) << endl;
    return 0;
}
