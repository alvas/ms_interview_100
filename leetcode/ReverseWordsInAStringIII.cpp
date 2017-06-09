#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string res;
        iss >> res;
        reverse(res.begin(), res.end());

        while (iss)
        {
            string sub;
            iss >> sub;
            reverse(sub.begin(), sub.end());

            if (!sub.empty()) {
                res += " " + sub;
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    string s("Let's take LeetCode contest");
    cout << sln.reverseWords(s) << endl;
    return 0;
}
