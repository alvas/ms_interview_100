#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        map<int, string> num;

        num[1] = "1";
        num[2] = "2";
        num[3] = "3";
        num[4] = "4";
        num[5] = "5";
        num[6] = "6";
        num[7] = "7";
        num[8] = "8";
        num[9] = "9";

        while (--n)
        {
            string::iterator itr = seq.begin();
            char digit = *itr++;
            string tmp;
            int count = 1;

            for ( ; itr != seq.end(); ++itr)
            {
                if (digit == *itr)
                {
                    count++;
                }
                else
                {
                    tmp = tmp + num[count] + string(1, digit);
                    digit = *itr;
                    count = 1;
                }
            }

            tmp = tmp + num[count] + string(1, digit);

            seq = tmp;
        }

        return seq;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    std::cout << sln.countAndSay(n) << endl;
    return 0;
}
