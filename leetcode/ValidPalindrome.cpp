#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        size_t m = s.size();

        // be careful, don't use size_t, otherwiae, when m is 0, m - 1 would cause overflow.
        int b = 0, e = m - 1;

        // Don't use std::tolower here, because namely confliction
        // <cctype> int tolower(int c); <locale> charT tolower()
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        while (b < e)
        {
            while (b < e && !isalnum(s[b]))
            {
                b++;
            }

            while (b < e && !isalnum(s[e]))
            {
                e--;
            }

            if (b > e || s[b] != s[e])
            {
                return false;
            }

            b++;
            e--;
        }

        return true;
    }

    bool isPalindrome1(string s) {
        int length = s.size();

        // when the string is empty, it considers as valid palindrome.

        for (int i = 0, j = length - 1; i < length && 0 <= j && i < j; ++i, --j)
        {
            while (!isalnum(s[i]) && i < length && i < j)
            {
                i++;
            }

            if (i >= j)
            {
                return true;
            }

            while (!isalnum(s[j]) && 0 <= j && i < j)
            {
                j--;
            }

            if (j <= i)
            {
                return true;
            }

            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    //string s("A man, a plan, a canal: Panama");
    string s("race a car");
    //std::cout << "Please enter string: ";
    //getline(cin, s);
    std::cout << sln.isPalindrome(s) << endl;
    std::cout << sln.isPalindrome1(s) << endl;
    return 0;
}
