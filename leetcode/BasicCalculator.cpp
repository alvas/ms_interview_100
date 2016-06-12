#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int, vector<int>> stk(vector<int>(2, 1));
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            char c = s[i];

            if (isdigit(c))
            {
                int num = c - '0';
                int j = i + 1;

                while (j < n && isdigit(s[j]))
                {
                    num = num * 10 + (s[j] - '0');
                    j++;
                }

                res += stk.top() * num;
                stk.pop();
                i = j - 1;
            }
            else if (c == '+' || c == '(')
            {
                stk.push(stk.top());
            }
            else if (c == '-')
            {
                stk.push(-1 * stk.top());
            }
            else if (c == ')')
            {
                stk.pop();
            }
        }

        return res;
    }

    int calculate1(string s) {
        int sz = s.size();

        if (sz == 0)
        {
            return 0;
        }

        // using long type to address the boundary case 2147483647
        long result = 0;
        int op = 1;
        stack<int> sign;
        stack<int> tmp;

        for (int i = 0; i < sz; ++i)
        {
            char c = s[i];

            if (c == ' ')
            {
                continue;
            }
            else if (c == '(')
            {
                sign.push(op);
                tmp.push(result);

                // When pushing the tmp result to stack, remember to reset the result and op.
                // Because only non-negative integers are allowed, op is always reset to 1.
                result = 0;
                op = 1;
            }
            else if (c == ')')
            {
                long top = 0;

                if (!tmp.empty())
                {
                    top = tmp.top();
                    tmp.pop();
                }

                int topSign = 1;

                if (!sign.empty())
                {
                    topSign = sign.top();
                    sign.pop();
                }

                result = top + (topSign * result);
            }
            else if ('0' <= c && c <= '9' )
            {
                long num = 0;

                // Be careful about changing the s[i].
                while (i < sz && '0' <= s[i] && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }

                // Be careful to move back the index, because the it points to 
                // the character after the last digit.
                if (i < sz)
                {
                    --i;
                }

                // using op to infer addition or substraction
                result += op * num;
            }
            else if (c == '+')
            {
                op = 1;
            }
            else if (c == '-')
            {
                op = -1;
            }
        }

        return result;
    }
};

int main()
{
    Solution sln;
    //string s("1 + 1");
    string s(" 2-1 + 2");
    //string s("(1+(4+5+2)-3)+(6+8)");
    //string s("2147483647");
    //string s("2-(5-6)");
    std::cout << sln.calculate(s) << endl;
    return 0;
}
