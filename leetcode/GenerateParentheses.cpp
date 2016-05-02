#include <iostream>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        findParenthesis(v, s, 0, 0, n);
        return v;
    }

    void findParenthesis(vector<string> &v, string s, int l, int r, int n)
    {
        if (r == n)
        {
            v.push_back(s);
            return;
        }

        if (l < n)
        {
            findParenthesis(v, s + '(', l + 1, r, n);
        }

        if (r < l)
        {
            findParenthesis(v, s + ')', l, r + 1, n);
        }

        //if (r == n)
        //{
            //v.push_back(s);
        //}
        //else if (l == n)
        //{
            //findParenthesis(v, s + ')', l, r + 1, n);
        //}
        //else
        //{
            //if (l > r)
            //{
                //findParenthesis(v, s + ')', l, r + 1, n);
            //}

            //findParenthesis(v, s + '(', l + 1, r, n);
        //}
    }

    vector<string> generateParenthesis1(int n) {
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
    std::cout << "Please enter n:";
    cin >> n;
    vector<string> v = sln.generateParenthesis(n);
    printVector<string>(v);
    return 0;
}
