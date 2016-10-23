#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // The same word could appear in the vector multiple times.
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) {
            return 0;
        }

        int sz = words.size(), res = sz;
        int idx1 = -1, idx2 = -1;

        for (int i = 0; i < sz; ++i) {
            if (words[i] == word1) {
                idx1 = i;

                if (idx2 != -1) {
                    res = min(abs(idx2 - i), res);
                }
            }
            else if (words[i] == word2) {
                idx2 = i;

                if (idx1 != -1) {
                    res = min(abs(idx1 - i), res);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    vector<string> words = {
        "practice", "makes", "perfect", "coding", "makes"
    };

    string word1("coding"), word2("practice");
    //string word1("makes"), word2("coding");
    cout << sln.shortestDistance(words, word1, word2) << endl;
    return 0;
}
