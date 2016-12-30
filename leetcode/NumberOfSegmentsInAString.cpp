#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int sz = s.size(), res = 0;
        bool startString = false;

        for (int i = 0; i < sz; ++i) {
            bool isSpace = isspace(s[i]);

            if (!startString && !isSpace) {
                startString = true;
                res++;
            }
            else if (isSpace) {
                startString = false;
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    string s("Hello, my name is John");
    //string s("love live! mu'sic forever");
    cout << sln.countSegments(s) << endl;
    return 0;
}
