#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        return findMedian(nums1, 0, sz1, nums2, 0, sz2);
    }

    double findMedian(vector<int> &nums1, int s1, int e1, vector<int> &nums2, int s2, int e2)
    {
        double median = 0.0;
        int sz1 = e1 - s1, sz2 = e2 - s2, sz3 = s1 + s2;

        bool odd1 = sz1 & 1, odd2 = sz2 & 1, odd3 = sz3 & 1;
        cout << s1 << "\t" << e1 << "\t" << s2 << "\t" << e2 << endl;

        if (sz1 != 0 && sz2 == 0)
        {
            if (odd1)
            {
                int idx = sz1 / 2 + s1;
                median = nums1[idx];
            }
            else
            {
                int idx2 = sz1 / 2 + s1, idx = idx2 - 1 + s1;
                median = (nums1[idx] + nums1[idx2]) / 2;
            }
        }
        else if (sz1 == 0 && sz2 != 0)
        {
            if (odd2)
            {
                int idx = sz2 / 2 + s2;
                median = nums2[idx];
            }
            else
            {
                int idx2 = sz2 / 2 + s2, idx = idx2 - 1 + s2;
                median = (nums2[idx] + nums2[idx2]) / 2;
            }
        }
        else if (sz1 != 0 && sz2 != 0)
        {
            if (nums1[s1] > nums2[e2 - 1])
            {
                if (odd3)
                {
                    int idx = sz3 / 2 + s2;

                    if (idx < s2 + sz2)
                    {
                        median = nums2[idx];
                    }
                    else
                    {
                        idx -= sz2 + s1;
                        median = nums1[idx];
                    }
                }
                else
                {
                    int idx2 = sz3 / 2 + s2, idx = idx2 - 1 + s2;

                    if (idx2 < sz2 + s2)
                    {
                        median = (nums2[idx] + nums2[idx2]) / 2;
                    }
                    else if (idx2 == sz2 + s2)
                    {
                        median = (nums2[idx] + nums1[s1]) / 2;
                    }
                    else
                    {
                        idx -= sz2;
                        idx2 -= sz2;
                        median = (nums1[idx] + nums1[idx2]) / 2;
                    }
                }
            }
            else if (nums2[s2] > nums1[sz1 - 1])
            {
                if (odd3)
                {
                    int idx = sz3 / 2 + s1;

                    if (idx < sz1 + s1)
                    {
                        median = nums2[idx];
                    }
                    else
                    {
                        idx -= sz2;
                        median = nums1[idx];
                    }
                }
                else
                {
                    int idx2 = sz3 / 2 + s1, idx = idx2 - 1 + s1;

                    if (idx2 < sz1 + s1)
                    {
                        median = (nums1[idx] + nums1[idx2]) / 2;
                    }
                    else if (idx2 == sz1 + s1)
                    {
                        median = (nums1[idx] + nums2[s2]) / 2;
                    }
                    else
                    {
                        idx -= sz2;
                        idx2 -= sz2;
                        median = (nums2[idx] + nums2[idx2]) / 2;
                    }
                }
            }
            else
            {
                int idx = sz1 / 2 + s1, idx2 = sz2 / 2 + s1;
                int m1 = nums1[idx], m2 = nums2[idx2];

                if (m1 == m2)
                {
                    median = m1;
                }
                else if (m1 < m2)
                {
                    median = findMedian(nums1, idx, e1, nums2, s2, idx2);
                }
                else
                {
                    median = findMedian(nums1, s1, idx, nums2, idx2, e2);
                }
            }
        }

        return median;
    }
};

int main()
{
    Solution sln;
    srand(unsigned(time(0))); 
    vector<int> nums1, nums2;
    initializeRandomVector(nums1, rand() % 10);
    initializeRandomVector(nums2, rand() % 10);
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    printVector<int>(nums1);
    printVector<int>(nums2);
    cout << sln.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
