#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<pair<string, int> > q;
        q.push(make_pair(beginWord, 1));

        while (!q.empty())
        {
            // Don't use pair<string, int> &p, string &s here. It would cause runtime error.
            // After q.pop(), p would become invalid.
            pair<string, int> p = q.front();
            q.pop();
            string s = p.first;
            int len = p.second;

            if (s == endWord)
            {
                return len;
            }

            vector<string> neighbors = findNeighbors(s, wordDict);

            for (string &a : neighbors)
            {
                q.push(make_pair(a, len + 1));
            }
        }

        return 0;
    }

    vector<string> findNeighbors(string &s, unordered_set<string> &dict)
    {
        vector<string> ret;

        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];

            for (int j = 0; j < 26; ++j)
            {
                if (c == 'a' + j)
                {
                    continue;
                }

                s[i] = 'a' + j;

                if (dict.count(s))
                {
                    ret.push_back(s);
                    dict.erase(s);
                }
            }

            s[i] = c;
        }

        return ret;
    }

    int ladderLength_complex(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int ret = 0;

        if (beginWord == endWord)
        {
            return ret;
        }

        vector<string> v;
        v.push_back(beginWord);
        v.push_back(endWord);

        for (unordered_set<string>::iterator itr = wordDict.begin();
                itr != wordDict.end(); ++itr)
        {
            v.push_back(*itr);
        }

        int n = beginWord.size();
        int n2 = v.size();
        map<string, set<string> > m;

        for (int i = 0; i < n2; ++i)
        {
            for (int j = 0; j < n2; ++j)
            {
                if (i == j)
                {
                    continue;
                }

                int diff = 0;

                for (int k = 0; k < n; ++k)
                {
                    if (v[i][k] != v[j][k])
                    {
                        diff++;
                    }

                    if (diff > 1)
                    {
                        break;
                    }
                }

                if (diff == 1)
                {
                    m[v[i]].insert(v[j]);
                }
            }
        }

        queue<string> q;
        set<string> s;
        q.push(beginWord);
        s.insert(beginWord);
        ++ret;

        while (!q.empty())
        {
            queue<string> q2;

            while (!q.empty())
            {
                string c = q.front();
                q.pop();

                map<string, set<string> >::iterator itr = m.find(c);

                // Be careful to check whether a string has a adjacent string set.
                // If there is no other string which has only 1 character different, it doesn't have adjacent string set.
                if (itr != m.end())
                {
                    set<string> &s1 = (*itr).second;
                    set<string>::iterator itr2 = s1.find(endWord);

                    if (itr2 != s1.end())
                    {
                        return ++ret;
                    }
                    else
                    {
                        for (auto &a : s1)
                        {
                            if (s.find(a) == s.end())
                            {
                                q2.push(a);
                                s.insert(a);
                            }
                        }
                    }
                }
            }

            ++ret;
            q.swap(q2);
        }

        return 0;
    }
};

int main()
{
    Solution sln;
    //string begin("hit"), end("cog");
    //const vector<string> a = {"hot", "dot", "dog", "lot", "log"};
    string begin("a"), end("c");
    const vector<string> a = {"a", "b", "c"};
    //string begin("hot"), end("dog");
    //const vector<string> word = {"hot", "dog"};
    cout << sln.ladderLength(begin, end, word) << endl;
    return 0;
}
