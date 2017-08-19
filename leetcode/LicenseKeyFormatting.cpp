#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int count = 0;

        for (auto ritr = S.rbegin(); ritr != S.rend(); ++ritr) {
            if (*ritr != '-') {
                if (count % K == 0 && !ans.empty()) {
                    ans.push_back('-');
                }

                ans.push_back(toupper(*ritr));
                count = (count + 1) % K;
            }
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sln;
    string S("2-4A0r7-4k");
    int K = 3;
    cout << sln.licenseKeyFormatting(S, K) << endl;
    return 0;
}
