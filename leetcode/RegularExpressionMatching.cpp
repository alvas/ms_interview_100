#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> v(m + 1, vector<bool>(n + 1, false));

        // because a* could match to nothing at the beginning, we need an extra row to represent this.
        // v[i][j] == true means s[0:i - 1] and p[0:j - 1] can match
        v[0][0] = true;

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] != '.' && p[j - 1] != '*')
                {
                    if (i > 0 && s[i - 1] == p[j - 1])
                    {
                        v[i][j] = v[i - 1][j - 1];
                    }
                }
                else if (i > 0 && p[j - 1] == '.')
                {
                    v[i][j] = v[i - 1][j - 1];
                }
                else if (j > 1 && p[j - 1] == '*')
                {
                    // how can a * match multiple times? p[j - 1] has been match to s[i - 2] and because s[i - 1] equals to p[j - 2] or p[j - 2] is .,
                    // p[j - 1] can match to s[i - 1].
                    if (i > 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                    {
                        v[i][j] = v[i][j] || v[i - 1][j];
                    }

                    // match 1 or 0?? Does this mean cancel previous element or ignore the *?
                    v[i][j] = v[i][j] || v[i][j - 1] || v[i][j - 2];
                    
                }
            }
        }

        return v[m][n];
    }

    bool isMatch1(string s, string p) {
        int m = s.size(), n = p.size();

        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // not '.' or '*'
                if (p[j - 1] != '.' && p[j - 1] != '*')
                {
                    if (i > 0 && s[i - 1] == p[j - 1] && dp[i - 1][j - 1])
                    {
                        dp[i][j] = true;
                    }
                }
                // '.' case
                else if (p[j - 1] == '.')
                {
                    if (i > 0 && dp[i - 1][j - 1])
                    {
                        dp[i][j] = true;
                    }
                }
                // "*" case
                else if (j > 1)
                {
                    // matching 0 or 1
                    if (dp[i][j - 1] || dp[i][j - 2])
                    {
                        dp[i][j] = true;
                    }
                    // matching multiple
                    else if (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j])
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution sln;
    //string s("aa"), p("a"); 
    //string s("aa"), p("aa"); 
    //string s("aaa"), p("aa"); 
    //string s("aa"), p("a*"); 
    //string s("aa"), p(".*"); 
    //string s("ab"), p(".*"); 
    //string s("aab"), p("c*a*b"); 

    vector<string> s = {"", "", "", "", 
                        "aa", "aa", "aaa", "aa", 
                        "aa", "ab", "aab", "aaa", 
                        "aaa", "aaa", "abcd", "a", 
                        "aaa", "aa", "aaa"};
    vector<string> p = {"", "*", ".*", "b", 
                        "a", "aa", "aa", "a*", 
                        ".*", ".*", "c*a*b", "ab*ac*a", 
                        "ab*a*c*a", ".*", "d*", "ab*", 
                        "ab*a", "c*a*", "c*a*"};

    int sz = s.size();

    for (int i = 0; i < sz; ++i)
    {
        std::cout << s[i] << ", " << p[i] << ": ";
        std::cout << sln.isMatch(s[i], p[i]) << ", " << sln.isMatch1(s[i], p[i]) << endl;
    }
    return 0;
}
