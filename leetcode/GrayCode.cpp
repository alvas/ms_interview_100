#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int m = 1 << n;

        for (int i = 0; i < m; ++i)
        {
            res.push_back((i >> 1) ^ i);
        }

        return res;
    }

    vector<int> grayCode1(int n) {
        vector<int> v(1, 0);
        int s = 0;

        // Be careful about the boundary condition, no euqal "=" here.
        while (s < n)
        {
            int size = v.size();
            int mask = 1 << s;
            vector<int> r = v;
            reverse(r.begin(), r.end());

            for (int i = 0; i < size; ++i)
            {
                r[i] = r[i] | mask;
            }

            v.insert(v.end(), r.begin(), r.end());
            s++;
        }

        return v;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    vector<int> v = sln.grayCode(n);
    printVector<int>(v);
    return 0;
}
