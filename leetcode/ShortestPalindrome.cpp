#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // using KMP
    string shortestPalindrome(string s) {
        int nS = s.size();

        if (nS <= 1)
        {
            return s;
        }

        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        int nT = t.size();
        vector<int> p(nT, 0);

        for (int i = 1; i < nT; ++i)
        {
            int j = p[i - 1];

            while (j > 0 && t[i] != t[j])
            {
                j = p[j - 1];
            }

            p[i] = (j += t[i] == t[j]);
        }

        printVector<int>(p);

        return r.substr(0, nS - p[nT - 1]) + s;
    }

    string shortestPalindrome_slow2(string s) {
        int n = s.size();

        if (n <= 1)
        {
            return s;
        }

        for (int i = n - 1; i >= 0; --i)
        {
            if (s[0] == s[i] && isPalindrome(s, i))
            {
                if (i == n - 1)
                {
                    return s;
                }
                else
                {
                    string c = s.substr(i + 1, n - i - 1);
                    reverse(c.begin(), c.end());
                    s = c + s;
                    break;
                }
            }
        }

        return s;
    }

    bool isPalindrome(string &s, int j)
    {
        if (j == 0)
        {
            return true;
        }

        bool isP = true;
        int i = 0;

        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                isP = false;
                break;
            }
        }

        return isP;
    }

    // time limit exceed.
    string shortestPalindrome_slow(string s) {
        int n = s.size();

        if (n <= 1)
        {
            return s;
        }

        int half = (n - 1) / 2;
        string c;

        for (int i = half; i >= 0; --i)
        {
            bool odd = true;

            for (int j = 0; j <= i; ++j)
            {
                if (s[i - j] != s[i + j])
                {
                    odd = false;
                    break;
                }
            }

            if (odd)
            {
                if (i == half)
                {
                    return s;
                }

                int len = i * 2 + 1;
                c = s.substr(len, n - len);
                // I made a very stupid mistake here. I put the break before the assignment :(
                break;
            }

            bool even = true;

            for (int j = 0; j <= i; ++j)
            {
                if (s[i - j] != s[i + j + 1])
                {
                    even = false;
                    break;
                }
            }

            if (even)
            {
                if (i == half)
                {
                    return s;
                }

                int len = (i + 1) * 2;
                c = s.substr(len, n - len);
                break;
            }
        }

        if (c.empty())
        {
            c = s.substr(1, n - 1);
        }

        reverse(c.begin(), c.end());
        s = c + s;
        
        return s;
    }
};

int main()
{
    Solution sln;
    //string s("aacecaaa");
    string s("abababc");
    //string s("a");
    //string s("ab");
    //string s("aba");
    //string s("aa");
    std::cout << sln.shortestPalindrome_slow(s) << endl;
    std::cout << sln.shortestPalindrome(s) << endl;
    return 0;
}
