#include <iostream>
#include <string>

#include "UnitTest++/UnitTest++.h"

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;

        for (int i = 0; i < J.size(); ++i) {
            for (int j = 0; j < S.size(); ++j) {
                if (J[i] == S[j])
                    res++;
            }
        }

        return res;
    }
};

SUITE(TEST_CASES)
{
    TEST(CASE1)
    {
        Solution sln;
        string J("aA");
        string S("aAAbbbb");
        CHECK_EQUAL(sln.numJewelsInStones(J, S), 3);
    }

    TEST(CASE2)
    {
        Solution sln;
        string J("z");
        string S("ZZ");
        CHECK_EQUAL(sln.numJewelsInStones(J, S), 0);
    }
}
