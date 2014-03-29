#include <iostream>
#include "RandomArray.h"

using namespace std;

int BMSearch()
{
}

int Horspool(char S[], int length, char pattern[], int patternLength)
{
    int d[ALPHABET] = {0};

    // initialize all characters distance to the right end as the length of the pattern string
    for (int i = 0; i != ALPHABET; ++i)
    {
        d[i] = patternLength;
    }

    // set the distance of character appears in the pattern string to the distance from
    // its position to the right end
    // The distance of the last character in the pattern string is not reset.
    for (int i = 0; i != (patternLength - 1); ++i)
    {
        d[pattern[i] - 'A'] = patternLength - i - 1;
    }

    // pos is the starting matching index of the source string
    int pos = 0;

    while (pos < (length - patternLength))
    {
        int j = patternLength - 1;

        // compare the souce and pattern string
        while (j >= 0 && S[pos + j] == pattern[j])
        {
            j--;
        }

        if (j == -1)
        {
            // found
            return pos;
        }
        else
        {
            // not found, move forward and make the right most possible character in pattern
            // to match the (patternLength - 1) character from pos in the source string
            pos += d[S[pos + patternLength - 1] - 'A'];
        }
    }

    return -1;
}

int Sunday(char S[], int length, char pattern[], int patternLength)
{
    int next[ALPHABET] = {0};

    for (int i = 0; i < ALPHABET; ++i)
    {
        next[i] = patternLength + 1;
    }

    for (int i = 0; i < patternLength; ++i)
    {
        next[pattern[i] - 'A'] = patternLength - i;
    }

    int pos = 0;

    while (pos < (length - patternLength + 1))
    {
        int i = pos;
        int j = 0;

        //for (; j < patternLength; ++j, ++i)
        while (j < patternLength)
        {
            if (S[i++] != pattern[j++])
            {
                pos += next[S[pos + patternLength] - 'A'];
                break;
            }
        }

        if (j == patternLength)
        {
            return pos;
        }

    }

    return -1;
}

int main()
{
    char S[MAXSTRLEN] = {0};
    char pattern[] = {'D', 'W', 'F', 'C', 'A', 'Y', 'S', 'S'};
    initializeStringArray(S, MAXSTRLEN);

    cout << "The random source string is:" << endl;
    printStringArray(S, MAXSTRLEN);
    cout << endl;
    cout << "The pattern string is:" << endl;
    printStringArray(pattern, 8);
    cout << endl;

//    int index = Horspool(S, MAXSTRLEN, pattern, 8);
    int index = Sunday(S, MAXSTRLEN, pattern, 8);

    cout << "The pattern string is found at index " << index << "." << endl;
    return 0;
}

