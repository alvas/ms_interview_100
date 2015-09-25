#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool valid = true;
        stack<char> stk;
        map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        for (string::iterator itr = s.begin(); itr != s.end(); ++itr)
        {
            //if (*itr == '(' || *itr == '{' || *itr == '[')

            if (m.find(*itr) != m.end())
            {
                stk.push(*itr);
            }
            else
            {
                if (stk.empty() || m[stk.top()] != *itr)
                {
                    return false;
                }

                // don't forget this
                stk.pop();

                //if (!stk.empty())
                //{
                    ////if ((*itr == ')' && stk.top() == '(') ||
                        ////(*itr == '}' && stk.top() == '{') ||
                        ////(*itr == ']' && stk.top() == '['))
                    //if (m[stk.top()] == *itr)
                    //{
                        //stk.pop();
                    //}
                    //else
                    //{
                        //valid = false;
                        //break;
                    //}
                //}
                //else
                //{
                    //valid = false;
                    //break;
                //}
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
    //char str[256];
    //gets(str);
    //string s(str);
    string s("(())([{}])");
    cout << sln.isValid(s) << endl;
}

