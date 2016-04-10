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

// After skip or shift, the new i would point to one character after
// the end of the pattern, so skip[0] = 10 means the original i would
// move 10 steps and pattern[0] would be moved to the pattern[9] place
// and restart by --i
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
//                          pptr(point to unmatch), i
//                           |
//                           v
// text    :  O  O  O  O  O  X  D  A  B  D
// pattern :  F  D  A  B  D  C  D  A  B  D 
// shift   : 15 14 13 12 11 10  9  8  5  1
//            ^              ^
//            |              |
//           p3             p2, j
//
//                       original i   >> move 10 steps >>  i restart here
//                           | shift+m-sptr |    p2 - p3   |
//                           |              |              |
//                           v              |              v                        
// text    :  O  O  O  O  O  X  D  A  B  D  O  O  O  O  O  O
// pattern :                 F  D  A  B  D  C  D  A  B  D  Z
//                                                         ^
//                                                         |
//                                                  j restart here
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
            //cout << "old *p1[" << p1 - P << "]: " << *p1 << "\t";

            while (p1 > P && *--p1 != c);

            p3 = p1;

            //cout << "new *p1[" << p1 - P << "]: " << *p1 << "\t" << endl;

            p2 = P + m - 1;

            while (p3 > P && p2 > pptr && *--p3 == *--p2);

            //cout << "p2[" << p2 - P << "]: " << *p2 << "\t";
            //cout << "p3[" << p3 - P << "]: " << *p3 << "\t";
            //cout << "p2[" << p2 - P <<  "] " << *p2 << " - ";
            //cout << "pptr[" << pptr - P << "] " << *pptr << " : ";
            //cout << p2 - pptr << "\t" << endl;

        } while (p3 > P && p2 > pptr);

        //cout << "shift[" << sptr - shift << "]: (shift + m - sptr) " << shift + m - sptr;
        //cout << " + (p2 - p3) " << p2 - p3 << endl << endl;;

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
    cout << "skip: " << endl;
    printArray<int>(skip, BYTESIZE);
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

// The value of the d array are steps to align the right most character which equals to T[m - 1]
// to the place of P[m - 1].
// text    : O O[D]B D C D A B C
// pattern : F D A B D C D A B D
// d array : 9 3 2 1[3]4 3 2 1 X
//                     |  
//                     |---4-->|
//                             v
//                   F D A B D C D A B D
int Horspool(char T[], int n, char P[], int m)
{
    int d[BYTESIZE] = {0};

    // initialize all characters distance to the right end as the n of the P string
    for (int i = 0; i != BYTESIZE; ++i)
    {
        d[i] = m;
    }

    // set the distance of character appears in the P string to the distance from
    // its position to the right end
    // The distance of the last character in the P string is not reset.
    // Don't set the value for d[T[m - 1]], because it will be 0.
    for (int i = 0; i < m - 1; ++i)
    {
        // m - i - 1 is value of how many steps to move the character to the end of P
        d[P[i]] = m - i - 1;
    }

    cout << "d array: " << endl;
    printArray<int>(d, BYTESIZE);
    cout << "pattern: " << endl;
    printArray<char>(P, m);

    // pos is the starting matching index of the source string
    int pos = 0;

    while (pos < (n - m))
    {
        int j = m - 1;

        // compare the souce and P string
        while (j >= 0 && T[pos + j] == P[j])
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
            // not found, move forward and make the right most possible character in P
            // to match the (m - 1) character from pos in the source string
            pos += d[T[pos + m - 1]];
        }
    }

    return -1;
}

