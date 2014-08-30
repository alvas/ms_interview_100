#include <algorithm>
#include <cstdlib>
#include <iostream>
//#include <random>
#include "NormalData.h"
#include "RandomData.h"

using namespace std;

// I: length the size of the array to be initialized
void initializeArray(int A[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        A[i] = rand() % maxNum;
    }
}

int RandomNumber()
{
    return rand() % MAXNUM;
}

void initializeRandomVector(vector<int> &v, int length)
{
#if 0
#ifdef CPP11
    default_random_engine generator();
    uniform_int_distribution<int> distribution(0, MAXNUM - 1);
#endif

    for (int i = 0; i < length; ++i)
    {
#ifdef CPP11
        v.push_back(distribution(generator));
#else
        v.push_back(rand() % MAXNUM);
#endif
    }
#endif

    srand(unsigned(time(0)));
    v.resize(length);
    generate(v.begin(), v.end(), RandomNumber);
}

void initializeRandomIndexVector(vector<int> &v, const int size)
{
    initializeIndexVector(v, size);
    random_shuffle(v.begin(), v.end());
}

void initializeRandomStringArray(char S[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        S[i] = 'A' + rand() % ALPHABET;
    }
}

void initializeRandomString(string &S, int length)
{
    S.clear();

    for (int i = 0; i < length; ++i)
    {
        S.push_back('A' + random() % ALPHABET);
    }
}

void printArray(int A[], int p, int r)
{
    int column = 0;

    for (int i = p; i <= r; ++i)
    {
        cout << A[i] << "\t";

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }

    cout << endl;
}

void printArray(int A[], int length)
{
    printArray(A, 0, length - 1);
}

void printStringArray(char S[], int length)
{
    int column = 0;

    for (int i = 0; i < length; ++i)
    {
        cout << S[i];

        if (column++ % CHARCOLUMNS == CHARCOLUMNS - 1)
        {
            cout << endl << endl;
        }
    }

    cout << endl << endl;
}

#ifndef EXPORTED
int main()
{
//    vector<int> v;
//    initializeVector(v, 20);
//    initializeRandomIndexVector(v, 20);
//    printVector(v);
    string S;
    initializeRandomString(S, 20);
    cout << S << endl;
    cout << endl;
}
#endif
