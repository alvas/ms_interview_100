#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.size();

        if (sz < 1)
        {
            return 0;
        }
    }
};

int main()
{
    Solution sln;
    //string s("(()");
    //string s(")()())");
    //string s("(");
    //string s("((");
    //string s(")");
    //string s("))");
    //string s(")(");
    //string s("()(()");
    //string s("())()");
    //string s("(()()");
    //string s("()()(");
    //string s("()(())");
    string s("((())()()");
    //string s("((())()())");
    //string s(")()())()()(");
    //string s("(()(((()");
    cout << sln.longestValidParentheses(s) << endl;
    return 0;
}
