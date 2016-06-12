#include <iostream>
#include <stack>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n < 3)
        {
            return 0;
        }

        vector<int> maxL(n, 0), maxR(n, 0);
        int water = 0;

        for (int i = 1; i < n; ++i)
        {
            maxL[i] = max(maxL[i - 1], height[i - 1]);
        }

        for (int i = n - 2; i >= 0; --i)
        {
            maxR[i] = max(maxR[i + 1], height[i + 1]);

            int minH = min(maxL[i], maxR[i]);

            if (minH > height[i])
            {
                water += (minH - height[i]);
            }
        }

        return water;
    }

    int trap2(vector<int>& height) {
        int n = height.size();

        if (n < 3)
        {
            return 0;
        }

        stack<int> s;
        s.push(0);
        int water = 0;

        for (int i = 1; i < n; ++i)
        {
            if (height[i] > height[s.top()])
            {
                int bottom = height[s.top()];

                s.pop();

                while (!s.empty() && height[i] >= height[s.top()])
                {
                    water += (height[s.top()] - bottom) * (i - s.top() - 1);
                    bottom = height[s.top()];
                    s.pop();
                }

                if (!s.empty())
                {
                    water += (height[i] - bottom) * (i - s.top() - 1);
                }
            }

            s.push(i);
        }

        return water;
    }

    int trap1(vector<int>& height) {
        int size = height.size();
        int amount = 0;

        if (size < 3)
        {
            return amount;
        }

        int begin = 0, end = 0;
        stack<int> s;

        // be careful about the index
        while (begin < size && end < size)
        {
            while (begin + 1 < size && height[begin] < height[begin + 1])
            {
                begin++;
            }

            if (begin + 1 == size)
            {
                break;
            }

            end = begin + 1;

            while (end < size && height[end] < height[begin])
            {
                s.push(end);
                end++;
            }

            if (end == size)
            {
                // be careful about the top value, and there are multiple small peaks inside the valley.
                int topVal = height[size - 1];

                while (!s.empty())
                {
                    int topIdx = s.top();
                    s.pop();

                    if (height[topIdx] <= topVal)
                    {
                        amount += topVal - height[topIdx];
                    }
                    else
                    {
                        topVal = height[topIdx];
                    }
                }
            }
            else
            {
                // be careful about the top value
                while (!s.empty())
                {
                    int topIdx = s.top();
                    s.pop();
                    amount += height[begin] - height[topIdx];
                }
            }

            begin = end;
        }

        return amount;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    vector<int> height;
    initializeRandomVector(height, n);
    printVector<int>(height);
    std::cout << sln.trap(height) << endl;
    return 0;
}
