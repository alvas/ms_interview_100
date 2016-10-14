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
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        
    }
    
    vector<Interval> getIntervals() {
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
int main() {
    SummaryRanges obj;
    vector<int> nums = {1, 3, 7, 2, 6};

    for (auto val: nums) {
        obj.addNum(val);
    }

    vector<Interval> param_2 = obj.getIntervals();
    printVector<Interval>(param_2);
    return 0;
}
