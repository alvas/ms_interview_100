#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;    
        int a = 1;

        for (string::reverse_iterator itr = s.rbegin(); itr != s.rend(); ++itr)
        {
            char c = *itr;
            c = toupper(c);

            num = num + (c - 'A' + 1) * a;
            a *= 26;
        }

        return num;
    }
};

int main()
{
    Solution sln;
    string str;
    cin >> str;
    cout << sln.titleToNumber(str) << endl;
    return 0;
}

