#include <iostream>
#include <map>
#include <string>

#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0, preNum = 0;

        for (string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
        {
            int num = symbols[*rit];

            if (preNum != 0 && num < preNum)
            {
                sum -= num;
            }
            else
            {
                sum += num;
            }

            preNum = num;
        }

        return sum;
    }

    Solution() {
        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;
    }

private:
    map<char, int> symbols;
};

int main(int argc, char *argv[])
{
    Solution sln;
    string str;

    if (argc > 1)
    {
        str = argv[1];
    }
    else
    {
        cin >> str;;
    }

    std::cout << str << ": " << sln.romanToInt(str) << endl;
    return 0;
}

