#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void makeNext(char *needle, int lenNeedle, int next[])
    {
        next[0] = -1;
        int i = 0, j = -1;

        while (i < lenNeedle - 1)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
    }

    // KMP
    int strStr(char *haystack, char *needle)
    {
        if (needle == NULL || *needle == '\0')
        {
            return 0;
        }
        else if (haystack == NULL || *haystack == '\0')
        {
            return -1;
        }

        int lenHaystack = strlen(haystack);
        int lenNeedle = strlen(needle);
        int next[lenNeedle];
        makeNext(needle, lenNeedle, next);

        int i = 0, j = 0;

        while (i < lenHaystack && j < lenNeedle)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }

        if (j >= lenNeedle)
        {
            return i - lenNeedle;
        }
        else
        {
            return -1;
        }
    }

    int strStr_forloop(char *haystack, char *needle)
    {
        if (needle == NULL || *needle == '\0')
        {
            return 0;
        }
        else if (haystack == NULL || *haystack == '\0')
        {
            return -1;
        }

        int lenHayStack = strlen(haystack);
        int lenNeedle = strlen(needle);

        for (int i = 0; i < lenHayStack; ++i)
        {
            int j = 0;

            for ( ; j < lenNeedle; ++j)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }

            if (j >= lenNeedle)
            {
                return i;
            }
        }

        return -1;
    }

    // This implementation runs out of time.
    int strStr_bruteforce(char *haystack, char *needle) {
        if (needle == NULL || *needle == '\0')
        {
            return 0;
        }
        else if (haystack == NULL || *haystack == '\0')
        {
            return -1;
        }

        char *p1Adv = haystack;
        char *p2 = needle;

        // don't forget to advance p2!!
        // don't forget to check the end of p1Adv
        // Be very careful about the advance of p2, it need to be ++p2,
        // otherwise, p1Adv would be moved unnecessary.
        while (*++p2 != '\0' && *p1Adv++ != '\0')
        {
            ;
        }

        if (*p2 != '\0' && *p1Adv == '\0')
        {
            return -1;
        }
        else if (*p2 == '\0' && *p1Adv == '\0')
        {
            p1Adv = haystack;
        }

        char *p1 = haystack;

        while (*p1Adv != '\0')
        {
            char *str = p1;
            char *sub = needle;

            while (*sub != '\0' && *str != '\0' && *str == *sub)
            {
                str++;
                sub++;
            }

            if (*sub == '\0')
            {
                return p1 - haystack;
            }

            p1Adv++;
            p1++;
        }

        return -1;
    }
};

int main()
{
    Solution sln;
    char h[1000], n[1000];
    cout << "Please enter haystack: ";
    //cin.getline(h, 256);
    cin >> h;
    cout << "Please enter needle: ";
    //cin.getline(n, 256);
    cin >> n;
    cout << sln.strStr(h, n) << endl;;
    return 0;
}

