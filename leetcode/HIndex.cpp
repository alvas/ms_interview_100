#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
    }
};

int main()
{
    Solution sln;
    vector<int> citations = {3, 0, 6, 1, 5};
    std::cout << sln.hIndex(citations) << endl;
    return 0;
}
