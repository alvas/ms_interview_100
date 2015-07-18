#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int sz1 = num1.size(), sz2 = num2.size();
        string result;

        if (sz1 == 0 || sz2 == 0)
        {
            return result;
        }
        else if (sz1 == 1)
        {
            int a = atoi(num1.c_str());

            if (a == 0)
            {
                result = "0";
                return result;
            }
            else if (a == 1)
            {
                return num2;
            }
        }
        else if (sz2 == 1)
        {
            int a = atoi(num2.c_str());

            if (a == 0)
            {
                result = "0";
                return result;
            }
            else if (a == 1)
            {
                return num1;
            }
        }

        int startDigit = 0, length = 0, carry = 0;

        for (int i = sz1 - 1; i >= 0; --i)
        {
            int digit = startDigit;
            int a = num1[i] - 48;

            for (int j = sz2 - 1; j >= 0; --j)
            {
                int b = num2[j] - 48;
                int c = a * b + carry;

                if (digit >= length)
                {
                    result.push_back(c % 10 + 48);
                    length++;
                }
                else
                {
                    // Be careful about the calculation here.
                    // Don't forget to add the result[digit] to c here.
                    c += result[digit] - 48;
                    result[digit] = c % 10 + 48;
                }

                carry = c / 10;
                digit++;
            }

            if (carry != 0)
            {
                result.push_back(carry + 48);
                length++;
                carry = 0;
            }

            startDigit++;
        }

        if (carry != 0)
        {
            result.push_back(carry + 48);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    Solution sln;
    string num1, num2;
    cout << "Please enter num1: ";
    cin >> num1;
    cout << "Please enter num2: ";
    cin >> num2;
    cout << sln.multiply(num1, num2) << endl;
    return 0;
}
