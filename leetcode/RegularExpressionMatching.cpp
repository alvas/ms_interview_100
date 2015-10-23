#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Shame on me. I can't figure out the solution.
    bool isMatch(string s, string p) {
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
    string s("aa"), p("a*"); 
    //string s("aa"), p(".*"); 
    //string s("ab"), p(".*"); 
    //string s("aab"), p("c*a*b"); 
    std::cout << sln.isMatch(s, p) << endl;
    return 0;
}
