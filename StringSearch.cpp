#include <iostream>
#include "RandomData.h"

using namespace std;

const int TEXTLENGTH = 34;
const int PATTERNLENGTH = 10;
const int BYTESIZE = 256;

//const int PATTERNLENGTH = 8;

char src[] = "ABCDACDAAHFACABCDABCDEAA";  
char des[] = "ABCDE";
char src1[] = "ABEEADEEABCABDABEEABCABDACFEE";
char des1[] = "ABCABDACF";
char src2[] = "FDABDBDABDFDABDCDABDABDABDBCABDFEE";
//char des2[] = "ABCABCDABCF";
//char des2[] = "ABCABD";
char des2[] = "FDABDCDABD";
char src3[] = "bacbababaabcbab";
char des3[] = "abdabca";

// WATCH OUT!! The S and pattern string must only contain capital characters.
// Otherwise, next[pattern[i] - 'A'] would access data out of boundery.
void makeSkip(char P[], int m, int skip[])
{
    // set the stride of bad character to pattern to patternLength
    // because the bad character doesn't appear in the pattern
    // we just skip over the whole patternLength characters string
    for (int i = 0; i < BYTESIZE; ++i)
    {
        skip[i] = m;
    }

    // set the stride for character of pattern; if the ith
    // character is not matched, then we want to move forward
    // skip[pattern[x]] steps to let the ith character in the source to
    // aligned to the pattern[x] character in pattern
    while (m != 0)
    {
        skip[*P++] = m--;
    }
}

// array pattern and shift have the same length
// index   :  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
//
//                          pptr(point to unmatch); j & i
//                           |
//                           v
// text    :  O  O  O  O  O  X  D  A  B  D
// pattern :  F  D  A  B  D  C  D  A  B  D 
// shift   : 15 14 13 12 11 10  9  8  5  1
//            ^              ^
//            |              |
//           p3             p2
//
//                       original i   >> move 10 steps >>  i
//                           | shift+m-sptr |    p2 - p3   |
//                           |              |              |
//                           v              |              |                        
// text    :  O  O  O  O  O  X  D  A  B  D  |              v
// pattern :                 F  D  A  B  D  C  D  A  B  D  Z
void makeShift(char P[], int m, int shift[])
{
    char *pptr = P + m - 1;
    // pptr points to the unmatch character
    pptr--;

    int *sptr = shift + m - 1;
    *sptr = 1;

    char c = P[m - 1];

    while (sptr-- != shift)
    {
        char *p1 = P + m - 1,  *p2 = NULL, *p3 = NULL;

        do
        {
            cout << "old *p1[" << p1 - P << "]: " << *p1 << "\t";

            while (p1 > P && *--p1 != c);

            p3 = p1;

            cout << "new *p1[" << p1 - P << "]: " << *p1 << "\t" << endl;

            p2 = P + m - 1;

            while (p3 > P && p2 > pptr && *--p3 == *--p2);

            cout << "p2[" << p2 - P << "]: " << *p2 << "\t";
            cout << "p3[" << p3 - P << "]: " << *p3 << "\t";
            cout << "p2[" << p2 - P <<  "] " << *p2 << " - ";
            cout << "pptr[" << pptr - P << "] " << *pptr << " : ";
            cout << p2 - pptr << "\t" << endl;

        } while (p3 > P && p2 > pptr);

        cout << "shift[" << sptr - shift << "]: (shift + m - sptr) " << shift + m - sptr;
        cout << " + (p2 - p3) " << p2 - p3 << endl << endl;;

        // (shift + m - sptr) are steps to move the index to the end of pattern
        // then (p2 - p3) are steps to align the substring to good suffix of pattern
        *sptr = (shift + m - sptr) + (p2 - p3);
        pptr--;
    }
}

