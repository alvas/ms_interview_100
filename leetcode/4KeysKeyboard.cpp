#include <iostream>
#include <numeric>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int maxA(int N) {
        vector<int> count(N);
        iota(count.begin(), count.end(), 1);

        for (int i = 6; i < N; ++i) {
            int a = 2 * count[i - 3];

            for (int j = 3; j < i; ++j) {
                int b = j * count[i - j  - 1];

                // be careful about the equal case here
                if (a <= b) {
                    a = b;
                }
                else {
                    break;
                }
            }

            count[i] = a;
        }

        return count[N - 1];
    }
};

int main()
{
    Solution sln;
    //int N = 3;
    //int N = 7;
    //int N = 15;
    int N = 26;
    //int N = 30;
    //int N = 44;
    //int N = 50;
    cout << sln.maxA(N) << endl;
    return 0;
}
