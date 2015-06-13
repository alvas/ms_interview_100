#include "NormalData.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

template<>
void printVector<Interval>(const vector<Interval> &v)
{
    int column = 0;

    for (vector<Interval>::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        cout << "(" << itr->start << ", " << itr->end<< ") ";

        if (++column % COLUMNS == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
}
