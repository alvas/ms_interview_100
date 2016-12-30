#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (str.empty()) {
            return false;
        }

        int sz = str.size(), half = sz / 2;

        for (int i = 1; i <= half; ++i) {
            if ((sz % i) != 0) {
                continue;
            }

            string tmp = str.substr(0, i);
            int j = i;

            for ( ; j < sz; j += i) {
                if (str.substr(j, i) != tmp) {
                    break;
                }
            }

            if (j >= sz) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sln;
    //string str("abab");
    //string str("abcabcabcabc");
    string str("aba");
    cout << sln.repeatedSubstringPattern(str) << endl;
    return 0;
}
