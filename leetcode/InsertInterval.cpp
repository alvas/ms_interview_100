#include <iostream>
#include <vector>

#include "Interval.h"

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int sz = intervals.size();
        vector<Interval> v;

        if (sz == 0)
        {
            v.push_back(newInterval);
            return v;
        }

        // This is very important in performance improvement. It reduces time from 608ms to 508ms.
        v.reserve(sz + 1);

        for (int i = 0; i < sz; ++i)
        {
            if (intervals[i].end < newInterval.start)
            {
                v.push_back(intervals[i]);
            }
            else if (intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end)
            {
                newInterval.start = intervals[i].start;
            }
            
            if (newInterval.end < intervals[i].start)
            {
                v.push_back(newInterval);
                
                // Be careful here. After we insert  newInterval, need to change it to intervals[i], so intervals[i] would be inserted in the next round.
                newInterval = intervals[i];
            }
            else if (intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end)
            {
                newInterval.end = intervals[i].end;
            }

            // Be very careful about the last element case. Need ton insert it to the vector, otherwise there may be no chance to insert it.
            if (i == sz - 1)
            {
                v.push_back(newInterval);
            }
        }

        return v;
    }
};

int main()
{
    Solution sln;
    //Interval a[] = {Interval(1, 3), Interval(6, 9)};
    Interval a[] = {Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)};
    vector<Interval> intervals(a, a + SIZE(a));;
    //vector<Interval> intervals;
    //srand(unsigned(time(0)));
    //int k = rand() % 5;

    //for (int i = 0; i < k; ++i)
    //{
        //int a = rand() % 15;
        //int b = rand() % 15;
        //Interval c(min(a, b), max(a, b));
        //std::cout << "c.start: " << c.start << ", c.end: " << c.end << "\t";
        //intervals.push_back(c);
    //}

    //std::cout << endl;

    //Interval b(2, 5);
    Interval b(4, 9);
    vector<Interval> v = sln.insert(intervals, b);
    int sz = v.size();

    for (int i = 0; i < sz; ++i)
    {
        std::cout << "(" << v[i].start << ", " << v[i].end << ")" << "\t";
    }

    std::cout << endl;
    
    return 0;
}
