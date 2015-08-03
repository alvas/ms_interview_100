#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main()
{
    Solution sln;
    string s("anagram"), t("nagaram");
    cout << sln.isAnagram(s, t) << endl;
    return 0;
}
