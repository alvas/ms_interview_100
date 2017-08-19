#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings2(string s) {
        int num = s.size();
        int ans = 0;

        vector<vector<bool>> dp(num, vector<bool>(num));

        for (int i = num - 1; i >= 0; --i) {
            for (int j = i; j < num; ++j) {
                dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);

                if (dp[i][j])
                    ++ans;
            }
        }

        return ans;
    }

    int countSubstrings(string s) {
        int ans = 0, num = s.size();
        for (int i = 0; i < num; ++i) {
            for (int j = 0; i - j >= 0 && i + j < num && s[i - j] == s[i + j]; ++j)
                ans++;

            for (int j = 0; i - 1 - j >= 0 && i + j < num && s[i - 1 - j] == s[i + j]; ++j) 
                ans++;
        }

        return ans;
    }

    int countSubstrings1(string s) {
        int num = s.size();
        int ans = num;

        for (int i = 1; i < num; ++i) {
            for (int j = 0; i + j < num; ++j) {
                if (isPalindrom(s, j, j + i)) {
                    ans++;
                }
            }
        }

        return ans;
    }

    bool isPalindrom(string &s, int b, int e) {
        while (b <= e) {
            if (s[b] != s[e]) {
                return false;
            }

            b++;
            e--;
        }

        return true;
    }
};

int main()
{
    Solution sln;
    //string s("abc");
    string s("aac");
    cout << sln.countSubstrings(s) << endl;
    return 0;
}
