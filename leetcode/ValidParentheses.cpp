#include <iostream>
#include <stack>

using namespace std;

const int LENGTH = 256;

class Solution {
public:
    bool isValid(string s) {
        bool valid = true;
        stack<char> stk;

        for (string::iterator itr = s.begin(); itr != s.end(); ++itr)
        {
            if (*itr == '(' || *itr == '{' || *itr == '[')
            {
                stk.push(*itr);
            }
            else
            {
                if (!stk.empty())
                {
                    if ((*itr == ')' && stk.top() == '(') ||
                        (*itr == '}' && stk.top() == '{') ||
                        (*itr == ']' && stk.top() == '['))
                    {
                        stk.pop();
                    }
                    else
                    {
                        valid = false;
                        break;
                    }
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }

        // Be carefull about the string "["
        if (!stk.empty())
        {
            valid = false;
        }
                
        return valid;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    char str[LENGTH];
    gets(str);
    string s(str);
    cout << sln.isValid(s) << endl;
}

