#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int maxL = max(m, n);

        int canary = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;

        for (int i = 0; i < maxL; ++i)
        {
            int ai = i < m ? a[i] - '0' : 0;
            int bi = i < n ? b[i] - '0' : 0;
            int c = ai + bi + canary;
            res.push_back(c % 2 + '0');
            canary = c / 2;
        }

        if (canary)
        {
            res.push_back(canary + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }

    // can't use bitset here, because it would get error: 
    // non-type template argument of type 'int' is not an integral constant expression
    string addBinary1(string a, string b) {
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
    std::cout << "Please enter a: ";
    cin >> a;
    std::cout << "Please enter b: ";
    cin >> b;
    std::cout << sln.addBinary(a, b) << endl;
    return 0;
}
