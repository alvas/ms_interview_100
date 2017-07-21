#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }

        return s;
    }

    string reverseStr1(string s, int k) {
        if (k == 0) {
            return s;
        }

        int sz = s.size();

        for (int i = 0, j = 0; i < sz; i++) {
            if (i % k == 0 && i % (2 * k) != 0) {
                reverse(s.begin() + j, s.begin() + i);
            }
            else if (i % (2 * k) == 0) {
                j = i;
            }
            else if (i == sz - 1 && i - j < k) {
                reverse(s.begin() + j, s.end());
            }
        }

        return s;
    }
};

int main()
{
    Solution sln;
    //string s = "abcdefg";
    //string s = "abcdefgh";
    //string s = "abcdefghi";
    string s = "abcdefghij";
    int k = 3;
    cout << sln.reverseStr(s, k) << endl;
    return 0;
}
