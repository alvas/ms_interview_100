#include <iostream>
#include <list>
#include <string>
#include <unordered_set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        int nS = s.size(), nD = wordDict.size();

        if (nS == 0 || nD == 0)
        {
            return ret;
        }
        
        vector<list<string> > dp(nS + 1);

        for (int i = 0; i < nS; ++i)
        {
            for (unordered_set<string>::iterator itr = wordDict.begin(); itr != wordDict.end(); ++itr)
            {
                string c = *itr;
                int len = c.size();

                if (i + len > nS)
                {
                    continue;
                }

                if (c == s.substr(i, len))
                {
                    dp[i + len].push_back(c);
                }
            }
        }

        if (dp[nS].empty())
        {
            return ret;
        }

        list<string> tmp;
        dfsStringList(dp, nS, ret, tmp);

        return ret;
    }

    void dfsStringList(vector<list<string> > &dp, int end, vector<string> &ret, list<string> &tmp)
    {
        if (end <= 0)
        {
            string ans;
            list<string>::reverse_iterator rItr = tmp.rbegin();

            if (rItr != tmp.rend())
            {
                ans += *rItr;
                ++rItr;
            }

            for ( ; rItr != tmp.rend(); ++rItr)
            {
                ans += " " + *rItr;
            }

            ret.push_back(ans);
            return;
        }

        for (string &c : dp[end])
        {
            tmp.push_back(c);
            dfsStringList(dp, end - c.size(), ret, tmp);
            tmp.pop_back();
        }
    }

    // time limit exceed
    // but using pruning, it can ipmrove performance significantly
    vector<string> wordBreak_slow(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        int nS = s.size(), nD = wordDict.size();

        if (nS == 0 || nD == 0)
        {
            return ret;
        }

        string c;
        // use possible to prune the calculation, possible[i] = true means [i, n] has solution
        vector<bool> possible(nS + 1, true);
        breakWord(s, nS, 0, wordDict, c, ret, possible);
        return ret;
    }

    void breakWord(string &s, int nS, int sIdx, unordered_set<string> &w, string &c, vector<string> &ret, vector<bool> &possible)
    {
        if (sIdx == nS)
        {
            ret.push_back(c);
            return;
        }

        for (int i = sIdx; i < nS; ++i)
        {
            string c2 = s.substr(sIdx, i - sIdx + 1);

            if (w.find(c2) != w.end() && possible[i + 1])
            {
                string c3 = c + (sIdx == 0 ? "" : " ") + c2;
                int size1 = ret.size();
                breakWord(s, nS, i + 1, w, c3, ret, possible);

                if (ret.size() == size1)
                {
                    possible[i + 1] = false;
                }
            }
        }
    }
};

int main()
{
    Solution sln;
    string s("catsanddog");
    const string a[] = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> word(a, a + SIZE(a));;
    vector<string> v = sln.wordBreak_slow(s, word);
    vector<string> v1 = sln.wordBreak(s, word);
    printVector<string>(v);
    printVector<string>(v1);
    return 0;
}
