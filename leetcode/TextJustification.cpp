#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    }
};

int main()
{
    Solution sln;
    int maxWidth = 0;
    cout << "Please enter maxWidth: ";
    cin >> maxWidth;
    vector<string> words;
    vector<string> v = sln.fullJustify(words, maxWidth);
    printVector<string>(v);
    return 0;
}
