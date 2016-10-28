#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt(num + 1, 0);
        
        for (int i = 1; i <= num; i++) {
            cnt[i] = cnt[i & (i - 1)] + 1;      // i & (i - 1) is i without lowest 1 bit
        }
        
        return cnt;
    }

    vector<int> countBits5(int num) {
        vector<int> cnt(num + 1, 0);

        for (int i = 1, k = 0, bound = 1; i <= num; i++) {
            cnt[i] = cnt[k] + 1;                            // k is i without highest 1 bit
            if (++k == bound) { k = 0, bound <<= 1; }       // update k
        }

        return cnt;
    }

    vector<int> countBits4(int num) {
        vector<int> cnt (num + 1, 0);

        for (int i = 1; i <= num; i++) {
            cnt[i] = cnt[i >> 1] + (i & 1);         // isolate i's lowest bit
        }

        return cnt;
    }

    vector<int> countBits3(int num) {
        vector<int> res;

        for (int i = 0; i <= num; ++i) {
            res.push_back(bitset<32>(i).count());
        }

        return res;
    }

    // This solution is very hard to understand and not faster than the first solution.
    vector<int> countBits2(int num) {
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
