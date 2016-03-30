#include <iostream>
#include <vector>

#include "NormalData.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        int sz = r, idx = 0;

        while (l < r)
        {
            int m = l + (r - l) / 2;
            idx = sz - 1 - m;

            if (citations[m] >= idx + 1)
            {
                r = m;
            }
            else if (citations[m] < idx + 1 && m + 1 < sz && citations[m + 1] >= idx)
            {
                return idx;
            }
            else
            {
                l = m + 1;
            }
        }

        if (l == sz)
        {
            idx = 0;
        }
        // be careful about this condition, {3, 3, 3}, h-index should be 3
        else if (l == 0)
        {
            idx = sz;
        }

        return idx;
    }

    int hIndex_normal(vector<int>& citations) {
        int idx = 0;
        int m = citations.size();

        for ( ; idx < m; ++idx)
        {
            if (citations[m - 1 - idx] < idx + 1)
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
    std::vector<vector<int>> citations = {{1}, {0, 1, 3, 5, 6}, {1, 2, 3, 4}, {0, 0, 0,0}, {0, 0, 1, 1, 1,1}, {0, 1, 2, 2, 3, 6}, {0, 0, 0, 0, 6}, {3, 3, 3}};

    for (auto c : citations)
    {
        printVector<int>(c);
        std::cout << sln.hIndex_normal(c) << std::endl;
        std::cout << sln.hIndex(c) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
