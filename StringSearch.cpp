#include <iostream>
#include "RandomArray.h"

using namespace std;

const int BYTESIZE = 256;

const int PATTERNLENGTH = 8;

char src[] = "ABCDACDAAHFACABCDABCDEAA";  
char des[] = "ABCDE";
char src1[] = "ABEEADEEABCABDABEEABCABDACFEE";
char des1[] = "ABCABDACF";
char src2[] = "ABEEADEEABCABDABEEABCABCDABCFEE";
char des2[] = "ABCABCDABCF";

// WATCH OUT!! The S and pattern string must only contain capital characters.
// Otherwise, next[pattern[i] - 'A'] would overflow the stack.

void makeSkip(char pattern[], int patternLength, int skip[])
{
    // set the stride of bad character to pattern to patternLength
    // because the bad character doesn't appear in the pattern
    // we just skip over the whole patternLength characters string
    for (int i = 0; i < BYTESIZE; ++i)
    {
        skip[i] = patternLength;
    }

    // set the stride for character of pattern; if the ith
    // character is not matched, then we want to move forward
    // skip[pattern[x]] steps to let the ith character in the source to
    // aligned to the pattern[x] character in pattern
    while (patternLength != 0)
    {
        skip[*pattern++] = patternLength--;
    }
}

// array pattern and shift have the same length
void makeShift(char pattern[], int patternLength, int shift[])
{
    int *sptr = shift + patternLength - 1;
    char *pptr = pattern + patternLength - 1;

    // the last character of pattern string
    char c = pattern[patternLength - 1];
    *sptr = 1;
    pptr--;

    while (sptr-- != shift)
    {
        char *p1 = pattern + patternLength - 2, *p2 = NULL, *p3 = NULL;

        do
        {
            while (p1 >= pattern && *p1-- != c);

            p2 = pattern + patternLength - 2;
            p3 = p1;

#ifdef DEBUG
            cout << "p1 = " << *p1 << endl;
#endif

            while (p3 >= pattern && *p3-- == *p2-- && p2 >= pptr);
        } while (p3 >= pattern && p2 >= pptr);

        *sptr = shift + patternLength - sptr + p2 - p3;

#ifdef DEBUG
        cout << "shift + patternLength - sptr = " << shift + patternLength - sptr << endl;
        cout << "p2 - p3 = " << p2 - p3 << "; *p2 = " << *p2 << "; *p3 = " << *p3 << endl;
        cout << "*sptr = " << *sptr << "; *pptr = " << *pptr << endl << endl;
#endif
        pptr--;
    }
}

int BMSearch(char S[], int length, char pattern[], int patternLength)
{
    int skip[BYTESIZE] = {0};
    int shift[patternLength];
    makeSkip(pattern, patternLength, skip);
    makeShift(pattern, patternLength, shift);

#ifdef DEBUG
    printArray(shift, patternLength);
#endif

    int bIdx = patternLength;

    // If the pattern string is empty, then return the index 0.
    if (patternLength == 0)
    {
        return 0;
    }

    while (bIdx <= length)
    {
        int pIdx = patternLength, skipStride = 0, shiftStride = 0;

        while (S[--bIdx] ==  pattern[--pIdx])
        {
            if (bIdx < 0)
            {
                return -1;
            }

            if (pIdx == 0)
            {
                return bIdx;
            }
        }

        skipStride = skip[(unsigned char)S[bIdx]];
        shiftStride = shift[pIdx];
        bIdx += (skipStride > shiftStride) ? skipStride : shiftStride;
    }

    return -1;
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

        while (j < patternLength)
        {
            // PITFALL!! don't increase i++ or j++ here
            // otherwise when it breaks, the j would still advance to the next position
            // when only patternLength -1 characters matching, because of this
            // inaccurate moving, the checking after the while loop would return 
            // incorrect result
            if (S[i] != pattern[j])
            {
                pos += next[S[pos + patternLength] - 'A'];
                break;
            }

            j++;
            i++;
        }

        if (j == patternLength)
        {
            return pos;
        }

    }

    return -1;
}

void makeNext(char pattern[], int patternLength, int next[])
{
    next[0] = -1;
    int i = 0, j = -1;

    while (i < patternLength - 1)
    {
        if (-1 == j || pattern[i] == pattern[j])
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

int KMPSearch(char S[], int length, char pattern[], int patternLength)
{
    if (length < patternLength)
    {
        return -1;
    }

    int next[patternLength];
    makeNext(pattern, patternLength, next);

#ifdef DEBUG
    printArray(next, patternLength);
#endif

    int i = 0, j = 0;

    while (i < length && j < patternLength)
    {
        if (-1 == j || S[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j >= patternLength)
    {
        return i - patternLength;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char S[MAXSTRLEN] = {0};
    char pattern[] = {'D', 'W', 'F', 'C', 'A', 'Y', 'S', 'S'};
    initializeStringArray(S, MAXSTRLEN);

    cout << "The random source string is:" << endl;
    printStringArray(S, MAXSTRLEN);
//    printStringArray(src, 24);
    cout << "The pattern string is:" << endl;
    printStringArray(pattern, PATTERNLENGTH);
//    printStringArray(des, 5);

    int index = -1;
//    index = Horspool(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = Sunday(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = Sunday(src1, 29, des1, 9);
    index = BMSearch(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = BMSearch(src2, 29, des2, 11);
//    index = KMPSearch(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = KMPSearch(src2, 29, des2, 11);

    cout << "The pattern string is found at index " << index << "." << endl;
    return 0;
}

