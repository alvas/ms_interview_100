#ifndef NESTEDINTEGER
#define NESTEDINTEGER
#include <vector>

#include "NormalData.h"

using namespace std;

//class NestedInteger {
//public:
    //// Return true if this NestedInteger holds a single integer, rather than a nested list.
    //bool isInteger() const { return l.empty(); };

    //// Return the single integer that this NestedInteger holds, if it holds a single integer
    //// The result is undefined if this NestedInteger holds a nested list
    //int getInteger() const { 
        //if (isInteger()) {
            //return num;
        //}
        //else {
            //return 0;
        //}
    //};

    //// Return the nested list that this NestedInteger holds, if it holds a nested list
    //// The result is undefined if this NestedInteger holds a single integer
    //const vector<NestedInteger> &getList() const {
        //if (!l.empty()) {
            //return l;
        //}
        //else {
            //return l;
        //}
    //};

    //NestedInteger(const vector<NestedInteger> &a): l(a) {}
    //NestedInteger(int a): num(a) { }
//private:
    //int num;
    //vector<NestedInteger> l;
//};

class NestedInteger {
    public:
    // Constructor initializes an empty nested list.
    NestedInteger() {}

    // Constructor initializes a single integer.
    NestedInteger(int value): num(value) {}

    NestedInteger(const vector<NestedInteger> &a): l(a) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return l.empty(); }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        if (isInteger()) {
            return num;
        }
        else {
            return 0;
        }
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) { 
        l.clear(); 
        num = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        num = 0;
        l.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        if (!l.empty()) {
            return l;
        }
        else {
            return l;
        }
    }
private:
    int num;
    vector<NestedInteger> l;
};

void printNestedInteger(NestedInteger& a) {
    if (a.isInteger()) {
        cout << a.getInteger();
    }
    else {
        cout << "[";
        bool firstElement = true;
        vector<NestedInteger> l = a.getList();

        for (auto i: l) {
            if (firstElement) {
                firstElement = false;
            }
            else {
                cout << ", ";
            }

            printNestedInteger(i);
        }

        cout << "]";
    }
}

template<>
void printVector<NestedInteger>(const vector<NestedInteger> &a) {
    cout << "[";
    bool firstElement = true;

    for (auto i: a) {
        if (firstElement) {
            firstElement = false;
        }
        else {
            cout << ", ";
        }

        printNestedInteger(i);
    }

    cout << "]" << endl;
}
#endif
