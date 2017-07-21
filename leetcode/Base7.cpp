#include <iostream>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string res;
        bool isNegative = num < 0;
        num = abs(num);

        if (num == 0) {
            return "0";
        }

        while (num != 0) {
            int r = num % 7;
            //res.append(1, '0' + r);
            res = to_string(r) + res;
            num /= 7;
        }

        if (isNegative) {
            //res.append(1, '-');
            res = "-" + res;
        }

        //reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution sln;
    //int num = 103;
    //int num = -7;
    int num = 0;
    cout << sln.convertToBase7(num) << endl;
    return 0;
}
