#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0;
        int sz1 = nums1.size(), sz2 = nums2.size();
        int num = sz1 + sz2;
        int half = num / 2;

        if (num % 2 == 0)
        {
        }
        else
        {
            if (nums1[sz1 - 1] < nums2[0])
            {
                if (sz1 < half)
                {
                    result = nums2[sz2 - half + sz1];
                }
                else
                {
                    result = nums1[half];
                }
            }
            else if (nums2[sz2 - 1] < nums1[0])
            {
                if (sz2 < half)
                {
                    result = nums1[sz1 - half + sz2];
                }
                else
                {
                    result = nums2[half];
                }
            }
            else
            {
                int i = 0;


            }
        }

        return result;
    }

    double findMedianSortedArrays_naive(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int sz = nums1.size();
        double result = 0.0;

        if (sz % 2 == 0)
        {
            result = (nums1[(sz - 1) / 2] + nums1[sz / 2]) /2;
        }
        else
        {
            result = nums1[sz / 2];
        }

        return result;
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
    cout << sln.findMedianSortedArrays_naive(nums1, nums2) << endl;
    cout << sln.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
