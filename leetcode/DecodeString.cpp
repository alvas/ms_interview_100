#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

    string decodeString(const string &s, int &i) {
        string ans;

        // sub string always ends after ]
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) {
                ans += s[i++];
            }
            else {
                int n = 0;

                while (i < s.length() && isdigit(s[i])) {
                    n = n * 10 + s[i++] - '0';
                }

                i++; // '['
                // sub string always starts after a number and [
                string t = decodeString(s, i);
                i++; // ']'

                while (n -- > 0) {
                    ans += t;
                }
            }
        }

        return ans;
    }

    string decodeString1(string s) {
        string ans;
        int num = 0;
        stack<int> stk;
        string sub;
        stack<string> prefixs;

        for (auto c: s) {
            if (isdigit(c)) {
                if (!sub.empty()) {

                    // sd2[a]
                    if (stk.empty()) {
                        ans.insert(ans.size(), sub);
                        sub.clear();
                    }
                    else {
                        // a2[a3[c]]
                        prefixs.push(sub);
                        sub.clear();
                    }
                }

                num = num * 10 + c - '0';
            }
            else if (c == '[') {
                stk.push(num);
                num = 0;
            }
            else if (c == ']') {
                int k = stk.top();
                stk.pop();

                if (stk.empty()) {
                    for (int i = 0; i < k; ++i) {
                        ans.insert(ans.size(), sub);
                    }

                    sub.clear();
                }
                else {
                    string tmp;

                    for (int i = 0; i < k; ++i) {
                        tmp += sub;
                    }

                    sub = tmp;

                    // a3[b[3[c]]]
                    if (!prefixs.empty()) {
                        sub = prefixs.top() + sub;
                        prefixs.pop();
                    }
                }
            }
            else
            {
                sub.push_back(c);
            }
        }

        // 2[bc]ad
        if (!sub.empty()) {
            ans.insert(ans.size(), sub);
        }

        return ans;
    }
};

int main() {
    Solution sln;
    //string s("3[a]2[bc]");
    //string s("3[a2[c]]");
    //string s("2[abc]3[cd]ef");
    string s("sd2[f2[e]g]i");
    cout << sln.decodeString(s) << endl;
    return 0;
}
