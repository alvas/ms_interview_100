#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int m = num.size();
        vector<vector<int>> res;

        for (int i = 0; i < m - 2; )
        {
            int a = num[i];

            if (a > 0)
            {
                break;
            }

            int j = i + 1, k = m - 1;

            while (j < k)
            {
                int b = num[j] + num[k];

                if (b == -a)
                {
                    // using initialization list improve performance a little bit.
                    vector<int> v = {a, num[j], num[k]};
                    //v.push_back(a);
                    //v.push_back(num[j]);
                    //v.push_back(num[k]);
                    res.push_back(v);

                    while (++j < k && num[j] == num[j - 1])
                    {
                        ;
                    }

                    while (--k > j && num[k] == num[k + 1])
                    {
                        ;
                    }
                }
                else if (b < -a)
                {
                    while (++j < k && num[j] == num[j - 1])
                    {
                        ;
                    }
                }
                else
                {
                    while (--k > j && num[k] == num[k + 1])
                    {
                        ;
                    }
                }
            }

            while (++i < m && num[i] == num[i - 1])
            {
                ;
            }
        }

        return res;
    }

    vector<vector<int> > threeSum1(vector<int> &num) {
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
    std::vector<int> num = {-1, 0, 1, 2, -1, -4};
    //std::vector<int> num = {0, 0, 0, 0};
    vector<vector<int> > v = sln.threeSum(num);
    print2DVector<int>(v);
    return 0;
}

