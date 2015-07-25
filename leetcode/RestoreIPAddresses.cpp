#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        int sz = s.size();

        if (sz < 4 || sz > 12)
        {
            return r;
        }

        string t;
        restore(s, 0, 0, sz, t, r);
        return r;
    }

    void restore(string &s, int j, int b, int e, string &t, vector<string> &r)
    {
        if (j >= 4)
        {
            if (b == e)
            {
                r.push_back(t);
            }

            return;
        }

        for (int i = 0; i < 3; ++i)
        {
            // Be careful to avoid accessing out of boundary.
            if (b + i + 1 > e)
            {
                break;
            }
            else if (i == 2)
            {
                // checking the boundary case 255
                if (s[b] > '2' || 
                    (s[b] == '2' && s[b + 1] > '5') || 
                    (s[b] == '2' && s[b + 1] == '5' && s[b + 2] > '5'))
                {
                    continue;
                }
            }

            string t1 = t;
            t1 += s.substr(b, i + 1);

            // Adding deliminator.
            if (j < 3)
            {
                t1 += ".";
            }

            restore(s, j + 1, b + i + 1, e, t1, r);

            // we can have 10.0.1.2
            // but we can't have 1.00.1.2
            if (s[b] == '0')
            {
                break;
            }
        }
    }
};

int main()
{
    Solution sln;
    //string s("25525511135");
    //string s("1111");
    //string s("1001");
    //string s("10000");
    //string s("10001");
    string s("10101");
    vector<string> v = sln.restoreIpAddresses(s);
    printVector<string>(v);
    return 0;
}
