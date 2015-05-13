#include <iostream>
#include <map>
#include <utility>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<string> v;
        vector<vector<string> > r;

        // If recursive call needs more parameter, need a seperate recursive routine to 
        // achieve this.
        seperate_recursive(s, 0, v, r);
        return r;
    }

    void seperate_recursive(const string &s, int start, vector<string> &v, vector<vector<string> > &r)
    {
        if (start == s.size())
        {
            r.push_back(v);
            return;
        }

        for (int i = start; i < s.size(); ++i)
        {
            if (isPalindrome(s, start, i + 1))
            {
                v.push_back(s.substr(start, i + 1 - start));
                seperate_recursive(s, i + 1, v, r);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end)
    {
        end--;

        while (start < end)
        {
            if (s[start++] != s[end--])
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
    //string s("aab");
    string s("ABCCBABBDFGGFDBBABC");
    //cout << "Please enter string: ";
    //cin >> s;
    cout << s << endl;
    vector<vector<string> > v = sln.partition(s);
    print2DVector<string>(v);
    return 0;
}

