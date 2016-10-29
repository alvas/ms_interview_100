#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX, sz = words.size();
        int idx1 = -1, idx2 = -1;

        if (word1 == word2) {
            for (int i = 0; i < sz; ++i) {
                if (words[i] == word1) {
                    if (idx1 == -1) {
                        idx1 = i;
                    }
                    else if (idx2 == -1) {
                        idx2 = i;
                        res = min(res, abs(idx2 - idx1));
                    }
                    else {
                        idx1 = idx2;
                        idx2 = i;
                        res = min(res, abs(idx2 - idx1));
                    }
                }
            }
        }
        else {
            for (int i = 0; i < sz; ++i) {
                if (words[i] == word1) {
                    idx1 = i;

                    if (idx2 != -1) {
                        res = min(res, abs(idx2 - idx1));
                    }
                }
                else if (words[i] == word2) {
                    idx2 = i;

                    if (idx1 != -1) {
                        res = min(res, abs(idx2 - idx1));
                    }
                }
            }

        }

        return res;
    }
};

int main() {
    Solution sln;
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    //string word1("makes"), word2("coding");
    string word1("makes"), word2("makes");
    cout << sln.shortestWordDistance(words, word1, word2) << endl;
    return 0;
}
