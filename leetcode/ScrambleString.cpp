#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // DP. Can't figure out the solution.
    bool isScramble(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();

        if (sz1 != sz2)
        {
            return false;
        }
        else if (sz1 == 0)
        {
            return true;
        }

        // c[k][i][j] means s1[i...i+k] is scramble of s2[j...j+k]
        vector<vector<vector<bool> > > c(sz1, vector<vector<bool> >(sz1, vector<bool>(sz1, false)));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                c[0][i][j] = (s1[i] == s2[j]);
            }
        }

        // k is the limit of the scramble string lenght.
        for (int k = 2; k <= sz1; ++k)
        {
            for (int i = sz1 - k; i >= 0; --i)
            {
                for (int j = sz1 - k; j >= 0; --j)
                {
                    bool r = false;

                    // partition string of lenght k with m and k - m.
                    for (int m = 1; m < k && !r; ++m)
                    {
                        // s1[i...i+m] s2[j...j+m]        s1[i+m...i+k] s2[j+m...j+k] ||
                        // s1[i...i+m] s2[j+k-m...j+k]    s1[i+m...i+k] s2[j...j+k-m]
                        r = (c[m - 1][i][j] && c[k - m - 1][i + m][j + m]) ||
                            (c[m - 1][i][j + k - m] && c[k - m - 1][i + m][j]);
                    }

                    c[k - 1][i][j] = r;
                }
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                for (int k = 0; k < sz1; ++k)
                {
                    std::cout << c[i][j][k] << "\t";
                }

                std::cout << endl;
            }

            std::cout << endl;
        }

        return c[sz1 - 1][0][0];
    }

    // Recursive solution.
    bool isScramble_resursive(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();

        if (sz1 != sz2)
        {
            return false;
        }

        int a[26] = {0}, b[26] = {0};

        for (int i = 0; i < sz1; ++i)
        {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }

        // Be careful here, it is 26, not sz1.
        for (int i = 0; i < 26; ++i)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }

        if (sz1 == 1)
        {
            return true;
        }

        bool scramble = false;

        for (int i = 1; i < sz1 && !scramble; ++i)
        {
            //scramble = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, sz1 - i), s2.substr(i, sz1 - i))) || 
                       //(isScramble(s1.substr(0, i), s2.substr(sz1 - i, i)) && isScramble(s1.substr(i, sz1 - i), s2.substr(0, sz1 - i)));
            scramble = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || 
                       (isScramble(s1.substr(0, i), s2.substr(sz1 - i)) && isScramble(s1.substr(i), s2.substr(0, sz1 - i)));
        }

        return scramble;
    }
};

int main()
{
    Solution sln;
    string s1("rgtae"), s2("great");
    //string s1("abcd"), s2("bdac");
    std::cout << "s1: " << s1 << endl;
    std::cout << "s2: " << s2 << endl;
    //string s1("xstjzkfpkggnhjzkpfjoguxvkbuopi"), s2("xbouipkvxugojfpkzjhnggkpfkzjts");
    std::cout << sln.isScramble(s1, s2) << endl;
    return 0;
}
