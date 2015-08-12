#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Need to improve.
    bool isInterleave(string s1, string s2, string s3) {
        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();

        if (sz1 + sz2 != sz3)
        {
            return false;
        }
        else if (sz3 == 0)
        {
            // s1 = "", s2 = "", s3 = ""
            if (sz1 + sz2 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        vector<vector<bool> > m(sz1 + 1, vector<bool>(sz2 + 1, false));

        if (s1[0] == s3[0])
        {
            m[1][0] = true;
        }

        if (s2[0] == s3[0])
        {
            m[0][1] = true;
        }

        // be careful, need to use i <= k and int j = k -i
        // otherwise, i or j would exceed its limit
        for (int k = 2; k <= sz3; ++k)
        {
            for (int i = 0; i <= sz1 && i <= k; ++i)
            {
                int j = k - i;

                // be careful about the index i and j, and i and j > 0
                if (i > 0 && s3[k - 1] == s1[i - 1] && m[i - 1][j])
                {
                    m[i][j] = true;
                }
                else if (j > 0 && s3[k - 1] == s2[j - 1] && m[i][j - 1])
                {
                    m[i][j] = true;
                }
            }
        }

        //for (int k = 2; k <= sz3; ++k)
        //{
            //for (int i = 0; i <= sz1 && i <= k; ++i)
            //{
                //for (int j = 0; j <= sz2 && i + j <= k; ++j)
                //{
                    //if (i + j == k)
                    //{
                        //if (i > 0 && s3[k - 1] == s1[i - 1] && m[i - 1][j])
                        //{
                            //m[i][j] = true;
                        //}
                        //else if (j > 0 && s3[k - 1] == s2[j - 1] && m[i][j - 1])
                        //{
                            //m[i][j] = true;
                        //}
                    //}
                //}
            //}
        //}

        return m[sz1][sz2];
    }

    bool isInterleave_recursive(string s1, string s2, string s3) {
        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();
        return interleave(s1, sz1, 0, s2, sz2, 0, s3, sz3, 0);
    }

    bool interleave(string s1, int sz1, int i1, string s2, int sz2, int i2, string s3, int sz3, int i3)
    {
        // remember to check the final terminal case.
        if (sz1 + sz2 != sz3)
        {
            return false;
        }
        else if (i1 >= sz1 && i2 >= sz2)
        {
            return true;
        }
        else if (i1 >= sz1)
        {
            if (s2[i2] == s3[i3])
            {
                return interleave(s1, sz1, i1, s2, sz2, i2 + 1, s3, sz3, i3 + 1);
            }
            else
            {
                return false;
            }
        }
        else if (i2 >= sz2)
        {
            if (s1[i1] == s3[i3])
            {
                return interleave(s1, sz1, i1 + 1, s2, sz2, i2, s3, sz3, i3 + 1);
            }
            else
            {
                return false;
            }
        }

        if (s1[i1] == s3[i3] && s2[i2] == s3[i3])
        {
            return interleave(s1, sz1, i1 + 1, s2, sz2, i2, s3, sz3, i3 + 1) ||
                   interleave(s1, sz1, i1, s2, sz2, i2 + 1, s3, sz3, i3 + 1);
        }
        else if (s1[i1] == s3[i3])
        {
            return interleave(s1, sz1, i1 + 1, s2, sz2, i2, s3, sz3, i3 + 1);
        }
        else if (s2[i2] == s3[i3])
        {
            return interleave(s1, sz1, i1, s2, sz2, i2 + 1, s3, sz3, i3 + 1);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution sln;
    string s1("aabcc"), s2("dbbca"), s3("aadbbcbcac");
    //string s1("aabcc"), s2("dbbca"), s3("aadbbbaccc");
    //string s1("aa"), s2("ab"), s3("aaba");
    //string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"), s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"), s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
    //cout << sln.isInterleave_recursive(s1, s2, s3) << endl;
    cout << sln.isInterleave(s1, s2, s3) << endl;
    return 0;
}
