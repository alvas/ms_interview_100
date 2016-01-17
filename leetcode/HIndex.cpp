#include <iostream>
#include <vector>

#include "NormalData.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int idx = 0;
        return idx;
    }
};

int main()
{
    Solution sln;
    std::vector<int> citations = {3, 0, 6, 1, 5};
    std::cout << sln.hIndex(citations) << endl;
    return 0;
}
