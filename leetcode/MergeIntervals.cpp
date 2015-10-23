#include <algorithm>
#include <iostream>
#include <vector>

#include "Interval.h"
#include "NormalData.h"

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool myfunction(Interval a, Interval b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> v;
        int sz = intervals.size();

        if (sz == 0)
        {
            return v;
        }
        else if (sz == 1)
        {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), myfunction);
        Interval a = intervals[0];

        for (int i = 1; i < sz; ++i)
        {
            Interval b = intervals[i];

            if (a.end < b.start)
            {
                v.push_back(a);
                a = b;

                if (i == sz - 1)
                {
                    v.push_back(b);
                }
            }
            else if (a.end <= b.end)
            {
                a.end = b.end;

                if (i == sz - 1)
                {
                    v.push_back(a);
                }
            }
            else
            {
                if (i == sz - 1)
                {
                    v.push_back(a);
                }
            }
        }
        
        return v;
    }
};

int main()
{
    Solution sln;
    //Interval a[] = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    //vector<Interval> intervals(a, a + SIZE(a));;
    vector<Interval> intervals;
    srand(unsigned(time(0)));
    int k = rand() % 5;

    for (int i = 0; i < k; ++i)
    {
        int a = rand() % 15;
        int b = rand() % 15;
        Interval c(min(a, b), max(a, b));
        std::cout << "c.start: " << c.start << ", c.end: " << c.end << "\t";
        intervals.push_back(c);
    }

    std::cout << endl;

    vector<Interval> v = sln.merge(intervals);
    printVector<Interval>(v);
    return 0;
}
