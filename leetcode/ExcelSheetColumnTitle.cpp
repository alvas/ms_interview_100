#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;

        while (n != 0)
        {
            // Need to be careful about n - 1
            char a = (n - 1) % 26;
            s.push_back(a + 'A');
            // Need to be careful about n - 1
            n = (n - 1) / 26;
        }

        reverse(s.begin(), s.end());
        
        return s;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cin >> n;
    cout << sln.convertToTitle(n) << endl;
    return 0;
}

