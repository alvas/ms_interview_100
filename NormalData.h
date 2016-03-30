#ifndef NORMAL_DATA_HEADER_H
#define NORMAL_DATA_HEADER_H
#include <vector>

#pragma once

using namespace std;

const int LENGTH = 10;
const int MAXNUM = 80;
const int MAXSTRLEN = 300;

const int COLUMNS = 10;
const int CHARCOLUMNS = 80;

const int ALPHABET = 26;

#define SIZE(a) (unsigned int)((sizeof(a)/sizeof(a[0])))

void initializeIndexVector(vector<int> &v, const int size);

template <typename T>
void printFunc(const T &p)
{
    cout << p << "\t";
}

// Template function must be in the calling site or header file,
// otherwise it would not compile.
// T must be a container type.
// Avoid to use the keyword class to define template variable name
// here; otherwise will get "elaborated type refers to a typedef"
// compile error.
template<typename T>
void printVector(const vector<T> &v)
{
    int column = 0;

    for (typename vector<T>::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        cout << *itr << "\t";

        if (++column % COLUMNS == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
}

// specialization
template<typename T>
void printVector(const vector<pair<T, T> > &v)
{
    int column = 0;

    for (typename vector<pair<int, int> >::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        cout << "(" << itr->first << ", " << itr->second << ") ";

        if (++column % COLUMNS == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
}

template <typename T>
void print2DVector(const vector<vector<T> > &v)
{
    for (typename vector<vector<T> >::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        for_each((*itr).begin(), (*itr).end(), printFunc<T>);
        cout << endl;
    }
}

// Don't put the definition of this function in header file.
// Otherwise, it would cause duplicate symbol link error.
// Or define this function as inline
//inline void printString(const string &str)
void printString(const string &str);

template <typename T>
void print2DVector2(const vector<vector<T> > &v)
{
    for (typename vector<vector<T> >::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        for_each((*itr).begin(), (*itr).end(), printString);
        cout << endl;
    }

    cout << endl;
}

void initialize2DVector(vector<vector<int> > &v, int row, int column);

// Template to calculate factorial of n, n!
template <unsigned int n>
struct factorial {
  enum { value = n * factorial<n - 1>::value };  
};

template <>
struct factorial<0> {
    enum { value = 1 };
};

#endif
