#include <iostream>
#include <vector>

#include "NestedInteger.h"

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;

        for (auto i: nestedList) {
            addDepth(i, 1, sum);
        }

        return sum;
    }

    void addDepth(NestedInteger& a, int depth, int &sum) {
        if (a.isInteger()) {
            sum += a.getInteger() * depth;
        }
        else {
            vector<NestedInteger> v = a.getList();

            for (auto i: v) {
                // be careful, don't use ++depth or depth++ here, because it would change depth for every pass in the for loop
                addDepth(i, depth + 1, sum);
            }
        }
    }
};

int main() {
    Solution sln;
    //vector<NestedInteger> v = {NestedInteger(vector<NestedInteger>(2, NestedInteger(1))), NestedInteger(2), NestedInteger(vector<NestedInteger>(2, NestedInteger(1)))};
    vector<NestedInteger> v1 = {NestedInteger(6)};
    vector<NestedInteger> v2 = {NestedInteger(4), v1};
    vector<NestedInteger> v = {NestedInteger(1), v2};
    printVector<NestedInteger>(v);
    cout << sln.depthSum(v) << endl;
    return 0;
}
