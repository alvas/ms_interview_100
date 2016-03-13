#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // use O(n^2) time and space time complexity
    //
    // expand around center
    string longestPalindrome(string s) {
        int sz = s.size(), maxLen = 0, b = 0;

        for (int i = 0; i < sz; ++i)
        {
            int k = -1, len = 0;

            for (int j = 0; j <= i; ++j)
            {
                if ((i + j < sz) && s[i - j] == s[i + j])
                {
                    k = j;

                    //int len = 2 * j + 1;
                    
                    //if (len > maxLen)
                    //{
                        //b = i - j;
                        //maxLen = len;
                    //}
                }
                else
                {
                    break;
                }
            }

            len = 2 * k + 1;

            if (len > maxLen)
            {
                b = i - k;
                maxLen = len;
            }

            k = -1;

            for (int j = 0; j <= i; ++j)
            {
                if ((i + j + 1) < sz && s[i - j] == s[i + j + 1])
                {
                    k = j;

                    //int len = 2 * j + 2;
                    
                    //if (len > maxLen)
                    //{
                        //b = i - j;
                        //maxLen = len;
                    //}
                }
                else
                {
                    break;
                }
            }

            len = 2 * k + 2;

            if (len > maxLen)
            {
                b = i - k;
                maxLen = len;
            }
        }

        return s.substr(b, maxLen);
    }

    //
    // Need to improve.
    string longestPalindrome1(string s) {
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

        std::string r(s, maxIdx, maxL);
        return r;
    }
};

int main()
{
    Solution sln;
    //string s("bb");
    //string s("ccc");
    std::string s("aaabcdefedcbazzz");
    std::cout << sln.longestPalindrome(s) << std::endl;
    return 0;
}
