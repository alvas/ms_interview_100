#include <vector>

using namespace std;

const int LENGTH = 10;
const int MAXNUM = 40;
const int MAXSTRLEN = 300;

const int COLUMNS = 10;
const int CHARCOLUMNS = 80;

const int ALPHABET = 26;

void initializeIndexVector(vector<int> &v, const int size);

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

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }

    cout << endl;
}

template <typename T>
void printFunc(T str)
{
    cout << str << " ";
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

void initialize2DVector(vector<vector<int> > &v, int row, int column);
