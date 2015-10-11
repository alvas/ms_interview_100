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
    vector<int> a = {3, 0, 6, 1, 5};
    vector<int> citations(a, a + SIZE(a));
    cout << sln.hIndex(citations) << endl;
    return 0;
}
