#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();

        if (sz1 + sz2 != sz3)
        {
            return false;
        }
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
    //string s1("aabcc"), s2("dbbca"), s3("aadbbbaccc");
    string s1("aa"), s2("ab"), s3("aaba");
    //string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"), s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"), s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
    cout << sln.isInterleave_recursive(s1, s2, s3) << endl;
    cout << sln.isInterleave(s1, s2, s3) << endl;
    return 0;
}
