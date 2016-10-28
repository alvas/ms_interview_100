#include <iostream>
#include <numeric>
#include <vector>

#include "NestedInteger.h"

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int lvl = 0;

        for (auto a: nestedList) {
            lvl = max(lvl, high(a));
        }

        vector<int> v(lvl, 0);

        for (auto a: nestedList) {
            getValue(a, v, 0);
        }

        return accumulate(v.begin(), v.end(), 0);
    }

    void getValue(NestedInteger& a, vector<int>& v, int lvl) {
        if (a.isInteger()) {
            v[lvl] += (v.size() - lvl) * a.getInteger();
        }
        else {
            for (auto b: a.getList()) {
                getValue(b, v, lvl + 1);
            }
        }
    }

    int high(NestedInteger &a) {
        if (a.isInteger()) {
            return 1;
        }
        else {
            int lvl = 0;

            for (auto b: a.getList()) {
                lvl = max(lvl, high(b));
            }

            return lvl + 1;
        }
    }
};

int main() {
    Solution sln;
    //vector<NestedInteger> v = {NestedInteger(vector<NestedInteger>(2, NestedInteger(1))), NestedInteger(2), NestedInteger(vector<NestedInteger>(2, NestedInteger(1)))};
    //vector<NestedInteger> v1 = {NestedInteger(6)};
    //vector<NestedInteger> v2 = {NestedInteger(4), v1};
    //vector<NestedInteger> v = {NestedInteger(1), v2};
    //NestedInteger a(-1), b(-2);
    NestedInteger a(-2), b(-1);
    NestedInteger a1, b1;
    a1.add(a);
    b1.add(b);
    NestedInteger b2;
    b2.add(b1);
    //vector<NestedInteger> v1 = {a};
    //vector<NestedInteger> v2 = {c};
    vector<NestedInteger> v = {a1, b2};
    printVector<NestedInteger>(v);
    cout << sln.depthSumInverse (v) << endl;
    return 0;
}
