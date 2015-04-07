#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        long a = 0;
        
        if (!str.empty())
        {
            int i = 0;
            int sign = 1;
            int length = str.size();

            // discard leading white space, be careful not exceed the range
            while (str[i] == ' ' && i < length)
            {
                i++;
            }

            // If the string only contains white space, then return 0.
            if (i < length)
            {
                if (str[i] == '-')
                {
                    sign = -1;
                    i++;
                }
                else if (str[i] == '+')
                {
                    i++;
                }


                for (; i < length; ++i)
                {
                    // ignore additonal non digit characters
                    if (!isdigit(str[i]))
                    {
                       break;
                    }

                    a *= 10;
                    a = a + str[i] - 48;

                    // deal with overflow case
                    // +333333333333
                    if (sign != -1 && a >= INT_MAX)
                    {
                        return INT_MAX;
                    }
                    // -33333333333
                    else if (sign == -1 && a > INT_MAX)
                    {
                        return INT_MIN;
                    }
                }

                a *= sign;
            }
        }

        return a;
    }
};

int main()
{
    Solution sln;
    string s;
    cout << "Please enter str: ";
    cin >> s;
    cout << sln.atoi(s) << endl;
    return 0;
}
