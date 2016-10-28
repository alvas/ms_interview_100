#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
    }
};

int main() {
    Solution sln;
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1("makes"), word2("coding");
    //string word1("makes"), word2("makes");
    cout << sln.shortestWordDistance(words, word1, word2) << endl;
    return 0;
}
