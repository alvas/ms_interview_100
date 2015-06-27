#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string a;

        if (n == 0 || k == 0)
        {
            return a;
        }

        return a;
    }

    string getPermutation_recursive(int n, int k) {
        string a;

        if (n == 0 || k == 0)
        {
            return a;
        }

        a = "123456789";
        a.resize(n);
        permutate(a, 0, n, k);
        return a;
    }

    void permutate(string &a, int idx, int n, int &k)
    {
        if (idx >= n)
        {
            k--;

            if (k <= 0)
            {
                return;
            }
        }

        for (int i = idx; i < n && k > 0; ++i)
        {
            swap(a[idx], a[i]);
            permutate(a, idx + 1, n, k);

            if (k <= 0)
            {
                break;
            }

            swap(a[idx], a[i]);
        }
    }
};

int main()
{
    Solution sln;
    int k = 0, n = 0;
    cout << "Please enter n <= 9: ";
    cin >> n;
    cout << "Please enter k < " << n << "!: ";
    cin >> k;
    cout << sln.getPermutation_recursive(n, k) << endl;
    cout << sln.getPermutation(n, k) << endl;
    return 0;
}
