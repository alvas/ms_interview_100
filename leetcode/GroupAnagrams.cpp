#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& strs) {
        vector<vector<string>> res;

        int n = strs.size();
        map<string, vector<string>> m;

        for (int i = 0; i < n; ++i)
        {
            string a = strs[i];
            sort(a.begin(), a.end());
            m[a].push_back(strs[i]);
        }

        for (auto itr = m.begin(); itr != m.end(); ++itr)
        {
            res.push_back(itr->second);
        }

        return res;
    }

    vector<string> anagrams1(vector<string>& strs) {
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
};

int main()
{
    Solution sln;
    return 0;
}
