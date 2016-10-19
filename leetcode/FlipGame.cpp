#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int sz = s.size();

        for (int i = 1; i < sz; ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                s[i] = '-';
                s[i - 1] = '-';
                res.push_back(s);
                s[i] = '+';
                s[i - 1] = '+';
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    //string s("++++");
    string s("++++--+-++-+++---+----+");
    vector<string> res = sln.generatePossibleNextMoves(s);
    printVector<string>(res);
    return 0;
}
