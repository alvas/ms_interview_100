#include <iostream>
#include <unordered_set>
#include <string>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char table[256] = {0};

        for (auto &j: J) {
            table[j] = 1;
        }

        int res = 0;

        for (auto &s: S) {
            res += table[s] & 1;
        }

        return res;
    }

    int numJewelsInStones3(string J, string S) {
        int res = 0;
        std::unordered_set<char> jSet(J.begin(), J.end());

        for (int i = 0; i < S.size(); ++i) {
            if (jSet.find(S[i]) != jSet.end())
                res++;
        }

        return res;
    }

    int numJewelsInStones2(string J, string S) {
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
    class MyFixture
    {
    public:
        Solution sln;
    };

    TEST_FIXTURE(MyFixture, CASE1)
    {
        string J("aA");
        string S("aAAbbbb");
        CHECK_EQUAL(sln.numJewelsInStones(J, S), 3);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        Solution sln;
        string J("z");
        string S("ZZ");
        CHECK_EQUAL(sln.numJewelsInStones(J, S), 0);
    }
}
