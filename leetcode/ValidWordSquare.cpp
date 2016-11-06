#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int r = words.size();

        if (r == 0) {
            return true;
        }

        int c = words[0].size();

        if (r != c) {
            return false;
        }

        unordered_map<int, int> m;

        for (int i = 0; i < r; ++i) {
            m[i] = words[i].size();
        }

        for (int i = 0; i < r; ++i) {
            int sz2 = m[i];

            // validate the length
            if (m[sz2 - 1] < i + 1) {
                return false;
            }

            for (int j = i; j < sz2; ++j) {
                if (m[j] >= i + 1 && words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sln;
    vector<string> words = {"abcd", "bnrt", "crmy", "dtye"};
    //vector<string> words = {"ball","asee","let","lep"};
    //vector<string> words = {"ball", "area", "read", "lady"};
    cout << sln.validWordSquare(words) << endl;
    return 0;
}
