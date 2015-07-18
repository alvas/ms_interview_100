#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        string t;
        int sz = s.size();
        restore(s, 0, 0, sz, t, r);
        return r;
    }

    void restore(string &s, int i, int b, int e, string &t, vector<string> &r)
    {
        if (i >= 4)
        {
            if (b >= e)
            {
                r.push_back(t);
            }

            return;
        }
    }
};

int main()
{
    Solution sln;
    string s("25525511135");
    vector<string> v = sln.restoreIpAddresses(s);
    printVector<string>(v);
    return 0;
}
