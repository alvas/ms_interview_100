#include <vector>

using namespace std;

const int LENGTH = 100;
const int MAXNUM = 5000;
const int MAXSTRLEN = 300;

const int COLUMNS = 5;
const int CHARCOLUMNS = 80;

const int ALPHABET = 26;

// Template function must be in the calling site or header file,
// otherwise it would not compile.
// T must be a container type.
template<class T>
void printVector(const T &v)
{
    int column = 0;

    for (class T::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        cout << *itr << "\t";

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }

    cout << endl;
}

void initializeIndexVector(vector<int> &v, const int size);
