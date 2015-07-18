#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<string> s;
        int sz = s.size();

        if (sz == 0)
        {
            return 0;
        }

        int result = 0;

        for (int i = 0; i < sz; ++i)
        {
            char c = string[i];

            if (c == ' ' || c == '(' || c == ')')
            {
                continue;
            }

            if (48 <= c && c < 58)
            {
                int num = 0;

                while (i < sz && 48 <= c && c < 58)
                {
                    num += num * 10 + (c - 48);
                }
            }
            else if (c == 43 || c == 45)
            {
            }
        }

        return result;
    }
};

int main()
{
    Solution sln;
    string s("1 + 1");
    //string s(" 2-1 + 2");
    //string s("(1+(4+5+2)-3)+(6+8)");
    cout << sln.calculate(s) << endl;
    cout << sln.calculate(s) << endl;
    return 0;
}
