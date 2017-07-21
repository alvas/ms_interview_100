#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int num = 0;

        while (j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (num == 0 && abbr[j] == '0') {
                    return false;
                }

                num = num * 10 + (abbr[j] - '0');
                j++;
            }
            else {
                if (i + num > word.size()) {
                    return false;
                }
                else if (i + num == word.size()) {
                    if (j == abbr.size()) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }

                i += num;
                num = 0;

                if (word[i++] != abbr[j++]) {
                    return false;
                }
            }
        }

        return i + num == word.size();
    }
};

int main()
{
    Solution sln;
    //string word("internationalization"), abbr("i12iz4n");
    //string word("apple"), abbr("a2e");
    string word("a"), abbr("01");
    cout << sln.validWordAbbreviation(word, abbr) << endl;
    return 0;
}
