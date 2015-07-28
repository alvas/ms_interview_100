#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Still need to improve performance. Using multimap is faster than map.
    vector<string> anagrams(vector<string>& strs) {
        vector<string> v;
        int sz = strs.size();

        if (sz == 0)
        {
            return v;
        }

        multimap<string, int> m;

        for (int i = 0; i < sz; ++i)
        {
            string a = strs[i];
            sort(a.begin(), a.end());
            m.insert(make_pair(a, i));
        }

        for (multimap<string, int>::iterator itr = m.begin();
             itr != m.end(); ++itr)
        {
            if (m.count(itr->first) > 1)
            {
                pair<multimap<string, int>::iterator, multimap<string, int>::iterator> itr2 = m.equal_range(itr->first);

                for (multimap<string, int>::iterator itr3 = itr2.first; itr3 != itr2.second; ++itr3)
                {
                    v.push_back(strs[itr3->second]);
                }

                itr = itr2.second;
                --itr;
            }
        }

        return v;
    }

    // Need to improve. Shame on me. I don't even know what this problem is talking about.
    vector<string> anagrams_map(vector<string>& strs) {
        vector<string> v;
        int sz = strs.size();

        if (sz == 0)
        {
            return v;
        }

        // saving index as vector is faster than saving a vector of string.
        map<string, vector<int> > m;

        for (int i = 0; i < sz; ++i)
        {
            string a = strs[i];
            std::sort(a.begin(), a.end());
            map<string, vector<int> >::iterator itr = m.find(a);

            if (itr != m.end())
            {
                vector<int> &b = itr->second;
                b.push_back(i);
            }
            else
            {
                vector<int> c;
                c.push_back(i);
                m.insert(make_pair(a, c));
            }
        }

        for (map<string, vector<int> >::iterator itr = m.begin();
             itr != m.end(); ++itr)
        {
            vector<int> &b = itr->second;

            if (b.size() > 1)
            {
                for (vector<int>::iterator itr2 = b.begin();
                     itr2 != b.end(); ++itr2)
                {
                    v.push_back(strs[*itr2]);
                }
            }
        }

        return v;
    }
};

int main()
{
    Solution sln;
    vector<string> strs;
    strs.push_back("abcd");
    strs.push_back("abcf");
    strs.push_back("aec");
    strs.push_back("bcad");
    strs.push_back("dacd");
    strs.push_back("eac");
    vector<string> v =  sln.anagrams(strs);
    printVector<string>(v);
    return 0;
}
