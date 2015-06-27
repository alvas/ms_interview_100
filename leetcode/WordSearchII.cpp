#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    }
};

int main()
{
    Solution sln;
    vector<vector<char> > board;
    vector<string> words;
    vector<string> v = sln.findWords(board, words);
    printVector<string>(v);
    return 0;
}
