#include <iostream>
#include <map>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, size = height.size();

        if (size == 0)
        {
            return max;
        }

        int leftVal = height[0], leftIdx = 0, rightVal = height[size - 1], rightIdx = size - 1;

        if (leftVal > rightVal)
        {
            max = (rightIdx - leftIdx) * rightVal;
        }
        else
        {
            max = (rightIdx - leftIdx) * leftVal;
        }

        while (leftIdx < rightIdx)
        {
            if (leftVal < rightVal)
            {
                while (leftIdx < rightIdx && height[++leftIdx] <= leftVal)
                {
                    ;
                }
            }
            else
            {
                while (leftIdx < rightIdx && height[--rightIdx] <= rightVal)
                {
                    ;
                }
            }

            if (leftIdx >= rightIdx)
            {
                break;
            }

            leftVal = height[leftIdx];
            rightVal = height[rightIdx];
            int area = 0;

            if (leftVal > rightVal)
            {
                area = (rightIdx - leftIdx) * rightVal;
            }
            else
            {
                area = (rightIdx - leftIdx) * leftVal;
            }

            if (max < area)
            {
                max = area;
            }
        }

        return max;
    }

    int maxArea_slow(vector<int>& height) {
        int max = 0, size = height.size();

        if (size == 0)
        {
            return max;
        }

        multimap<int, int> m;

        for (int i = 0; i < size; ++i)
        {
            m.insert(make_pair(height[i], i));
        }

        vector<int> h2 = height;
        sort(h2.begin(), h2.end());

        for (int i = 0; i < size; ++i)
        {
            int area = 0;
            multimap<int, int>::iterator itr = m.find(h2[i]);
            int index = itr->second;

            for (int j = index - 1; j >= 0; --j)
            {
                if (height[j] > h2[i])
                {
                    // Be careful about the index here. Not i.
                    area = h2[i] * (index - j);

                    if (max < area)
                    {
                        max = area;
                    }
                }
            }

            for (int j = index + 1; j < size; ++j)
            {
                if (height[j] > h2[i])
                {
                    // Be careful about the index here. Not i.
                    area = h2[i] * (j - index);

                    if (max < area)
                    {
                        max = area;
                    }
                }
            }

            m.erase(itr);

        }

        return max;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n: ";
    cin >> n;
    vector<int> height;
    initializeRandomVector(height, n);
    printVector<int>(height);
    cout << sln.maxArea(height) << endl;
    cout << sln.maxArea_slow(height) << endl;
    return 0;
}
