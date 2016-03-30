#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
       vector<int> res(num + 1, 0);

       for (int i = 0; i <= num; ++i)
       {
           res[i] = ((i & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
           res[i] += (((i & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
           res[i] += ((i >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
       }

       return res;
    }

    vector<int> countBits1(int num) {
       vector<int> res(num + 1, 0);

       for (int i = 0; i <= num; ++i)
       {
           int j = i;

           while (j)
           {
               res[i]++;
               j = j & (j - 1);
           }
       }

       return res;
    }
};

int main()
{
    Solution sln;
    const int N = 999;
    std::vector<int> v = sln.countBits(N);
    int n = v.size();

    for (int i = 0; i < n; ++i)
    {
        std::cout << "v: " << v[i] << std::endl;
        //std::cout << "v: " << __builtin_popcount(i) << std::endl;
        assert(__builtin_popcount(i) == v[i]);
    }

    return 0;
}
