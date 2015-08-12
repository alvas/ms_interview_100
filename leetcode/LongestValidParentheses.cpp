#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.size();

        if (sz < 1)
        {
            return 0;
        }

        int maxV = 0;
        vector<int> dp(sz + 1, 0);

        for (int i = 1; i <= sz; ++i)
        {
            //        )      ( .........  )       )
            //               |------------|
            //        j     j+1    x     i-2     i-1
            // dp[j]                   dp[i-1] dp[i]
            //
            //        (      ( .........  )       )
            //               |------------|
            //        j     j+1    x     i-2     i-1
            // dp[j]                   dp[i-1] dp[i] = dp[j] + 2 + d[i - 1]
            int j = i - 2 - dp[i - 1];

            if (s[i - 1] == '(' || j < 0 || s[j] == ')')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i - 1] + 2 + dp[j];
                maxV = max(maxV, dp[i]);
            }
        }

        printVector<int>(dp);

        return maxV;
    }

    int longestValidParentheses1(string s) {
        int sz = s.size();

        if (sz < 1)
        {
            return 0;
        }

        int nMax = 0;
        vector<int> stk;

        for (int i = 0; i < sz; ++i)
        {
            if (s[i] == '(')
            {
                stk.push_back(i);
            }
            else
            {
                if (!stk.empty() && s[stk.back()] == '(')
                {
                    stk.pop_back();
                    nMax = std::max(nMax, i - (stk.empty() ? - 1 : stk.back()));
                }
                else
                {
                    stk.push_back(i);
                }
            }
        }

        return nMax;
    }

    //int longestValidParentheses_wrong(string s) {
        //int sz = s.size();

        //if (sz < 1)
        //{
            //return 0;
        //}

        //int maxCount = 0;
        //stack<char> stk;
        //stack<int> close, open;

        //for (int i = 0; i < sz; ++i)
        //{
            //if (s[i] == '(')
            //{
                //stk.push(s[i]);
            //}
            //else
            //{
                //if (stk.empty())
                //{
                    //int cur = 0;

                    //while (!open.empty())
                    //{
                        //cur += open.top();
                        //open.pop();
                    //}

                    //while (!close.empty())
                    //{
                        //close.pop();
                    //}

                    //maxCount = max(maxCount, cur);
                //}
                //else
                //{
                    //stk.pop();

                    //if (stk.empty())
                    //{
                        //int cur = 0;

                        //while (!open.empty())
                        //{
                            //cur += open.top();
                            //open.pop();
                        //}

                        //cur += 2;

                        //if (!close.empty())
                        //{
                            //int top = close.top();
                            //cur += top;
                            //close.pop();
                            //close.push(cur);
                        //}
                        //else
                        //{
                            //close.push(cur);
                        //}

                        //maxCount = max(maxCount, cur);
                    //}
                    //else
                    //{
                        //open.push(2);
                    //}
                //}
            //}
        //}

        //int cur = 0;

        //while (!open.empty())
        //{
            //cur += open.top();
            //open.pop();
        //}

        //maxCount = max(maxCount, cur);

        //return maxCount;
    //}
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
    //string s("((())()()");
    string s("((())()())");
    //string s(")()())()()(");
    //string s("(()(((()");
    cout << s << endl;
    cout << sln.longestValidParentheses(s) << endl;
    return 0;
}
