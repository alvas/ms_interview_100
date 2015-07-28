#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespce std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    }
};

int main()
{
    Solution sln;
    string input;
    cout << "Please enter input: ";
    cin >> input;
    vector<int> v = sln.diffWaysToCompute(input);
    printVector<int>(v);
    return 0;
}
