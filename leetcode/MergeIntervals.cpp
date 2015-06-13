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
    vector<Interval> merge(vector<Interval>& intervals) {
    }
};

int main()
{
    Solution sln;
    Interval a[] = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    vector<Interval> intervals(a, a + SIZE(a));;
    vector<Interval> v = sln.merge(intervals);
    printVector<Interval>(v);
    return 0;
}
