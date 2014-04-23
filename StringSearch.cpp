#include <iostream>
#include "NormalData.h"
#include "RandomData.h"

using namespace std;

const int BYTESIZE = 256;

//const int PATTERNLENGTH = 8;

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
        skip[(unsigned char)*pattern++] = patternLength--;
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

// Boyer-Moore algorithm
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

// Whenever there is an unmatch, make a jump depending on the the character after
// current end position of the source string.
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

// Knuth-Morris-Pratt algorithm
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

/*
 *  lev(|a|, |b|) = lev(i, j)
 *
 *  if min(i, j) = 0; = max(i, j);
 *
 *  oterwise; min( lev(i-1, j) + 1, lev(i, j-1) + 1, lev(i-1, j-1) ) + cost; 
 *             cost = 1 if a[i] != b[j]; cost = 0 if a[i] == b[j]
 *
 *  lev(i-1, j) delete from s to t
 *  lev(i, j-1) insert
 *  lev(i-1, j-1) + cost; if cost == 0, the last charactor matches; otherwise, replace it with cost 1
 */
int LevensteinDistanceRecursive(string s, string t)
{
    if (s.size() == 0)
    {
        return t.size();
    }

    if (t.size() == 0)
    {
        return s.size();
    }

    int cost = 0;

    if (s.back() == t.back())
    {
        cost = 0;
    }
    else
    {
        cost =  1;
    }

    string s1 = s;
    s1.pop_back();
    string t1 = t;
    t1.pop_back();
    int distance1 = LevensteinDistanceRecursive(s1, t) + 1;
    int distance2 = LevensteinDistanceRecursive(s, t1) + 1;
    int distance3 = LevensteinDistanceRecursive(s1, t1) + cost;

    int min = distance1 < distance2 ? distance1 : distance2;
    min = min < distance3 ? min : distance3;

    return min;
}

int LevensteinDistance(string s, string t)
{
    vector< vector<int> > d;
    // The size of d is from 0 to s.size() and t.size().
    vector<int> v(t.size() + 1, 0);

    // initilze array to 0
    for (int i = 0; i <= s.size(); ++i)
    {
        d.push_back(v);
    }

    // source prefixes can be transformed into empty string ty dropping all characters
    for (int i = 1; i <= s.size(); ++i)
    {
        d[i][0] = i;
    }

    // target prefixes can be reached from empty source prefix by inserting every charactors
    for (int i = 1; i <= t.size(); ++i)
    {
        d[0][i] = i;
    }

    for (int j = 1; j <= t.size(); ++j)
    {
        for (int i = 1; i <= s.size(); ++i)
        {
            // !!Be careful!! The index starts from 1.
            if (s[i - 1] == t[j - 1])
            {
                d[i][j] = d[i - 1][j - 1];
            }
            else
            {
                int dis1 = d[i - 1][j] + 1;
                int dis2 = d[i][j - 1] + 1;
                int dis3 = d[i - 1][j - 1] + 1;
                int min = dis1 < dis2 ? dis1 : dis2;
                d[i][j] = min < dis3 ? min : dis3;
            }
        }
    }

    return d[s.size()][t.size()];
}

int LevensteinDistance2(string s, string t)
{
    if (s == t)
    {
        return 0;
    }
    else if (s.size() == 0)
    {
        return t.size();
    }
    else if (t.size() == 0)
    {
        return s.size();
    }

    vector<int> v0(t.size() + 1, 0);
    vector<int> v1(t.size() + 1, 0);

    // initialize v0 the previous row of distances
    // this row is d[0][j] edit distance for an empty s
    // the distance is just the number of characters to delete from t
    for (int i = 0; i < v0.size(); ++i)
    {
        v0[i] = i;
    }

    for (int i = 0; i <= s.size(); ++i)
    {
        // calculate v1 current row distances from the previous row v0
        //
        // first element of v1 is d[i+1][0]
        // editing distance is delete (i+1) chars from s to match empty t
        v1[0] = i + 1;


        // use formular to fill in the rest of the row
        for (int j = 0; j <= t.size(); ++j)
        {
            int cost = (s[i] == t[j]) ? 0 : 1;
            int d1 = v1[j] + 1;
            int d2 = v0[j + 1] + 1;
            int d3 = v0[j] + cost;
            int min = d1 < d2 ? d1 : d2;
            v1[j + 1] = min < d3 ? min : d3;
        }

        // copy current row to previous row for next iteration
        v0 = v1;
    }

    return v1[t.size()];
}

int main()
{
//    char S[MAXSTRLEN] = {0};
//    char pattern[] = {'D', 'W', 'F', 'C', 'A', 'Y', 'S', 'S'};
//    initializeStringArray(S, MAXSTRLEN);

//    cout << "The random source string is:" << endl;
//    printStringArray(S, MAXSTRLEN);
//    printStringArray(src, 24);
//    cout << "The pattern string is:" << endl;
//    printStringArray(pattern, PATTERNLENGTH);
//    printStringArray(des, 5);

//    int index = -1;
//    index = Horspool(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = Sunday(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = Sunday(src1, 29, des1, 9);
//    index = BMSearch(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = BMSearch(src2, 29, des2, 11);
//    index = KMPSearch(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = KMPSearch(src2, 29, des2, 11);

//    cout << "The pattern string is found at index " << index << "." << endl;

    string s("kitten");
    string t("sitting");
    cout << "The Levenstein Distance is " << LevensteinDistance2(s, t) << "." << endl;
    return 0;
}