// Whenever there is an unmatch, make a jump depending on the the character after
// current end position of the source string.
// The value of next array is the distance to move the character to the place
// one behind the end of the pattern: m + 1
// index      :  0  1  2  3  4  5  6  7  8  9
// text       :  F  D  A  B  X  O  O  O  O  O [C]
// pattern    :  F  D  A  B  D  C  D  A  B  D
// next array : 10  1  3  2  1 [5] 1  3  2  1
//                              ^
//                              |
//                        i restart from here
//                        j restart from 0
//                              |
//                              v
// pattern    :  |-- 5 steps -->F  D  A  B  D  C  D  A  B  D
int Sunday(char T[], int n, char P[], int m)
{
    int next[BYTESIZE] = {0};

    for (int i = 0; i < BYTESIZE; ++i)
    {
        next[i] = m + 1;
    }

    for (int i = 0; i < m; ++i)
    {
        next[P[i]] = m - i;
    }

    cout << "next array: " << endl;
    printArray<int>(next, BYTESIZE);
    cout << "pattern: " << endl;
    printArray<char>(P, m);

    int pos = 0;

    while (pos < (n - m + 1))
    {
        int i = pos;
        int j = 0;

        while (j < m)
        {
            // PITFALL!! don't increase i++ or j++ here
            // otherwise when it breaks, the j would still advance to the next position
            // when only m -1 characters matching, because of this
            // inaccurate moving, the checking after the while loop would return 
            // incorrect result
            if (T[i] != P[j])
            {
                pos += next[T[pos + m]];
                break;
            }

            j++;
            i++;
        }

        if (j == m)
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

// index  : 0  1  2  3  4  5
// text   : A  B  D  A  B  X 
// pattern: A  B  D  A  B  C
// pi[q]  : 0  0  0  0  1  2
//
// align paitern[pi[q]] to the current index q 
//                    i continues from here
//                         |
//                         v
// index  : 0  1  2  3  4  5
// text   : A  B  D  A  B [D]
//                +--------|
//                         V
// pattern:          A  B [D] A  B  C
// pi[x]  :          0  1 [2]
//                         ^
//                         |
// q = 5; pi[q] = 2; pi[q] restart here
vector<int> COMPUTE_PREFIX_FUNCTION(const string &P)
{
    int m = P.size();
    vector<int> pi(m, 0);

    int j = 0;

    // pi[] is when the current position doesn't match,
    // what should be the next nearest position we should
    // start to match the current position.
    for (int i = 1; i < m; ++i)
    {
        pi[i] = j;
        
        while (j > 0 && P[j] != P[i])
        {
            j = pi[j];
        }

        if (P[j] == P[i])
        {
            j++;
        }
    }

    return pi;
}

int KMP_MATCHER(const string &T, const string &P)
{
    int n = T.size(), m = P.size();
    vector<int> &&pi = COMPUTE_PREFIX_FUNCTION(P);

    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && P[j] != T[i])
        {
            j = pi[j];
        }

        if (P[j] == T[i])
        {
            j++;
        }

        if (j == m)
        {
            // find all occurence
            //cout << "Pattern occurs at index " << i - m + 1 << "\t"; 
            //j = pi[j - 1];

            return i - m + 1;
        }
    }

    return -1;
}

int RABIN_KARP_MATCHER(const string &T, const string &P, int d, int q)
{
    int n = T.size();
    int m = P.size();

    int h = 1;

    for (int i = 0; i < m - 1; ++i)
    {
        h = (d * h) % q;
    }

    int p = 0, t = 0;

    for (int i = 0; i < m; ++i)
    {
        // Computing hash value.
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) %q;
    }

    cout << "p = " << p << endl;

    for (int i = 0; i < n - m; ++i)
    {
        cout << "t[" << i << "] = " << t << endl;

        if (p == t)
        {
            bool matched = true;

            for (int j = 0; j < m; ++j)
            {
                if (P[j] != T[i + j])
                {
                    matched = false;
                    break;
                }
            }

            if (matched)
            {
                return i;
            }
        }

        if (i < n - m)
        {
            // This is the hash function.
            t = (d * (t - T[i] * h) + T[i + m]) % q;

            // make sure the hash is positive value
            if (t < 0)
            {
                t = t + q;
            }
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
int LevensteinDistanceRecursive(const string &s, const string &t)
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

    int cost = 0;

    if (s.back() != t.back())
    {
        cost = 1;
    }

    string s1 = s;
    s1.pop_back();
    string t1 = t;
    t1.pop_back();
    int distance1 = LevensteinDistanceRecursive(s1, t) + 1;
    int distance2 = LevensteinDistanceRecursive(s, t1) + 1;
    int distance3 = LevensteinDistanceRecursive(s1, t1) + cost;

    return  min(distance1, min(distance2, distance3));
}

int LevensteinDistance(string s, string t)
{
    // The size of d is from 0 to s.size() and t.size().
    vector< vector<int> > d(s.size() + 1, vector<int>(t.size() + 1, 0));;

    // source prefixes can be transformed into empty string ty dropping all characters
    for (int i = 1; i <= s.size(); ++i)
    {
        d[i][0] = i;
    }

    // target prefixes can be reached from empty source prefix by inserting every characters
    for (int i = 1; i <= t.size(); ++i)
    {
        d[0][i] = i;
    }

    // After dropping source/target to empty string, we can insert characters to create target/source
    // the cost is s.size() + t.size().

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
                d[i][j] = min(dis1, min(dis2, dis3));
            }
        }
    }

    return d[s.size()][t.size()];
}

