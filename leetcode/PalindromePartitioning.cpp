#include <iostream>
#include <map>
#include <utility>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> sol;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // IMPORTANT!! construct DP palindrome checking array
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; j++)
            {
                // j <= i + 2
                if ((i + 1 >= j - 1 || isPal[i + 1][j - 1]) && s[i] == s[j])
                {
                    isPal[i][j] = true;
                }
            }
        }

        findPartitions(s, 0, isPal, sol, res);
        return res;
    }

    void findPartitions(string &s, int b, vector<vector<bool>> &isPal, vector<string> &sol, vector<vector<string>> &res)
    {
        if (b == s.size())
        {
            res.push_back(sol);
            return;
        }

        for (int i = b; i < s.size(); ++i)
        {
            if (isPal[b][i])
            {
                int len = i - b + 1;
                sol.push_back(s.substr(b, len));
                findPartitions(s, i + 1, isPal, sol, res);
                sol.pop_back();
            }
        }
    }

    vector<vector<string> > partition1(string s) {
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
    //std::cout << "Please enter string: ";
    //cin >> s;
    std::cout << s << endl;
    vector<vector<string> > v = sln.partition(s);
    print2DVector<string>(v);
    return 0;
}

