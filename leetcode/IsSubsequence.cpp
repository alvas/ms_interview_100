#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int szS = s.size(), szT = t.size();

        if (szT < szS) {
            return false;
        }

        int i = 0, j = 0;

        while (i < szS && j < szT) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i == szS; 
    }
};

int main() {
    Solution sln;
    //string s("abc"), t("ahbgdc");
    string s("axc"), t("ahbgdc");
    cout << sln.isSubsequence(s, t) << endl;
    return 0;
}
