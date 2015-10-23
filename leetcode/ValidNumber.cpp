#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        // count space at the begininig
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i == n)
        {
            return false;
        }

        n--;

        // count space at the end
        while (n >= i && s[n] == ' ')
        {
            n--;
        }

        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }

        bool num = false, dot = false, exp = false;

        while (i <= n)
        {
            char c = s[i];

            if (isdigit(c))
            {
                num = true;
            }
            else if (c == '.')
            {
                // can't be double dot
                // exp and dot can't exist at the same time
                if (exp || dot)
                {
                    return false;
                }

                dot = true;
            }
            else if (c == 'e')
            {
                // can't be double exp
                // exp can't be the first character
                if (exp || num == false)
                {
                    return false;
                }

                exp = true;

                // exp can't the be last one. 
                num = false;
            }
            else if (c == '+' || c == '-')
            {
                // '+'/'-' in the middle, it must be like this 222e+10
                if (s[i - 1] != 'e')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

            i++;
        }

        return num;
    }
};

int main()
{
    Solution sln;
    //string s("0");
    //string s("0.1");
    //string s("abc");
    string s("1 a");
    //string s("2e10");
    std::cout << sln.isNumber(s) << endl;
    return 0;
}
