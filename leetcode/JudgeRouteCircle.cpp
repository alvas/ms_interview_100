#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int numU = 0, numD = 0, numL = 0, numR = 0;

        for (auto s: moves) {
            if (s == 'U') {
                numU++;
            }
            else if (s == 'D') {
                numD++;
            }
            else if (s == 'L') {
                numL++;
            }
            else {
                numR++;
            }
        }

        return numU == numD && numL == numR;
    }
};

int main()
{
    Solution sln;
    //string moves("UD");
    string moves("LL");
    cout << sln.judgeCircle(moves) << endl;
    return 0;
}
