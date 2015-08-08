#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        
        if (sz <= 1)
        {
            return s;
        }

        map<char, vector<int> > m;

        for (int i = 0; i < sz; ++i)
        {
            char c = s[i];
            map<char , vector<int> >::iterator itr = m.find(c);

            if (itr == m.end())
            {
                vector<int> v;
                v.push_back(i);
                m.insert(make_pair(c, v));
            }
            else
            {
                vector<int> &v = itr->second;
                v.push_back(i);
            }
        }

        string r;

        return r;
    }
};

int main()
{
    Solution sln;
    string s("aaabcdefedcbazzz");
    cout << sln.longestPalindrome(s) << endl;
    return 0;
}
