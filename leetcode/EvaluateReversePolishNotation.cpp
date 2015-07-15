#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int val = 0;
        int sz = tokens.size();
        map<string, int> m;
        m.insert(make_pair("+", 0));
        m.insert(make_pair("-", 1));
        m.insert(make_pair("*", 2));
        m.insert(make_pair("/", 3));
        stack<int> s;

        for (int i = 0; i < sz; ++i)
        {
            map<string, int>::iterator itr = m.find(tokens[i]);

            if (itr == m.end())
            {
                s.push(atoi(tokens[i].c_str()));
            }
            else
            {
                int result = 0, a = 0, b = 0;

                if (!s.empty())
                {
                    b = s.top();
                    s.pop();
                }

                if (!s.empty())
                {
                    a = s.top();
                    s.pop();
                }

                switch (itr->second)
                {
                    case 0:
                    {
                        result = a + b;
                        break;
                    }
                    case 1:
                    {
                        result = a - b;
                        break;
                    }
                    case 2:
                    {
                        result = a * b;
                        break;
                    }
                    case 3:
                    {
                        result = a / b;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }

                s.push(result);
            }
        }
        
        if (!s.empty())
        {
            val = s.top();
        }

        return val;
    }
};

int main()
{
    Solution sln;
    //string a[] = {"2", "1", "+", "3", "*"};
    string a[] = {"4", "13", "5", "/", "+"};
    vector<string> tokens(a, a + SIZE(a));
    cout << sln.evalRPN(tokens) << endl;
    return 0;
}