// using two rows to implement Levenstein Distance
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

    vector<vector<int> > v(2, vector<int>(t.size() + 1, 0));
    int row = 0;

    // initialize v0 the previous row of distances
    // this row is d[0][j] edit distance for an empty s
    // the distance is just the number of characters to delete from t
    for (int i = 0; i < v[row].size(); ++i)
    {
        v[row][i] = i;
    }

    row = (row + 1) % 2;

    for (int i = 0; i <= s.size(); ++i)
    {
        // calculate v1 current row distances from the previous row v0
        //
        // first element of v1 is d[i+1][0]
        // editing distance is delete (i+1) chars from s to match empty t
        v[row][0] = i + 1;


        // use formular to fill in the rest of the row
        for (int j = 0; j <= t.size(); ++j)
        {
            int cost = (s[i] == t[j]) ? 0 : 1;
            int d1 = v[row][j] + 1;
            int d2 = v[(row + 1) % 2][j + 1] + 1;
            int d3 = v[(row + 1) % 2][j] + cost;
            v[row][j + 1] = min(d1, min(d2, d3));
        }

        // switch current row and previous row for next iteration
        row = (row + 1) % 2;
    }

    return v[(row + 1) % 2][t.size()];
}

pair<vector<vector<int> >, vector<vector<int> > > LCS_LENGTH(const string &X, const string &Y)
{
    vector<vector<int> > b(X.size() + 1, vector<int>(Y.size() + 1, 0));
    vector<vector<int> > c(X.size() + 1, vector<int>(Y.size() + 1, 0));

    for (int i = 1; i <= X.size(); ++i)
    {
        for (int j = 1; j <= Y.size(); ++j)
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

void LCS(const vector< vector<int> > &b, const string &X, int i, int j)
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

    //int index = -1;
    //index = Horspool(src2, TEXTLENGTH, des2, PATTERNLENGTH);
//    index = Sunday(S, MAXSTRLEN, pattern, PATTERNLENGTH);
    //index = Sunday(src2, TEXTLENGTH, des2, PATTERNLENGTH);
    //index = BMSearch(S, TEXTLENGTH, pattern, PATTERNLENGTH);
    //index = BMSearch(src2, TEXTLENGTH, des2, PATTERNLENGTH);
//    index = BMSearch(src2, 29, des2, 11);
    //index = KMPSearch(S, MAXSTRLEN, pattern, PATTERNLENGTH);
    //index = KMPSearch(src2, 34, des2, 6);
    //vector<char> src2V(src2, src2 + 34);
    //vector<char> des2V(des2, des2 + 8);
    //vector<char> src3V(src3, src3 + 15);
    //vector<char> des3V(des3, des3 + 7);
    //index = KMP_MATCHER(src3V, des3V);
    //string ss(src2, src2 + TEXTLENGTH), ds(des2, des2 + PATTERNLENGTH);
    //index = RABIN_KARP_MATCHER(ss, ds, 10, 33); 

    //cout << "The pattern string is found at index " << index << "." << endl;

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

    //string s("aaba");
    string p("ababa");
    string t("ddtafwetababacfadijgaabababiojfiuaet");
    vector<int> &&pi = COMPUTE_PREFIX_FUNCTION(p);
    printVector<int>(pi);
    std::cout << KMP_MATCHER(t, p) << std::endl;
    return 0;
}

