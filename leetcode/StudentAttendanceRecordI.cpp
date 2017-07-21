#include <iostream>
#include <string>

class Solution {
public:
    bool checkRecord(string s) {
        int numA = 0, numL = 0;

        for (auto i: s) {
            if (i == 'A') {
                numA++;
                numL = 0;

                if (numA == 2) {
                    return false;
                }
            }
            else if (i == 'L') {
                numL++;

                if (numL == 3) {
                    return false;
                }
            }
            else
            {
                numL = 0;
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    string s;
    cout << sln.checkRecord(s) << endl;
    return 0;
}
