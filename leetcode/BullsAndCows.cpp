#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0, c = 0;
        vector<int> sd(10, 0), gd(10, 0);
        int sz = secret.size();

        for (int i = 0; i < sz; ++i)
        {
            if (secret[i] == guess[i])
            {
                b++;
            }
            else
            {
                sd[secret[i] - '0']++;
                gd[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; ++i)
        {
            // be careful about the condition and value here
            if (sd[i] != 0 && gd[i] != 0)
            {
                c += min(sd[i], gd[i]);
            }
        }

        // the number can be more than 1 digit, so we can't using the approache with replacing number in "0A0B".
        return std::to_string(b) + "A" + std::to_string(c) + "B";
    }
};

int main()
{
    Solution sln;
    //string s("1123"), g("0111");
    //string s("1807"), g("7810");
    string s("1122"), g("0001");
    std::cout << sln.getHint(s, g) << std::endl;
    return 0;
}
