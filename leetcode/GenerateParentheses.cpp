#include <iostream>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        // Be careful 2 * n.
        build(v, s, 0, 2 * n);
        return v;
    }

    void build(vector<string> &v, string &s, int value, int n)
    {
        // Be careful when n < 0 and return.
        if (n <= 0)
        {
            if (n == 0 && value == 0)
            {
                v.push_back(s);
            }

            return;
        }

        if (value + 1 > 0)
        {
            string tmp = s + "(";
            build(v, tmp, value + 1, n - 1);
        }
        
        if (value - 1 >= 0)
        {
            string tmp = s + ")";
            build(v, tmp, value - 1, n - 1);
        }
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n:";
    cin >> n;
    vector<string> v = sln.generateParenthesis(n);
    printVector<string>(v);
    return 0;
}
