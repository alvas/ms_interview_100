#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (n == 0 || s[0] == '0')
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 1; i < n; ++i)
        {
            if (s[i] != '0')
            {
                dp[i + 1] += dp[i];
            }

            int v = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (10 <= v && v <= 26)
            {
                dp[i + 1] += dp[i - 1];
            }

            if (dp[i + 1] == 0)
            {
                return 0;
            }
        }

        return dp[n];
    }

    int numDecodings_slow(string s) {
        int n = s.size();

        if (n == 0)
        {
            return 0;
        }

        for (int i = 1; i <= 26; ++i)
        {
            string c = to_string(i);
            m_map[c] = 'A' + i - 1;
        }

        int ret = 0;
        decode(s, 0, n, ret);
        return ret;
    }

    void decode(string &s, int bgn, int end, int &ret)
    {
        if (bgn == end)
        {
            ret++;
            return;
        }
        else if (bgn > end)
        {
            return;
        }

        string c = s.substr(bgn, 1);

        if (c == "0")
        {
            return;
        }

        if (m_map.find(c) != m_map.end())
        {
            decode(s, bgn + 1, end, ret);
        }

        c = s.substr(bgn, 2);

        if (m_map.find(c) != m_map.end())
        {
            decode(s, bgn + 2, end, ret);
        }
    }

private:
    map<string, char> m_map;
};

int main()
{
    Solution sln;
    //string s("10");
    //string s("27");
    //string s("11");
    //string s("12");
    //string s("110");
    //string s("1221");
    //string s("1212");
    //string s("12120");
    //string s("5114");
    string s("24726");
    cout << sln.numDecodings(s) << endl;
    cout << sln.numDecodings_slow(s) << endl;
    return 0;
}
