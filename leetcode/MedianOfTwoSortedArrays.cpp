#include <iostream>
#include <vector>

#include "NormalData.h"
#include "RandomData.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if (m + n == 0)
        {
            return 0.0;
        }
        
        double a = findK(nums1, 0, m, nums2, 0, n, (n + m) / 2 + 1);

        if ((m + n) % 2 == 0)
        {
            double b = findK(nums1, 0, m, nums2, 0, n, (n + m) / 2);
            a = (a + b) / 2;
        }

        return a;
    }

    int findK(vector<int> &a, int s1, int m, vector<int> &b, int s2, int n, int k)
    {
        if (m <= 0)
        {
            return b[s2 + k - 1];
        }

        if (n <= 0)
        {
            return a[s1 + k - 1];
        }

        if (k <= 1)
        {
            return min(a[s1], b[s2]);
        }

        // a0, a1, a2, ..., am/2,     am/2+1, ...., am-2, am-1
        //    section 1                  section 2
        // b0, b1, b2, ..., bn/2,     bn/2+1, ...., bn-2, bn-1
        //    section 3                  section 4
        //If (m/2+n/2+1) > k && am/2 > bn/2 , drop Section 2
        //If (m/2+n/2+1) > k && am/2 < bn/2 , drop Section 4
        //If (m/2+n/2+1) < k && am/2 > bn/2 ,  drop Section 3
        //If (m/2+n/2+1) < k && am/2 < bn/2 ,  drop Section 1
        // This condition is very important
        if (b[s2 + n / 2] >= a[s1 + m / 2])
        {
            // This condition is very important
            if ((m / 2 + 1 + n / 2) >= k)
            {
                return findK(a, s1, m, b, s2, n / 2, k);
            }
            else
            {
                return findK(a, s1 + m / 2 + 1, m - (m / 2 + 1), b, s2, n, k - (m / 2 + 1));
            }
        }
        else
        {
            if ((m / 2 + 1 + n / 2) >= k)
            {
                return findK(a, s1, m / 2, b, s2, n, k);
            }
            else
            {
                return findK(a, s1, m, b, s2 + n / 2 + 1, n - (n / 2 + 1), k - (n / 2 + 1));
            }
        }
    }

    double findMedianSortedArrays_naive(vector<int>& nums1, vector<int>& nums2) {
        // If we merge it, it would be better than sorting here.
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int sz = nums1.size();

        if (sz == 0)
        {
            return 0.0;
        }
        else if (sz % 2 == 0)
        {
            double a = nums1[(sz - 1) / 2], b = nums1[sz / 2];
            return (a + b) / 2;
        }
        else
        {
            return nums1[sz / 2];
        }
    }
};

int main()
{
    Solution sln;
    //vector<int> a = {31, 53, 55};
    //vector<int> b = {1, 25, 31, 53, 55};
    //vector<int> nums1(a, a + SIZE(a)), nums2(b, b + SIZE(b));
    vector<int> nums1, nums2;
    srand(unsigned(time(0))); 
    initializeRandomVector(nums1, rand() % 10);
    initializeRandomVector(nums2, rand() % 10);
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    printVector<int>(nums1);
    printVector<int>(nums2);
    cout << sln.findMedianSortedArrays(nums1, nums2) << endl;

    // because the naive algorithm would merge the nums1 and nums2, it should not be called
    // before findMedianSortedArrays
    cout << sln.findMedianSortedArrays_naive(nums1, nums2) << endl;
    return 0;
}
