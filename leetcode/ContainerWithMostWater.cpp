#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int l = 0, r = height.size() - 1;

        while (l < r)
        {
            maxA = max(min(l, r) * (r - l), maxA);

            if (height[l] < height[r])
            {
                l++;
            }
            else if (height[l] > height[r])
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
    }

    int maxArea2(vector<int>& height) {
        int n = height.size();

        if (n <= 0)
        {
            return 0;
        }

        int l = 0, r = n - 1;
        int maxA = (n - 1) * min(height[l], height[r]);

        while (l < r)
        {
            int area = 0;

            if (height[l] < height[r])
            {
                int tmp = height[l];
                while (++l < r && height[l] <= tmp);
                area = (r - l) * min(height[l], height[r]);
            }
            else
            {
                int tmp = height[r];
                while (l < --r && height[r] <= tmp);
                area = (r - l) * min(height[r], height[l]);
            }

            maxA = max(maxA, area);

        }

        return maxA;
    }

    int maxArea_normal(vector<int>& height) {
        int ma = 0;
        int n = height.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int w = j - i;
                int area = w * min(height[i], height[j]);
                ma = max(ma, area);
            }
        }

        return ma;
    }

    int maxArea1(vector<int>& height) {
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
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 50);
    int m = distribution(generator);

    for (int i = 0; i < m; ++i)
    {
        int n = distribution(generator);
        std::vector<int> height;
        initializeRandomVector(height, n);
        std::cout << "n: " << n << std::endl;
        printVector<int>(height);

        int r1 = sln.maxArea1(height);
        std::cout << r1 << endl;

        int r2 = sln.maxArea(height);
        std::cout << r2 << endl;

        assert(r1 == r2);
        //std::cout << sln.maxArea_slow(height) << endl;
        std::cout << endl;
    }

return 0;
}
