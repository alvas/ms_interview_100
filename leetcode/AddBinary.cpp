#include <iostream>

using namespace std;

class Solution {
public:
    // can't use bitset here, because it would get error: 
    // non-type template argument of type 'int' is not an integral constant expression
    string addBinary(string a, string b) {
        string c;
        int carry = 0;
        string::reverse_iterator rit1 = a.rbegin(), rit2 = b.rbegin();

        for ( ; rit1 != a.rend() && rit2 != b.rend(); ++rit1, ++rit2)
        {
            int bit1 = *rit1 - 48;
            int bit2 = *rit2 - 48;
            int bit3 = bit1 + bit2 + carry;

            // !!! BE CAREFUL ABOUT THE TYPO += and =+ !!
            // It doesn't show the error when it was =+ by mistake.
            switch (bit3)
            {
                case 3:
                {
                    carry = 1;
                    c += "1";
                    break;
                }
                case 2:
                {
                    carry = 1;
                    c += "0";
                    break;
                }
                case 1:
                {
                    carry = 0;
                    c += "1";
                    break;
                }
                case 0:
                {
                    carry = 0;
                    c += "0";
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        if (rit1 != a.rend())
        {
            for ( ; rit1 != a.rend(); ++rit1)
            {
                int bit1 = *rit1 - 48;
                int bit3 = bit1 + carry;

                switch (bit3)
                {
                    case 2:
                    {
                        carry = 1;
                        c += "0";
                        break;
                    }
                    case 1:
                    {
                        carry = 0;
                        c += "1";
                        break;
                    }
                    case 0:
                    {
                        carry = 0;
                        c += "0";
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            for ( ; rit2 != b.rend(); ++rit2)
            {
                int bit2 = *rit2 - 48;
                int bit3 = bit2 + carry;

                switch (bit3)
                {
                    case 2:
                    {
                        carry = 1;
                        c += "0";
                        break;
                    }
                    case 1:
                    {
                        carry = 0;
                        c += "1";
                        break;
                    }
                    case 0:
                    {
                        carry = 0;
                        c += "0";
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }

        if (carry != 0)
        {
            c += "1";
        }

        reverse(c.begin(), c.end());
        return c;
    }
};

int main()
{
    Solution sln;
    string a, b;
    cout << "Please enter a: ";
    cin >> a;
    cout << "Please enter b: ";
    cin >> b;
    cout << sln.addBinary(a, b) << endl;
    return 0;
}
