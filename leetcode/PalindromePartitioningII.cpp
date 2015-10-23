#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<int> cuts(n + 1, 0);

        for (int i = 0; i <= n; ++i)
        {
            cuts[i] = i - 1;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j)
            {
                cuts[i + j + 1] = min(cuts[i + j + 1], 1 + cuts[i - j]);
            }

            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; ++j)
            {
                cuts[i + j + 1] = min(cuts[i + j + 1], 1 + cuts[i - j + 1]);
            }
        }

        return cuts[n];
    }

    int minCut_1(string s) {
        int n = s.size();
        vector<int> D(n + 1, 0);
        vector<vector<bool> > P(n, vector<bool>(n, false));

        for (int i = 0; i <= n; ++i)
        {
            D[i] = n - i - 1;
        }

        // P[i][j] is palindrome if s[i] == s[j] && P[i + 1][j - 1] is palindrome;
        // or s[i] == s[j] && j - i < 2 , which means s[i] == s[i] || s[i] == s[i + 1].
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j] && (j - i < 2 || P[i + 1][j - 1]))
                {
                    P[i][j] = true;
                    D[i] = min(D[i], D[j + 1] + 1);
                }
            }
        }

        return D[0];
    }
};

int main()
{
    Solution sln;
    //string s("aab");
    //string s("aabb");
    //string s("abc");
    string s("aba");
    //string s("abab");
    //string s("abcba");
    //string s("fff");
    //string s("ccaacabacb");
    //string s("ababbbabbaba");
    //string s("cabababcbc");
    //string s("abcccb");
    //string s("eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj");
    std::cout << s << endl;
    std::cout << sln.minCut(s) << endl;
    return 0;
}
