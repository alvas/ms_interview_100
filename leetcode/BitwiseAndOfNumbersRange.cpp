#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;

        while ((m & d) != (n & d))
        {
            d <<= 1;
        }

        return m & d;
    }

    int rangeBitwiseAnd3(int m, int n) {
        if (n > m)
        {
            return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
        }
        else
        {
            return m;
        }
    }

    int rangeBitwiseAnd2(int m, int n) {
        int k = 0;

        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            k++;
        }

        return m << k;
    }

    // Need to improve it.
    int rangeBitwiseAnd1(int m, int n) {
        int val = m & n;

        if (val == 0)
        {
            return val;
        }

        int lm = 0, ln = 0;
        int tmpm = m, tmpn = n;

        while (tmpm != 0)
        {
            tmpm >>= 1;
            lm++;
        }

        while (tmpn != 0)
        {
            tmpn >>= 1;
            ln++;
        }

        if (ln > lm)
        {
            return 0;
        }

        tmpm  = m^n;
        lm = 0;

        while (tmpm != 0)
        {
            tmpm >>= 1;
            lm++;
        }

        int mask = 1 << lm;
        mask--;
        mask = ~mask;
        val &= mask;

        return val;
    }

    int rangeBitwiseAnd_improve(int m, int n) {
        int val = m & n;

        if (val == 0)
        {
            return val;
        }

        int lm = 0, ln = 0;
        int tmpm = m, tmpn = n;

        while (tmpm != 0)
        {
            tmpm >>= 1;
            lm++;
        }

        while (tmpn != 0)
        {
            tmpn >>= 1;
            ln++;
        }

        if (ln > lm)
        {
            return 0;
        }

        // Please test the basic case: 1, 1. Shame on me.
        lm--;
        int mask = 1 << lm;
        tmpm = m & mask;
        tmpn = n & mask;

        while (tmpm == tmpn && lm > 0)
        {
            lm--;
            mask = 1 << lm;
            tmpm = m & mask;
            tmpn = n & mask;
        }

        mask = 1 << lm;
        mask--;
        // Be careful. ~= is invalid.
        mask = ~mask;
        val &= mask;

        return val;
    }

    int rangeBitwiseAnd_naive(int m, int n) {
        int val = m;

        for (int i = m + 1; i <= n; ++i)
        {
            val &= i;
        }

        return val;
    }
};

int main()
{
    Solution sln;
    int m = 0, n = 2147483647;
    std::cout << "Please enter m: ";
    cin >> m;
    std::cout << "Please enter n > " << m << ": ";
    cin >> n;

    bitset<32> bm(m);
    bitset<32> bn(n);
    std::cout << bm << endl;
    std::cout << bn << endl;

    std::cout << sln.rangeBitwiseAnd_naive(m, n) << endl;
    std::cout << sln.rangeBitwiseAnd(m, n) << endl;
    return 0;
}
