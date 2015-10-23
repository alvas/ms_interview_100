#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        bool star = false;
        int  i = 0, j = 0, ii = 0, jj = 0;
        
        for ( ; i < m; ++i, ++j)
        {
            switch (p[j])
            {
                case '?' :
                    {
                        break;
                    }
                case '*':
                    {
                        star = true;
                        
                        ii = i, jj = j;

                        while (p[jj] == '*')
                        {
                            jj++;
                        }

                        if (jj >= n)
                        {
                            return true;
                        }

                        i = ii - 1;
                        j = jj - 1;
                        break;
                    }
                default:
                    {
                        if (s[i] != p[j])
                        {
                            if (!star)
                            {
                                return false;
                            }

                            ii++;

                            i = ii - 1;
                            j = jj - 1;
                        }
                    }
            }
        }

        // skip all '*' at the end of p
        while (p[j] == '*')
        {
            j++;
        }

        return (j >= n);
    }

    bool isMatch_1D(string s, string p) {
        int m = s.size(), n = p.size();

        if (m == 0 && n == 0)
        {
            return true;
        }
        // If s is empty, p is not empty but p is all '*', it could still match.
        else if (/*m == 0 || */n == 0)
        {
            return false;
        }

        vector<bool> dp(m + 1, false);

        for (int i = 1; i <= m; ++i)
        {
            dp[0] = i == 1 ? true : false;
            bool diag = dp[0];

            for (int j = 1; j <= n; ++j)
            {
                int tmp = dp[j];

                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                {
                    dp[j] = i > 0 && diag;
                }
                else if (p[j - 1] == '*')
                {
                    dp[j] = dp[j - 1] || (i > 0 && (diag || dp[j]));
                }

                diag = tmp;
            }
        }

        return dp[n];
    }

    bool isMatch_2D(string s, string p) {
        int m = s.size(), n = p.size();

        if (m == 0 && n == 0)
        {
            return true;
        }
        // If s is empty, p is not empty but p is all '*', it could still match.
        else if (/*m == 0 ||*/ n == 0)
        {
            return false;
        }

        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    // match 0, 1 and multiple characters
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution sln;
    //string s("aa"), p("aa");
    string s("aab"), p("a*a*b");
    std::cout << sln.isMatch_2D(s, p) << endl;
    std::cout << sln.isMatch_1D(s, p) << endl;
    std::cout << sln.isMatch(s, p) << endl;
    return 0;
}
