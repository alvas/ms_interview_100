#include <algorithm>
#include <cctype>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;

        for (auto i: s) {
            b.flip(i);
        }

        return b.count() < 2;
    }

    bool canPermutePalindrome1(string s) {
        unordered_map<char, int> m;

        for (auto i: s) {
            m[i]++;
        }

        int odd = 0;

        for (int i = 'a'; i <= 'z'; ++i) {
            if (m[i] & 1) {
                odd++;
            }
        }

        for (int i = 'A'; i <= 'Z'; ++i) {
            if (m[i] & 1) {
                odd++;
            }
        }

        return odd <= 1;
    }
};

int main() {
    Solution sln;
    //string s("code");
    //string s("aab");
    string s("carerac");
    cout << sln.canPermutePalindrome(s) << endl;
    return 0;
}
