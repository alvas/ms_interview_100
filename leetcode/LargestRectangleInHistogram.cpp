#include <iostream>
#include <stack>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int maxArea = 0;
        stack<int> s;

        // Need to add a dummy element at the end, so it would cause the algorithm to pop up all element in the stack. Otherwise, if it is an strict increasing order array, then no maxArea would be calculated.
        height.push_back(0);

        int sz = height.size();

        for (int i = 0; i < sz; ++i)
        {
            // Can't get top here directly because s could be empty.
            //
            if (s.empty() || height[i] > height[s.top()])
            {
                s.push(i);
            }
            else
            {
                int top = s.top();
                s.pop();

                // If two continue increasing value are pushed into the stack, then when the second value is pop from the stack, i - s.top() - 1 would be 0. And we would continue to pop the first value and calculate the area.
                maxArea = max(maxArea, height[top] * (s.empty() ? i : i - s.top() - 1));

                // Be careful to decrease i, because we would precoess height[i] again.
                i--;
            }
        }

        return maxArea;
    }

    int largestRectangleArea_prune(vector<int>& height) {
        int sz = height.size();
        int maxArea = 0;

        for (int i = 0; i < sz; ++i)
        {
            // This pruning improvement is important. Not my idea. Shame on me.
            if (i + 1 < sz && height[i] <= height[i + 1])
            {
                continue;
            }

            int minV = height[i];

            for (int j = i; j >= 0; --j)
            {
                minV = min(minV, height[j]);
                int area = minV * (i - j + 1);

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }

    int largestRectangleArea_slow(vector<int>& height) {
        int sz = height.size();
        int maxArea = 0;

        for (int i = 0; i < sz; ++i)
        {
            int area = height[i];

            for (int j = i - 1; j >= 0; --j)
            {
                if (height[j] >= height[i])
                {
                    area += height[i];
                }
                else
                {
                    break;
                }
            }

            for (int j = i + 1; j < sz; ++j)
            {
                if (height[j] >= height[i])
                {
                    area += height[i];
                }
                else
                {
                    break;
                }
            }

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    Solution sln;
    vector<int> a = {2, 1, 5, 6, 2, 3};
    vector<int> height(a, a + SIZE(a));
    initializeIndexVector(height, 20000);
    printVector<int>(height);
    cout << sln.largestRectangleArea_slow(height) << endl;
    cout << sln.largestRectangleArea_prune(height) << endl;
    cout << sln.largestRectangleArea(height) << endl;
    return 0;
}
