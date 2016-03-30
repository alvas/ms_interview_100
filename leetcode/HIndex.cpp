#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater<int>());

        int m = citations.size();
        int idx = 0;

        for ( ; idx < m; ++idx)
        {
            if (citations[idx] < idx + 1)
            {
                break;
            }
        }

        return idx;
    }
};

int main()
{
    Solution sln;
    std::vector<vector<int>> citations = {{3, 0, 6, 1, 5}, {2, 1, 3, 4}};

    for (auto c : citations)
    {
        printVector<int>(c);
        std::cout << sln.hIndex(c) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
