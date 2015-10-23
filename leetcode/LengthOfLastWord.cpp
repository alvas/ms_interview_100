#include <cstdio>
#include <iostream>

using namespace std;

const int LENGTH = 256;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;

        if (s == 0 || *s == '\0')
        {
            return len;
        }

        int index = strlen(s) - 1;

        while (index >= 0)
        {
            if ((s[index] >= 41 && s[index] <= 90) ||
                (s[index] >= 61 && s[index] <=122))
            {
                len++;
                index--;
            }
            // The string could be "a ".
            else if (len == 0 && s[index] == 32)
            {
                index--;
            }
            else
            {
                break;
            }
        }

        return len;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    char s[LENGTH];
    gets(s);
    std::cout << "The length of last word is: " << sln.lengthOfLastWord(s) << endl;
    return 0;
}

