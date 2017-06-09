#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        vector<int> rowMap = { 1, 0, 0, 1, 2, 1, 1, 1, 2, 1, 1, 1, 0, 0, 2, 2, 2, 2, 1, 2, 2, 0, 2, 0, 2, 0 };

        for (auto word: words) {
            int sz = word.size();
            char c = tolower(word[0]);
            int idx = rowMap[c - 'a'];
            int i = 1;

            for (; i < sz; ++i) {
                c = tolower(word[i]);
                
                if (rowMap[c - 'a'] != idx) {
                    break;
                }
            }

            if (i == sz) {
                res.push_back(word);
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<string> words = { "Hello", "Alaska", "Dad", "Peace" };
    vector<string> res = sln.findWords(words);
    printVector<string>(res);
    return 0;
}
