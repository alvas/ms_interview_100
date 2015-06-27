#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    }
};

int main()
{
    Solution sln;
    string word;
    cout << "Please enter the word: ";
    cin >> word;

    vector<vector<char> > board;
    cout << sln.exist(board, word) << endl;
    return 0;
}
