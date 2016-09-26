#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        // can use addition also
        return accumulate(begin(s), end(s += t), 0, bit_xor<int>());
    }

    char findTheDifference2(string s, string t) {
        unordered_map<char, int> m;

        for (char c: s)
        {
            ++m[c];
        }

        for (char c: t)
        {
            if (--m[c] < 0)
            {
                return c;
            }
        }

        return 0;
    }

    char findTheDifference1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (auto itr = s.begin(), itr2 = t.begin(); itr != s.end(); ++itr, ++itr2)
        {
            if (*itr != *itr2)
            {
                return *itr2;
            }
        }

        return t.back();
    }
};

int main()
{
    Solution sln;
    string s("abcd"), t("abcde");
    cout << sln.findTheDifference(s, t) << endl;
    return 0;
}
