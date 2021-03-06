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
        string result;
        vector<string> sols;
        int len = s.size();
        vector<bool> possible(len + 1, true);
        findWordBreak(0, s, wordDict, len, result, sols, possible);
        return sols;
    }

    void findWordBreak(int start, string &s, unordered_set<string> &dict, int len, string &result, vector<string> &sols, vector<bool> &possible)
    {
        if (start == len)
        {
            sols.push_back(result.substr(0, result.size() - 1));
            return;
        }

        for (int i = start; i < len; ++i)
        {
            string piece = s.substr(start, i - start + 1);

            if (dict.find(piece) != dict.end() && possible[i + 1])
            {
                result.append(piece).append(" ");

                int beforeChange = sols.size();

                findWordBreak(i + 1, s, dict, len, result, sols, possible);

                if (sols.size() == beforeChange)
                {
                    possible[i + 1] = false;
                }

                result.resize(result.size() - piece.size() - 1);
            }
        }
    }

    vector<string> wordBreak_slow(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        int nS = s.size(), nD = wordDict.size();

        if (nS == 0 || nD == 0)
        {
            return ret;
        }
        
        vector<list<string> > dp(nS + 1);

        for (int i = 0; i < nS; ++i)
        {
            // This pruning is important. Without this, time limit would exceed. But it is slower than the algorithm below.
            if (i != 0 && dp[i].empty())
            {
                continue;
            }

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
    vector<string> wordBreak_dp(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        int nS = s.size(), nD = wordDict.size();

        if (nS == 0 || nD == 0)
        {
            return ret;
        }

        string c;
        // use possible to prune the calculation, possible[i] = true means [i, n] has solution
        vector<bool> possible(nS + 1, true);
        breakWord(s, 0, wordDict, c, ret, possible);
        return ret;
    }

    void breakWord(string &s, int sIdx, unordered_set<string> &w, string &c, vector<string> &ret, vector<bool> &possible)
    {
        int n = s.size();

        if (sIdx == n)
        {
            ret.push_back(c);
            return;
        }

        for (int i = sIdx; i < n; ++i)
        {
            string c2 = s.substr(sIdx, i - sIdx + 1);

            if (w.find(c2) != w.end() && possible[i + 1])
            {
                string c3 = c + (sIdx == 0 ? "" : " ") + c2;
                int size1 = ret.size();
                breakWord(s, i + 1, w, c3, ret, possible);

                if (ret.size() == size1)
                {
                    // set possible[i + 1] to false
                    possible[i + 1] = false;
                }
            }
        }
    }
};

int main()
{
    Solution sln;
    std::string s("catsanddog");
    std::unordered_set<string> word = {"cat", "cats", "and", "sand", "dog"};
    std::vector<string> v = sln.wordBreak_dp(s, word);
    std::vector<string> v1 = sln.wordBreak_slow(s, word);
    std::vector<string> v2 = sln.wordBreak(s, word);
    printVector<string>(v);
    printVector<string>(v1);
    printVector<string>(v2);
    return 0;
}
