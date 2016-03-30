#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        int a = 1;

        for (int i = 1; i <= n; ++i)
        {
            a *= i;
        }

        // a = (n - 1)!
        int r = 0;

        // why?? change k from (1, n) to (0, n - 1) to accord to index??
        k--;

        // the range here is important, make sure to loop through n times
        for (int i = n; i > 0; --i)
        {
            a /= i;
            int d = k / a;
            
            // This is wrong, because the index is not right. Need to shift
            // number to left.
            //while (nums[d] == 0)
            //{
                //d++;
            //}

            r = r * 10 + nums[d];

            // shift it to left
            nums.erase(nums.begin() + d);

            k %= a;
        }

        return std::to_string(r);
    }

    string getPermutation1(int n, int k) {
        string a;

        if (n == 0 || k == 0)
        {
            return a;
        }

        vector<int> v(n);
        int permCount = 1;

        for (int i = 0; i < n; ++i)
        {
            v[i] = i + 1;
            permCount *= i + 1;
        }

        // This is important.
        --k;

        for (int i = 0; i < n; ++i)
        {
            permCount /= n - i;
            int t = k / permCount;
            a.push_back('0' + v[t]);

            for (int j = t; j < n - i; ++j)
            {
                v[j] = v[j + 1];
            }

            k %= permCount;
        }

        return a;
    }

    // This solution is wrong. Its order is not correct.
    //string getPermutation_recursive(int n, int k) {
        //string a;

        //if (n == 0 || k == 0)
        //{
            //return a;
        //}

        //a = "123456789";
        //a.resize(n);
        //permutate(a, 0, n, k);
        //return a;
    //}

    //void permutate(string &a, int idx, int n, int &k)
    //{
        //if (idx >= n)
        //{
            //k--;

            //if (k <= 0)
            //{
                //return;
            //}
        //}

        //for (int i = idx; i < n && k > 0; ++i)
        //{
            //swap(a[idx], a[i]);
            //permutate(a, idx + 1, n, k);

            //if (k <= 0)
            //{
                //break;
            //}

            //swap(a[idx], a[i]);
        //}
    //}
};

int main()
{
    Solution sln;
    std::vector<int> k = {1, 2, 3, 4, 5, 6};
    std::vector<int> n = {3, 4, 5};

    for (auto n1 : n)
    {
        for (auto k1 : k)
        {
            std::cout << "n: " << n1 << ", k: " << k1 << ", ";
            std::cout << sln.getPermutation(n1, k1) << std::endl;
        }

        std::cout << endl;
    }
    return 0;
}
