#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int left = arrays[0].front(), right = arrays[0].back(), res = 0;
        int sz = arrays.size();

        for (int i = 1; i < sz; ++i) {
            res = max(res, max(abs(arrays[i].front() - right), abs(arrays[i].back() - left)));
            left = min(left, arrays[i].front());
            right = max(right, arrays[i].back());
        }

        return res;
    }

    int maxDistance1(vector<vector<int>>& arrays) {
        int sz = arrays.size();
        int minVIdx = 0, maxVIdx = 0;

        for (int i = 0; i < sz; ++i) {
            if (arrays[i].front() < arrays[minVIdx].front()) {
                minVIdx = i;
            }

            if (arrays[i].back() > arrays[maxVIdx].back()) {
                maxVIdx = i;
            }
        }

        if (minVIdx == maxVIdx) {
            int secondMax = INT_MIN, secondMin = INT_MAX;
            int secondMaxVIdx = 0, secondMinVIdx = 0;

            for (int i = 0; i < sz; ++i) {
                if (i != maxVIdx && arrays[i].back() >= secondMax) {
                    secondMaxVIdx = i;
                    secondMax = arrays[i].back();
                }

                if (i != minVIdx&& arrays[i].front() <= secondMin) {
                    secondMinVIdx = i;
                    secondMin = arrays[i].front();
                }
            }

            int dist1 = abs(arrays[maxVIdx].back() - arrays[secondMinVIdx].front());
            int dist2 = abs(arrays[secondMaxVIdx].back() - arrays[minVIdx].front());

            if (dist1 >= dist2) {
                minVIdx = secondMinVIdx;
            }
            else {
                maxVIdx = secondMaxVIdx;
            }
        }

        return abs(arrays[maxVIdx].back() - arrays[minVIdx].front());
    }
};

int main()
{
    Solution sln;
    //vector<vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    //vector<vector<int>> arrays = {{1, 7}, {0, 10}, {3, 8}};
    //vector<vector<int>> arrays = {{1, 7}, {1, 7}};
    //vector<vector<int>> arrays = {{1}, {1}};
    vector<vector<int>> arrays = {{1}, {3}};
    cout << sln.maxDistance(arrays) << endl;
    return 0;
}
