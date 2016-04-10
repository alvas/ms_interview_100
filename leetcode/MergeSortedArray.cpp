#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m + n;
        copy_backward(nums1.begin(), nums1.begin() + m, nums1.end());

        // Be careful about the start index of i. It should be the length of nums2.
        int k = 0, i = n, j = 0;

        for (; i < l && j < n; ++k)
        {
            nums1[k] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }

        if (i == l)
        {
            nums1.insert(nums1.begin() + k, nums2.begin() + j, nums2.end());
        }
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // be careful about the insert position, NOT nums1.end(), because there are trailing 0
        // it is nums1.begin() + m
        nums1.insert(nums1.begin() + m, nums2.begin(), nums2.end());
        nums1.resize(m + n);
        sort(nums1.begin(), nums1.end());
    }

    void merge1(int A[], int m, int B[], int n) {
        if (n == 0)
        {
            return;
        }

        if (m == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                A[i] = B[i];
            }

            return;
        }

        bool increasing = true;

        if (A[0] > A[m - 1] || B[0] > B[n - 1])
        {
            increasing = false;
        }

        int C[m + n];
        int i = 0, j = 0, d = 0;


        for ( ; i < m && j < n; )
        {
            if (A[i] < B[j])
            {
                C[d++] = increasing ? A[i++] : B[j++];
            }
            else
            {
                C[d++] = increasing ? B[j++] : A[i++];
            }
        }

        if (i < m)
        {
            for ( ; i < m; )
            {
                C[d++] = A[i++];
            }
        }
        else
        {
            for ( ; j < n; )
            {
                C[d++] = B[j++];
            }
        }

        for (int i = 0; i < m + n; ++i)
        {
            A[i] = C[i];
        }
    }
};

int main()
{
    Solution sln;
    vector<int> A;
    vector<int> B = {1};
    //vector<int> A = {1, 2, 3, 8, 19, 28};
    //vector<int> B = {4, 5, 9, 10, 20, 25, 30};
    int m = A.size(), n = B.size();
    A.resize(m + n);

    printVector<int>(A);
    printVector<int>(B);
    sln.merge(A, m, B, n);
    printVector<int>(A);

    return 0;
}
