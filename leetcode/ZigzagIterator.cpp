#include <iostream>
#include <queue>
#include <vector>

#include "NormalData.h"

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        //int num2 = min(v1.size(), v2.size());

        //for (int i = 0; i < num2; ++i) {
            //v.push_back(v1[i]);
            //v.push_back(v2[i]);
        //}

        //if (v1.size() > v2.size()) {
            //v.insert(v.end(), v1.begin() + num2, v1.end());
        //}
        //else {
            //v.insert(v.end(), v2.begin() + num2, v2.end());
        //}

        //itr = v.begin();
        if (!v1.empty()) {
            q.push({v1.begin(), v1.end()});
        }

        if (!v2.empty()) {
            q.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        //return *(itr++);
        auto itr1 = q.front().first;
        auto itr2 = q.front().second;
        int value = *itr1;
        q.pop();

        // remember to ++ first
        if (++itr1 != itr2) {
            q.push({itr1, itr2});
        }

        return value;
    }

    bool hasNext() {
        //return itr != v.end();
        return !q.empty();
    }

private:
    //vector<int> v;
    //vector<int>::iterator itr;
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4, 5, 6};
    ZigzagIterator i(v1, v2);

    while (i.hasNext()) {
        cout << i.next();
    }

    return 0;
}
