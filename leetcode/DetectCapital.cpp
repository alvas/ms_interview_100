#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int sz = word.size();

        if (sz == 0) {
            return true;
        }

        // isupper return non zero for upper case; zero for lower case;
        bool isFirstUp = (isupper(word[0]) != 0);
        bool isSecondUp = false;

        if (sz > 1) {
            isSecondUp = (isupper(word[1]) != 0);
        }

        if (!isFirstUp && isSecondUp) {
            return false;
        }

        for (int i = 2; i < sz; ++i) {
            if (isSecondUp != (isupper(word[i]) != 0)){
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    //string word("USA");
    //string word("Leetcode");
    //string word("lEetcode");
    string word("leEtcode");
    //string word("FlaG");
    cout << sln.detectCapitalUse(word) << endl;
    return 0;
}
