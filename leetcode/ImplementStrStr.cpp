#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle)
    {
    }

    // This implementation runs out of time.
    int strStr_basic(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL ||
            *haystack == '\0' || *needle == '\0')
        {
            return -1;
        }

        char *start = haystack;
        char *sub = NULL;

        while (*start != '\0')
        {
            char *str = start;
            sub = needle;

            while (*sub != '\0' && *str != '\0' && *str == *sub)
            {
                str++;
                sub++;
            }

            if (*sub == '\0')
            {
                break;
            }

            start++;
        }

        if (sub != NULL && *sub == '\0')
        {
            return start - haystack;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution sln;
    char h[256], n[128];
    cout << "Please enter haystack: ";
    cin >> h;
    cout << "Please enter needle: ";
    cin >> n;
    cout << sln.strStr(h, n) << endl;;
    return 0;
}

