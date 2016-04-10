#include <cmath>
#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;

        res = sqrt(n);
        // take simple case for example.
        // 6, has factor 2 and 3. Its value would be 0: 0, 1: 1, 2: 0, 3: 1, 6: 0.
        // Then we add another factor 2 to 6 and make it 12. Its value would be 0: 0, 1: 1, 2: 0, 3: 1, 4: 0, 6: 1, 12: 0.
        // We can see that add another factor, its value change 2 more times and the final result doesn't change.
        //for (int i = 1; i * i <= n; ++i)
        //{
            //res++;
        //}

        return res;
    }

    int bulbSwitch1(int n) {
        int res = 0;
        vector<bool> v(n, true);

        for (int i = 2; i <= n; ++i)
        {
            // index is important
            for (int k = 1, j = i; j * k <= n; ++k)
            {
                v[j * k - 1] = v[j * k - 1] ^ 1;
            }
        }

        for (auto i : v)
        {
            res += i ? 1 : 0;
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> v = {8, 10, 12, 20, 33, 45, 78, 9999999};

    for (auto n : v)
    {
        std::cout << "n: " << n << std::endl;
        std::cout << sln.bulbSwitch1(n) << std::endl;
        std::cout << sln.bulbSwitch(n) << std::endl;
    }

    return 0;
}
