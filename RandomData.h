#include <vector>

using namespace std;

const int LENGTH = 100;
const int MAXNUM = 5000;
const int MAXSTRLEN = 300;

const int COLUMNS = 5;
const int CHARCOLUMNS = 80;

const int ALPHABET = 26;

// I: length the size of the array
void initializeArray(int A[], int length);
void initializeVector(vector<int> &v, int length);
void initializeStringArray(char S[], int length);
void printArray(int A[], int size);
void printArray(int A[], int p, int r);
template <class T>
void printVector(const T &v);
void printStringArray(char S[], int length);
