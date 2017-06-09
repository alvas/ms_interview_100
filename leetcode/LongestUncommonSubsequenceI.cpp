#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        int sza = a.size(), szb = b.size();

        if (a == b)
            return -1;
        else
            return max(sza, szb);
    }
};

int main()
{
    Solution sln;
    string a("aba"), b("cdc");
    cout << sln.findLUSlength(a, b) << endl;
    return 0;
}
