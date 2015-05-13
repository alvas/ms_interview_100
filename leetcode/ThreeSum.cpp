#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

const int LOCALLENGTH = 6;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int size = num.size();

        for (int i = 0; i < size; )
        {
            int target = -num[i];

            // don't need to find triples which contain previous elements
            int start = i + 1, end = size - 1;

            while (start < end)
            {
                int sum = num[start] + num[end];

                if (sum == target)
                {
                    vector<int> v;
                    v.push_back(num[start]);
                    v.push_back(num[end]);
                    v.push_back(-target);
                    sort(v.begin(), v.end());
                    result.push_back(v);

                    // the same target, there would be different combinations of start and end.
                    start++;

                    // skip duplicate num[start]
                    while (num[start] == num[start - 1])
                    {
                        start++;
                    }
                }
                else if (sum < target)
                {
                    start++;

                    // skip duplicate num[start]
                    while (num[start] == num[start - 1])
                    {
                        start++;
                    }
                }
                else
                {
                    end--;

                    // skip duplicate num[end]
                    while (num[end] == num[end + 1])
                    {
                        end--;
                    }
                }
            }

            i++;

            // skip the duplicate target
            while (num[i] == num[i - 1])
            {
                i++;
            }
        }

        return result;
    }
};

int main()
{
    Solution sln;
    //int a[LOCALLENGTH] = {-1, 0, 1, 2, -1, -4};
    int a[LOCALLENGTH] = {0, 0, 0, 0};
    vector<int> num(a, a + LOCALLENGTH);
    vector<vector<int> > v = sln.threeSum(num);
    print2DVector<int>(v);
    return 0;
}

