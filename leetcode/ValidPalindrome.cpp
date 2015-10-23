#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
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
    string s;
    std::cout << "Please enter string: ";
    getline(cin, s);
    std::cout << sln.isPalindrome(s) << endl;
    return 0;
}
