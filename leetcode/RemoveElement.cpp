#include <iostream>
#include <vector>
#include <sstream>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        size_t m = nums.size();

        for (int j = 0; j < m; ++j)
        {
            if (nums[j] != val)
            {
                nums[i++] = nums[j];
            }
        }

        nums.resize(i);
        return i;
    }

    int removeElement_naive(vector<int> &nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }

    //int removeElement1(int A[], int n, int elem) {
        //int i = 0, j = n - 1;

        //// Be carefull about the equal condition here!!
        //while (i <= j)
        //{
            //while (A[i] != elem && i <= j)
            //{
                //i++;
            //}

            //if (i > j)
            //{
                //break;
            //}

            //while (A[j] == elem && i <= j)
            //{
                //j--;
            //}

            //if (i > j)
            //{
                //break;
            //}

            //swap(A[i], A[j]);
            ////int tmp = A[i];
            ////A[i] = A[j];
            ////A[j] = tmp;
        //}

        //return i;
    //}
};

int main()
{
    Solution sln;
    //int A[500];
    //int n = 0, elem = 0;
    //string s;

    //std::cout << "Please enter numbers: ";
    //getline(cin, s);

    //std::cout << "Please enter elem: ";
    //cin >> elem;

    //istringstream str(s);
    //string sub;

    //while (getline(str, sub, ' '))
    //{
        //A[n++] = atoi(sub.c_str());
    //}

    //std::cout << sln.removeElement(A, n, elem) << endl;
    //vector<int> A = {3, 2, 2, 3};
    vector<int> A = {2, 2, 3};
    vector<int> B = A;
    int val = 2;
    std::cout << sln.removeElement(A, val) << endl;
    sln.removeElement_naive(B, val);
    printVector<int>(A);
    printVector<int>(B);
    return 0;
}
