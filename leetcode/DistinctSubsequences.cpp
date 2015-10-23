#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Shame on me, I can't figure out the DP solution.
    int numDistinct(string s, string t) {
        int sz1 = s.size(), sz2 = t.size();

        if (sz1 == 0 || sz2 == 0 || sz1 < sz2)
        {
            return 0;
        }

        vector<int> v(sz2 + 1, 0);
        v[0] = 1;

        // Be careful i is from 1 to sz1
        for (int i = 1; i <= sz1; ++i)
        {
            // Be careful j is from 1 to sz2
            for (int j = sz2; j >= 1; --j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    v[j] += v[j - 1];
                }
            }

            printVector<int>(v);
        }

        return v[sz2];
    }

    int numDistinct_naive(string s, string t) {
        int sz1 = s.size(), sz2 = t.size();

        if (sz1 == 0 || sz2 == 0 || sz1 < sz2)
        {
            return 0;
        }

        int num = 0;
        find(s, 0, sz1, t, 0, sz2, num);
        return num;
    }

    void find(string &s, int i, int sz1, string &t, int j, int sz2, int &num)
    {
        if (i >= sz1)
        {
            if (j == sz2)
            {
                num++;
            }

            return;
        }
        else if (j >= sz2)
        {
            num++;
            return;
        }

        if (s[i] != t[j])
        {
            find(s, i + 1, sz1, t, j, sz2, num);
        }
        else
        {
            find(s, i + 1, sz1, t, j, sz2, num);
            find(s, i + 1, sz1, t, j + 1, sz2, num);
        }
    }
};

int main()
{
    Solution sln;
    //string s("abcbabc"), t("abc");
    string s("aba"), t("ab");
    std::cout << "s: " << s << endl;
    std::cout << "t: " << t << endl;
    //string s("rabbbit"), t("rabbit");
    //string s("ABCDE"), t("AEC");
    //string s("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac"), t("ceadbaa");
    //std::cout << "Please enter S: " << endl;
    //cin >> s;
    //std::cout << "Please enter T: " << endl;
    //cin >> t;
    //std::cout << sln.numDistinct_naive(s, t) << endl;
    std::cout << sln.numDistinct(s, t) << endl;
    return 0;
}
