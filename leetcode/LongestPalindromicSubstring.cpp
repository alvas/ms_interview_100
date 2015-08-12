#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Need to improve.
    string longestPalindrome(string s) {
        int sz = s.size();
        
        if (sz <= 1)
        {
            return s;
        }

        int maxL = 0;
        int maxIdx = 0;

        for (int i = sz / 2 - 1; i >= 0; --i)
        {
            int len = 0;
            int index = i;

            for (int j = 1; i - j >= 0 && i + j < sz; ++j)
            {
                if (s[i - j] != s[i + j])
                {
                    index = i - j + 1;
                    break;
                }

                index = i - j;
                ++len;
            }

            if (2 * len + 1 > maxL)
            {
                maxL = 2 * len + 1;
                maxIdx = index;
            }
        }

        for (int i = sz / 2 - 1; i >= 0; --i)
        {
            int len = 0;
            int index = i;

            for (int j = 0; i - j >= 0 && i + j < sz; ++j)
            {
                if (s[i - j] != s[i + j + 1])
                {
                    index = i - j + 1;
                    break;
                }

                index = i - j;

                ++len;
            }

            if (2 * len > maxL)
            {
                maxL = 2 * len;
                maxIdx = index;
            }
        }

        for (int i = sz / 2; i < sz; ++i)
        {
            int len = 0;
            int index = i;

            for (int j = 1; i - j >= 0 && i + j < sz; ++j)
            {
                if (s[i - j] != s[i + j])
                {
                    index = i - j + 1;
                    break;
                }

                index = i - j;
                ++len;
            }

            if (2 * len + 1 > maxL)
            {
                maxL = 2 * len + 1;
                maxIdx = index;
            }
        }

        for (int i = sz / 2; i < sz; ++i)
        {
            int len = 0;
            int index = i;

            for (int j = 0; i - j >= 0 && i + j < sz; ++j)
            {
                if (s[i - j] != s[i + j + 1])
                {
                    index = i - j + 1;
                    break;
                }

                index = i - j;
                ++len;
            }

            if (2 * len > maxL)
            {
                maxL = 2 * len;
                maxIdx = index;
            }
        }

        string r(s, maxIdx, maxL);
        return r;
    }
};

int main()
{
    Solution sln;
    //string s("bb");
    //string s("ccc");
    string s("aaabcdefedcbazzz");
    cout << sln.longestPalindrome(s) << endl;
    return 0;
}
