#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &wordList) {
        mp.clear();
        res.clear();
        path.clear();

        wordList.insert(start);
        wordList.insert(end);

        unordered_set<string> cur_lev;
        cur_lev.insert(start);
        unordered_set<string> next_lev;
        path.push_back(end);

        while (true)
        {
            for (auto &a : cur_lev)
            {
                wordList.erase(a);
            }

            for (auto &a : cur_lev)
            {
                findDict2(a, wordList, next_lev);
            }

            if (next_lev.empty())
            {
                return res;
            }

            if (next_lev.find(end) != next_lev.end())
            {
                output(start, end);
                return res;
            }

            cur_lev.clear();
            cur_lev = next_lev;
            next_lev.clear();
        }

        return res;
    }

    void findDict2(string str, unordered_set<string> &dict, unordered_set<string> &next_lev)
    {
        int n = str.size();

        for (int i = 0; i < n; ++i)
        {
            string s = str;

            for (char j = 'a'; j <= 'z'; ++j)
            {
                s[i] = j;

                if (dict.find(s) != dict.end())
                {
                    next_lev.insert(s);
                    mp[s].push_back(str);
                }
            }
        }
    }

    void output(string &start, string &last)
    {
        if (last == start)
        {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }
        else
        {
            // map[last] value is a vector.
            for (int i = 0; i < mp[last].size(); ++i)
            {
                path.push_back(mp[last][i]);
                output(start, mp[last][i]);
                path.pop_back();
            }
        }
    }

    unordered_map<string, vector<string> > mp;
    vector<vector<string> >  res;
    vector<string> path;
};

int main()
{
    Solution sln;
    std::string s("hit"), e("cog");
    std::unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    std::vector<vector<string> > v = sln.findLadders(s, e, dict);
    print2DVector<string>(v);
    return 0;
}
