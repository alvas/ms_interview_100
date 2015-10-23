#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;

        if (denominator == 0)
        {
            return res;
        }
        else if (numerator == 0)
        {
            return "0";
        }

        long long n = numerator, d = denominator;

        if ((n < 0) ^ (d < 0))
        {
            res += "-";
        }

        n = abs(n), d = abs(d);
        long long q = n / d;

        res += to_string(q);
        long long r = n % d;

        if (r != 0)
        {
            res += ".";
        }
        else
        {
            return res;
        }

        // map the remainder to index is the key.
        unordered_map<long long, int> mp;

        while (r != 0)
        {
            if (mp.find(r) == mp.end())
            {
                mp[r] = res.size();
            }
            else
            {
                int idx = mp[r];
                int sz = res.size() - idx;
                string repeat = res.substr(idx, sz);
                repeat = "(" + repeat + ")";
                res.erase(idx, sz);
                res += repeat;
                break;
            }

            // This is important. This has be be after the map insert code above.
            r *= 10;
            q = r / d;
            r = r % d;
            res += to_string(q);
        }

        return res;
    }
};

int main()
{
    Solution sln;
    //int num = 2, denominator = 3;
    //int num = 2, denominator = 1;
    //int num = 2, denominator = 69;
    int num = 1, denominator = 6;
    //int num = -50, denominator = 8;
    //int num = -1, denominator = -2147483648;
    //std::cout << "Please enter numerator: ";
    //cin >> num;
    //std::cout << "Please enter denominator: ";
    //cin >> denominator;
    std::cout << sln.fractionToDecimal(num, denominator) << endl;
    return 0;
}
