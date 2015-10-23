#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int sz = s.size();

        if (sz == 0)
        {
            return 0;
        }

        stack<long> tmp;
        stack<char> opStack;

        for (int i = 0; i < sz; ++i)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                // !!! Be creaful. Can't use if here.
                // We need to use a while loop to process all calculations
                // on the stack. Otherwise, all leftover on the stack would
                // be process from the back. This would be wrong.
                // A minus operation would not be performed properly.
                while (!opStack.empty())
                {
                    char op = opStack.top();

                    // Can't process '+' or '-' here.
                    // Only process '*' and '/' here. Remember to pop out op
                    opStack.pop();
                    int first = 0, second = 0;
                    
                    // Be careful about which is first and which is second
                    if (!tmp.empty())
                    {
                        second = tmp.top();
                        tmp.pop();
                    }

                    if (!tmp.empty())
                    {
                        first = tmp.top();
                        tmp.pop();
                    }

                    if (op == '+')
                    {
                        tmp.push(first + second);
                    }
                    else if (op == '-')
                    {
                        tmp.push(first - second);
                    }
                    else if (op == '*')
                    {
                        tmp.push(first * second);
                    }
                    else if (op == '/' && second != 0)
                    {
                        tmp.push(first / second);
                    }
                }

                opStack.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                if (!opStack.empty())
                {
                    char op = opStack.top();

                    // Can't process '+' or '-' here.
                    // Only process '*' and '/' here. Remember to pop out op
                    if (op == '*' || op == '/')
                    {
                        opStack.pop();
                        int first = 0, second = 0;
                        
                        // Be careful about which is first and which is second
                        if (!tmp.empty())
                        {
                            second = tmp.top();
                            tmp.pop();
                        }

                        if (!tmp.empty())
                        {
                            first = tmp.top();
                            tmp.pop();
                        }


                        if (op == '*')
                        {
                            tmp.push(first * second);
                        }
                        else if (op == '/' && second != 0)
                        {
                            tmp.push(first / second);
                        }
                    }
                }

                // Be careful about the position of this push here.
                // Can't put it inside the if checking, because if the first op is
                // '*' or '/', it would be missed.
                opStack.push(s[i]);
            }
            else if ('0' <= s[i] && s[i] <= '9')
            {
                int num = 0;

                while (i < sz && '0' <= s[i] && s[i] <= '9')
                {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }

                if (i < sz)
                {
                    --i;
                }

                tmp.push(num);
            }
        }

        while (!opStack.empty())
        {
            int first = 0, second = 0;
            
            // Be careful about which is first and which is second
            if (!tmp.empty())
            {
                second = tmp.top();
                tmp.pop();
            }

            if (!tmp.empty())
            {
                first = tmp.top();
                tmp.pop();
            }

            char op = opStack.top();
            
            // Don't forget to pop out the op
            opStack.pop();

            if (op == '+')
            {
                tmp.push(first + second);
            }
            else if (op == '-')
            {
                tmp.push(first - second);
            }
            else if (op == '*')
            {
                tmp.push(first * second);
            }
            else if (op == '/' && second != 0)
            {
                tmp.push(first / second);
            }
        }

        long result = 0;

        if (!tmp.empty())
        {
            result = tmp.top();
        }

        return result;
    }
};

int main()
{
    Solution sln;
    //string s("3+2*2");
    //string s("3/2");
    //string s("3+5 / 2");
    //string s("7");
    //string s("7 /  3 * 3 / 3 * 3");
    //string s("3 / 7 * 4 / 2 / 3 / 5");
    //string s("1-1+1");
    //string s("2*3+4");
    string s("1*2-3/4+5*6-7*8+9/10");
    std::cout << sln.calculate(s) << endl;
    return 0;
}
