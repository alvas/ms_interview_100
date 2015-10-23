#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int n = words.size();

        if (n == 0)
        {
            return ret;
        }

        int n2 = s.size();
        int n3 = words[0].size();
        int n4 = n3 * n;
        map<string, int> m1, m2;

        for (int i = 0; i < n; ++i)
        {
            m1[words[i]]++;
        }

        // Be careful about <= here.
        for (int i = 0; i <= n2 - n4; ++i)
        {
            m2.clear();
            bool misMatch = false;

            for (int j = 0; j < n; ++j)
            {
                string s2 = s.substr(i + j * n3, n3);

                if (m1.find(s2) != m1.end())
                {
                    m2[s2]++;
                }
                else
                {
                    misMatch = true;
                    break;
                }

                if (m2[s2] > m1[s2])
                {
                    misMatch = true;
                    break;
                }
            }

            if (!misMatch)
            {
                ret.push_back(i);
            }
        }

        return ret;
    }

    // time limit exceeded
    vector<int> findSubstring_slow(string s, vector<string>& words) {
        vector<int> ret;
        int n = words.size();

        if (n == 0)
        {
            return ret;
        }

        vector<int> v;

        for (int i = 0; i < n; ++i)
        {
            v.push_back(i);
        }

        // if I use set, time limit exceed.
        // if I use unordered_set, memory limit exceed.
        set<string> allWordSet;

        do
        {
            string s1;

            for (int &a : v)
            {
                s1 += words[a];
            }

            allWordSet.insert(s1);
        }
        while (next_permutation(v.begin(), v.end()));

        int n3 = words[0].size();
        int n4 = n3 * n;
        int n2 = s.size();

        for (int i = 0; i <= n2 - n4; ++i)
        {
            string s2 = s.substr(i, n4);

            if (allWordSet.find(s2) != allWordSet.end())
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};

int main()
{
    Solution sln;
    //string s("barfoothefoobarmana");
    //const vector<string> words = {"foo", "bar"};
    string s("wordgoodgoodgoodbestword");
    const vector<string> words = {"word","good","best","good"};
    //vector<int> v = sln.findSubstring_slow(s, words);
    vector<int> v = sln.findSubstring(s, words);
    printVector<int>(v);
    return 0;
}
