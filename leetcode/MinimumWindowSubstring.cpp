#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    // need to improve
    string minWindow(string s, string t) {
        string ret;
        int nS = s.size(), nT = t.size();

        if (nS == 0 || nT == 0)
        {
            return ret;
        }

        map<char, int> mT;

        for (char &c : t)
        {
            mT[c]++;
        }

        queue<pair<char, int> > q;
        map<char, int> m2;
        int minL = nS + 1, count = 0;

        for (int i = 0; i < nS; ++i)
        {
            if (mT.count(s[i]) == 0)
            {
                continue;
            }
            else
            {
                if (q.empty())
                {
                    q.push(make_pair(s[i], i));
                    m2[s[i]]++;
                    count++;

                    if (count == nT)
                    {
                        ret = s.substr(i, 1);
                        return ret;
                    }
                }
                // be careful, don't use m2.count(s[i]) here, it would be 1, not the number of elements.
                else if (m2[s[i]] < mT[s[i]])
                {
                    q.push(make_pair(s[i], i));
                    m2[s[i]]++;
                    count++;

                    if (count == nT)
                    {
                        pair<char, int> f = q.front();

                        int len = i - f.second + 1;

                        if (len < minL)
                        {
                            minL = len;
                            ret = s.substr(f.second, len);
                        }
                    }
                }
                else
                {
                    q.push(make_pair(s[i], i));
                    m2[s[i]]++;
                    pair<char, int> f = q.front();

                    while (m2[f.first] > mT[f.first])
                    {
                        q.pop();
                        m2[f.first]--;

                        if (!q.empty())
                        {
                            f = q.front();
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (count == nT)
                    {
                        if (!q.empty())
                        {
                            f = q.front();
                            int len = i - f.second + 1;

                            if (len < minL)
                            {
                                minL = len;
                                ret = s.substr(f.second, len);
                            }
                        }
                    }
                }
            }
        }

        return ret;
    }

    // time limit exceed
    string minWindow_slow(string s, string t) {
        string ret;
        int nS = s.size(), nT = t.size();

        map<char, int> mT;

        for (char &c : t)
        {
            mT[c]++;
        }

        int minL = nS + 1;

        for (int i = nT; i <= nS; ++i)
        {
            for (int j = 0; j <= nS - nT; ++j)
            {
                map<char, int> m2 = mT;

                for (int k = 0; k < i; ++k)
                {
                    if (m2.count(s[j + k]) == 0)
                    {
                        continue;
                    }
                    else
                    {
                        m2[s[j + k]]--;

                        if (m2[s[j + k]] == 0)
                        {
                            m2.erase(s[j + k]);
                        }
                    }
                }

                if (m2.empty() && i < minL)
                {
                    minL = i;
                    ret = s.substr(j, i);
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution sln;
    //string s("ADOBECODEBANC"), t("ABC");
    string s("aa"), t("aa");
    std::cout << sln.minWindow_slow(s, t) << endl;
    std::cout << sln.minWindow(s, t) << endl;
    return 0;
}
