#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        int res = 0, sz = str.size();

        if (sz == 0)
        {
            return res;
        }
        
        int i = 0;

        while (i < sz && str[i] == ' ') {
            i++;
        }

        int sign = 1;

        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (str[i] == '+')
        {
            i++;
        }
        else if (!isdigit(str[i]))
        {
            return 0;
        }

        while (i < sz && isdigit(str[i]))
        {
            if (res > 214748364)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            else if (res == 214748364)
            {
                if (sign == 1 && str[i] > '7')
                {
                    return INT_MAX;
                }
                else if (sign == -1 && str[i] > '8')
                {
                    return INT_MIN;
                }
            }

            // be careful, don't use += here
            res = res * 10 + str[i] - '0';
            i++;
        }

        return sign * res;
    }

    int atoi1(string str) {
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


                //for (; i < length; ++i)
                while (i < length && isdigit(str[i]))
                {
                    // ignore additonal non digit characters
                    //if (!isdigit(str[i]))
                    //{
                       //break;
                    //}

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

                    ++i;
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
    std::string ss[] = {"+77289", "", "0", "1", "+", "-", "+-", "+3", "-4", "a", "+a", "a-", " ", "  ", " a", " -", " a0", "+a0", " 0a", "123", "023", "+023", "-023", "123+", "2147483647", "+2147483647", "2147483648", "+2147483648", "-2147483648", "-2147483649"};
    //std::cout << "Please enter str: ";
    //std::cin >> s;

    for (auto s : ss)
    {
        cout << s << ": ";
        std::cout << sln.atoi(s) << std::endl;
    }

    return 0;
}
