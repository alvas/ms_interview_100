#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n == 0)
        {
            return false;
        }

        set<int> s;
        n = abs(n);

        while (n != 1)
        {
            int tmp = 0;

            for ( ; n != 0; n /= 10)
            {
                int d = n % 10;
                tmp = tmp + d * d;
            }

            if (s.find(tmp) != s.end())
            {
                return false;
            }

            s.insert(tmp);
            n = tmp;
        }

        return true;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n: ";
    cin >> n;
    cout << sln.isHappy(n) << endl;
    return 0;
}
