#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Need to improve.
    string convert(string s, int nRows) {
        string zz;
        int length = s.length();

        for (int i = 0; i < nRows; ++i)
        {
            if (i < length)
            {
                zz.append(1, s[i]);
            }

            
            // !!WATCH OUT!! (length + 2 * nRows - 2) / (2 * nRows - 2) would be 0 and cause floating point exception.
            if (nRows == 1)
            {
                for (int j = 1; j < length; ++j)
                {
                    zz.append(1, s[j]);
                }
            }
            else
            {
                // how many columns 2 * (nRows - 1)
                int columns = (length + 2 * nRows - 2) / (2 * nRows - 2);

                for (int j = 1; j <= columns; ++j)
                {
                    int k = 2 * j * (nRows - 1);

                    // the first row only has one char
                    if (i == 0)
                    {
                        // may be less than nRows char in first column, be careful
                        if (k < length)
                        {
                            zz.append(1, s[k]);
                        }
                    }
                    else
                    {
                        // the last row only has one char
                        if (0 < k - i && k - i < length && i != nRows - 1)
                        {
                            zz.append(1, s[k - i]);
                        }

                        // char on the j column
                        if (k + i < length)
                        {
                            zz.append(1, s[k + i]);
                        }
                    }
                }
            }
        }

        return zz;
    }
};

int main()
{
    Solution sln;
    int r = 0;
    string z;
    cout << "Please enter string: ";
    cin >> z;
    cout << "Please enter rows: ";
    cin >> r;
    cout << sln.convert(z, r) << endl;
    return 0;
}
