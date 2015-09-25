#include <iostream>
#include <map>
#include <string>

#include <stdlib.h>
#include <time.h>

using namespace std;

const int RANGE = 3999;

class Solution {
    public:
        string intToRoman(int num) {
            static int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            static string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

            string roman;

            int i = 0;

            while (num > 0)
            {
                int k = num / values[i];

                for (int j = 0; j < k; ++j)
                {
                    roman += symbols[i];
                    num -= values[i];
                }

                ++i;
            }

            return roman;
        }

        string intToRoman1(int num) {
            string number;
            int t1 = 1000;

            while (num)
            {
                int digit = num / t1;

                switch (digit)
                {
                    case 1:
                    case 2:
                    case 3:
                    {
                        number += string(digit, symbols[t1]);
                        break;
                    }
                    case 4:
                    {
                        number = number + string(1, symbols[t1]) + string(1, symbols[5 * t1]);
                        break;
                    }
                    case 5:
                    {
                        number += string(1, symbols[5 * t1]);
                        break;
                    }
                    case 6:
                    case 7:
                    case 8:
                    {
                        number += string(1, symbols[5 * t1]);
                        digit -= 5;
                        number += string(digit, symbols[t1]);

                        break;
                    }
                    case 9:
                    {
                        number = number + string(1, symbols[t1]) + string(1, symbols[10 * t1]);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }

                num %= t1;
                t1 /= 10;
            }

            return number;
        }

        Solution() {
            symbols[1] = 'I';
            symbols[5] = 'V';
            symbols[10] = 'X';
            symbols[50] = 'L';
            symbols[100] = 'C';
            symbols[500] = 'D';
            symbols[1000] = 'M';
        }
    private:
        map<int, char> symbols;
};

int main(int argc, char *argv[])
{
    Solution sln;
    int num = 0;

    if (argc > 1)
    {
        num = atoi(argv[1]);
    }
    else
    {
        srand(time(NULL));
        num = (rand() % RANGE) + 1;
        //cin >> num;
    }

    cout << num << ": " << sln.intToRoman(num) << endl;
    return 0;
}

