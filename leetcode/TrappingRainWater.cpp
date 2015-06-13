#include <iostream>
#include <stack>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
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
    cout << "Please enter n: ";
    cin >> n;
    vector<int> height;
    initializeRandomVector(height, n);
    printVector<int>(height);
    cout << sln.trap(height) << endl;
    return 0;
}
