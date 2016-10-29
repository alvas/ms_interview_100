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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
                if (a.start < b.start) {
                    return true;
                }
                else if (a.start > b.start) {
                    return false;
                }
                else {
                    if (a.end <= b.end) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
        });

        int sz = intervals.size();

        for (int i = 1; i < sz; ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sln;
    vector<Interval> v = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    cout << sln.canAttendMeetings(v) << endl;
    return 0;
}
