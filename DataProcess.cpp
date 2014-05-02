#include <algorithm>
#include <iostream>

#include "NormalData.h"

using namespace std;

void LongestMultiple(double *a, int n)
{
    double *Min = new double[n + 1];
    double *Max = new double[n + 1];

    Min[0] = a[0];
    Max[0] = a[0];
    double maxVal = Max[0];

    for (int i = 1; i < n; ++i)
    {
        Max[i] = max(max(Max[i - 1] * a[i], Min[i - 1] * a[i]), a[i]);
        Min[i] = min(min(Max[i - 1] * a[i], Min[i - 1] * a[i]), a[i]);

        if (maxVal < Max[i])
        {
            maxVal = Max[i];
        }
    }

    cout << endl << maxVal << endl;

#ifdef DEBUG
    cout << "Max: ";
    for_each(Max, Max + n, printFunc<double>);
    cout << endl;
    cout << "Min: ";
    for_each(Min, Min + n, printFunc<double>);
    cout << endl;
#endif

    delete [] Max;
    delete [] Min;
}

vector<int> spiralOrder(const vector<vector<int> > &m)
{
    vector<int> result;

    if (m.empty())
    {
        return result;
    }

    // !!pitfall!! don't use size_t as the type here, otherwise
    // the index would overflow in the for loop when it decreases
    // below 0. negative value would be treated as a very big
    // unsigned integer. i >= beginX would not stop when i changes
    // from 0 to -1.
    int beginX = 0, endX = m[0].size();
    int beginY = 0, endY = m.size();

    while (true)
    {
        for (int i = beginX; i < endX; ++i)
        {
            result.push_back(m[beginY][i]);
        }

        if (++beginY > endY)
        {
            break;
        }

        for (int i = beginY; i < endY; ++i)
        {
            // !!be carefull!! the end index should be endX - 1
            result.push_back(m[i][endX - 1]);
        }

        if (beginX > --endX)
        {
            break;
        }

        for (int i = endX - 1; i >= beginX; --i)
        {
            result.push_back(m[endY - 1][i]);
        }

        if (beginY > --endY)
        {
            break;
        }

        for (int i = endY - 1; i >= beginY; --i)
        {
            result.push_back(m[i][beginX]);
        }

        if (++beginX > endX)
        {
            break;
        }
    }

    return result;
}

#ifndef EXPORTED
int main()
{
//    double d[7] = {-2.5, 4, 0, 3, 0.5, 8, -1};
//    for_each(d, d + 7, printFunc<double>);
//    LongestMultiple(d, 7);
    vector<vector<int> > v;
    initialize2DVector(v, 4, 8);
    print2DVector(v);
    vector<int> r = spiralOrder(v);
    for_each(r.begin(), r.end(), printFunc<int>);
    cout << endl;
    return 0;
}
#endif
