#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ssize = s.size(), tsize = t.size();

        if (ssize != tsize)
        {
            return false;
        }

        // Be careful about the two directions.
        // s[i] maps to t[i] and t[i] maps to s[i] at the same time.
        map<char, char> m1, m2;

        for (int i = 0; i < ssize; ++i)
        {
            map<char, char>::iterator itr1 = m1.find(t[i]);
            map<char, char>::iterator itr2 = m2.find(s[i]);

            if (itr1 == m1.end() && itr2 == m2.end())
            {
                m1[t[i]] = s[i];
                m2[s[i]] = t[i];
            }
            else if (itr1 != m1.end() && itr2 != m2.end())
            {
                if ((*itr1).second != s[i] || (*itr2).second != t[i])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    string s, t;
    cout << "Please enter s: ";
    cin >> s;
    cout << "Please enter t: ";
    cin >> t;
    cout << sln.isIsomorphic(s, t) << endl;
    return 0;
}
