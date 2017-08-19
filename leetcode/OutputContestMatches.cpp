#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> tmp;

        for (int i = 1; i <= n / 2; ++i) {
            stringstream ss;
            ss << "(" << i << "," << n - i + 1 << ")";
            tmp.push_back(ss.str());
        }

        n /= 2;

        while (n >= 2) {
            for (int i = 1; i <= n / 2; ++i) {
                stringstream ss;
                ss << "(" << tmp[i - 1] << "," << tmp[n - i] << ")";
                tmp[i - 1] = ss.str();
            }

            n /= 2;
        }

        return tmp[0];
    }
};

int main()
{
    Solution sln;
    int n = 4;
    cout << sln.findContestMatch(n) << endl;
    return 0;
}
