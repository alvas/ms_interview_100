#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
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
    int k = 0, n = 0;
    cout << "Please enter n <= 9: ";
    cin >> n;
    cout << "Please enter k < " << n << "!: ";
    cin >> k;
    //cout << sln.getPermutation_recursive(n, k) << endl;
    cout << sln.getPermutation(n, k) << endl;
    return 0;
}
