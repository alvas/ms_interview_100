#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ctr[256] = {0}, j = -1, distinct = 0, ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            distinct += ctr[s[i]]++ == 0;

            while (distinct > k) {
                distinct -= --ctr[s[++j]] == 0;
            }

            ans = max(ans, i - j);
        }

        return ans;
    }

    int lengthOfLongestSubstringKDistinct2(string s, int k) {
        int ans = 0, l = 0;
        map<char, int> m;
        int count = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0) {
                if (count == k) {
                    while (--m[s[l++]] > 0);
                }
                else {
                    count++;
                }
            }

            m[s[i]]++;
            ans = std::max(ans, i - l + 1);
        }

        return ans;
    }

    int lengthOfLongestSubstringKDistinct1(string s, int k) {
        int ans = 0, l = 0;
        map<char, int> m;

        for (int i = 0; i < s.size(); ++i) {
            m[s[i]]++;

            while (countDistinctChar(m) > k && l <= i) {
                m[s[l++]]--;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }

    int countDistinctChar(std::map<char, int> m) {
        return std::count_if(m.begin(), m.end(), [](std::pair<const char, int> &p) { return p.second != 0; });
    }
};

int main()
{
    Solution sln;
    //string s("eceba");
    //string s("eceea");
    string s("eeeaaab");
    //string s("ekkkkkkkkkkkkke");
    int k = 2;
    cout << sln.lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}
