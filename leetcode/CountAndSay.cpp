#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        map<int, string> num = {{1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, 
                                {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}}; 

        while (--n)
        {
            string::iterator itr = seq.begin();
            char digit = *itr++;
            stringstream tmp;
            int count = 1;

            for ( ; itr != seq.end(); ++itr)
            {
                if (digit == *itr)
                {
                    count++;
                }
                else
                {
                    tmp << num[count] << digit;
                    digit = *itr;
                    count = 1;
                }
            }

            tmp << num[count] << digit;
            seq = tmp.str();
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
