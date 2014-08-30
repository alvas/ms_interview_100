#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int N = 3;
int a[][2] = {{1, 5}, {10, 15}, {20, 27}};

vector<pair<int, int> > getInterval(const vector<pair<int, int> > &a, const pair<int, int> &b)
{
    int numPair = a.size();
    int s = 0, e = numPair;

    for (int i = 0, j = 1; j < numPair; ++i, ++j)
    {
        pair<int, int> v1 = a[i];
        pair<int, int> v2 = a[j];

        if (b.first <= v1.second)
        {
            s = i;
            break;
        }
        else if ((v1.second <= b.first && b.first < v2.first) || b.first <= v2.first)
        {
            s = j;
            break;
        }
    }

    for (int i = s, j = s + 1; j < numPair; ++i, ++j)
    {
        pair<int, int> v1 = a[i];
        pair<int, int> v2 = a[j];

        if (b.second < v2.first)
        {
            e = i;
            break;
        }
        else if (b.second < v2.second)
        {
            e = j;
            break;
        }
    }

    vector<pair<int, int> > r;

    for (int i = 0; i < numPair && i < s; ++i)
    {
        r.push_back(a[i]);
    }

    // Here we insert the overlaping interval.
    pair<int, int> interval;

    if (a[s].first <= b.first)
    {
        interval.first = a[s].first;
    }
    else
    {
        interval.first = b.first;
    }

    if (a[e].second < b.second)
    {
        interval.second = b.second;
    }
    else
    {
        interval.second = a[e].second;
    }

    r.push_back(interval);

    for (int i = e + 1; i < numPair; ++i)
    {
        r.push_back(a[i]);
    }

    return r;
}

static void printInterval(const vector<pair<int, int> > &r)
{
    for (vector<pair<int, int> >::const_iterator itr = r.begin(); itr != r.end(); ++itr)
    {
        cout << "{" << (*itr).first << ", " << (*itr).second << "}\n";
    }

    cout << endl;
}

vector<pair<int, int> > buildData(const int s[][2], const int size)
{
    vector<pair<int, int> > data;

    for (int i = 0; i < size; ++i)
    {
        pair<int, int> d(s[i][0], s[i][1]);
        data.push_back(d);
    }

    return data;
}

#ifndef EXPORTED
int main()
{
    vector<pair<int, int> > data = buildData(a, N);
    pair<int, int> b(12, 25);
    vector<pair<int, int> > result =  getInterval(data, b); 
    printInterval(result);
}
#endif