// Boyer-Moore algorithm
int BMSearch(char T[], int n, char P[], int m)
{
    // If the pattern string is empty, then return the index 0.
    if (m == 0)
    {
        return 0;
    }
    else if (n < m)
    {
        return -1;
    }

    int skip[BYTESIZE] = {0};
    int shift[PATTERNLENGTH] = {0};

    makeSkip(P, m, skip);
    makeShift(P, m, shift);

    cout << "pattern: " << endl;
    printArray<char>(P, m);
    //cout << "skip: " << endl;
    //printArray<int>(skip, BYTESIZE);
    cout << "shift: " << endl;
    printArray<int>(shift, m);

    int i = m;
    
    while (i <= n)
    {
        int j = m;

        while (j >= 0 && T[--i] ==  P[--j])
        {
            if (j == 0)
            {
                return i;
                //cout << "Found matching string at index: " << i << endl;
                //i += shift[0];
            }
        }

        i += max(skip[T[i]], shift[j]);
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

    // !!!
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

    printArray(next, patternLength);

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

// index  : 0 1 2 3 4 5
// pattern: A B D A B C
// pi[x]  : 0 0 0 0 1 2
//
// text   : A B D A B[D]
//          0 1 2 3 4[i]
//          A B D A B[C]
//
// align pattern[pi[i]] to the current index i         
// i = 5; pi[i] = 2;
// index  : 0 1 2 3 4 i
// text   : A B D A B[D]
//              +-----|
//                    V
// pi[x]  :       0 1[2]
// pattern:       A B[D] A B C
vector<int> COMPUTE_PREFIX_FUNCTION(const vector<char> &P)
{
    int m = P.size();
    vector<int> pi(m, 0);

    // !!!
    int k = 0;

    // pi[] is when the current position doesn't match,
    // what should be the next nearest position we should
    // start to match the current position.
    for (int q = 1; q < m; ++q)
    {
        // !!!
        pi[q] = k;
        
        // !!!
        while (k > 0 && P[k] != P[q])
        {
            k = pi[k];
        }

        if (P[k] == P[q])
        {
            k++;
        }
    }

    return pi;
}

int KMP_MATCHER(const vector<char> &T, const vector<char> &P)
{
    int n = T.size();
    int m = P.size();

    cout << "Text string: " << endl;
    string s1(T.begin(), T.end());
    cout << s1 << endl;
    cout << "Pattern string: " << endl;
    string s2(P.begin(), P.end());
    cout << s2 << endl;

    vector<int> pi = COMPUTE_PREFIX_FUNCTION(P);

    cout << "Prefix function: " << endl;
    printVector<int>(pi);
    cout << endl;

    // !!!
    int q = 0;

    for (int i = 0; i < n; ++i)
    {
        // !!!
        while (q > 0 && P[q] != T[i])
        {
            q = pi[q];
        }

        if (P[q] == T[i])
        {
            q++;
        }

        if (q == m)
        {
            // find all occurence
            cout << "Pattern occurs at index " << i - m + 1 << "\t"; 
            // !!!
            q = pi[q - 1];
            //return i - m + 1;
        }
    }

    return -1;
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

pair<vector< vector<int> >, vector< vector<int> > > LCS_LENGTH(string X, string Y)
{
    vector<vector<int> > c, b;
    vector<int> a(Y.size() + 1, 0);

    for (int i = 0; i < X.size() + 1; ++i)
    {
        c.push_back(a);
        b.push_back(a);
    }

    for (int i = 1; i < X.size() + 1; ++i)
    {
        for (int j = 1; j < Y.size() + 1; ++j)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = -1;
            }
        }
    }

    // Don't initialize result with c, b before we calculate the value.
    pair<vector<vector<int> >, vector<vector<int> > > result(c, b);
    return result;
}

void LCS(vector< vector<int> > b, string X, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }

    if (b[i][j] == 0)
    {
        LCS(b, X, i - 1, j - 1);
        cout << X[i - 1] << " " ;
    }
    else if (b[i][j] == 1)
    {
        LCS(b, X, i - 1, j);
    }
    else
    {
        LCS(b, X, i, j - 1);
    }
}

int main()
{
    char S[TEXTLENGTH] = {'A', 'B', 'C', 'D', 'A', 'B', 'C', 'E', 'M', 'O', 'O', 'R', 'E', 'O', 'O', 'R', 'S', 'E'};
    char pattern[PATTERNLENGTH] = {'M', 'O', 'O', 'R', 'E', 'O', 'O', 'R', 'S'};
//    initializeRandomStringArray(S, MAXSTRLEN);

//    cout << "The random source string is:" << endl;
//    printStringArray(S, MAXSTRLEN);
//    printStringArray(src, 24);
//    cout << "The pattern string is:" << endl;
//    printStringArray(pattern, PATTERNLENGTH);
//    printStringArray(des, 5);

    int index = -1;
//    index = Horspool(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = Sunday(S, MAXSTRLEN, pattern, PATTERNLENGTH);
//    index = Sunday(src1, 29, des1, 9);
    //index = BMSearch(S, TEXTLENGTH, pattern, PATTERNLENGTH);
    index = BMSearch(src2, TEXTLENGTH, des2, PATTERNLENGTH);
//    index = BMSearch(src2, 29, des2, 11);
    //index = KMPSearch(S, MAXSTRLEN, pattern, PATTERNLENGTH);
    //index = KMPSearch(src2, 34, des2, 6);
    //vector<char> src2V(src2, src2 + 34);
    //vector<char> des2V(des2, des2 + 8);
    //vector<char> src3V(src3, src3 + 15);
    //vector<char> des3V(des3, des3 + 7);
    //index = KMP_MATCHER(src3V, des3V);

    cout << "The pattern string is found at index " << index << "." << endl;

//    string s("kitten");
//    string t("sitting");
//    cout << "The Levenstein Distance is " << LevensteinDistance2(s, t) << "." << endl;
//

    //string X, Y;
    //initializeRandomString(X, 30);
    //initializeRandomString(Y, 20);
    //cout << "X: " << X << endl;
    //cout << "Y: " << Y << endl;
    //pair<vector<vector<int> >, vector<vector<int> > > result = LCS_LENGTH(X, Y);
    //cout << "The length of LCS is: " << result.first[30][20] << endl;
    //LCS(result.second, X, 30, 20);
    //cout << endl;
    return 0;
}

