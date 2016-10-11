#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size(), sz2 = num2.size();
        int i = sz1 - 1, j = sz2 - 1, canary = 0;
        string res;

        while (i >= 0 || j >= 0) {
            int a = 0, b = 0;

            if (i >= 0) {
                a = num1[i--] - '0';
            }

            if (j >= 0) {
                b = num2[j--] - '0';
            }

            int c = a + b + canary;
            res.push_back(c % 10 + '0');
            canary = c / 10;
        }
        
        if (canary) {
            res.push_back(canary + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sln;
    //string a("123"), b("456");
    //string a("9"), b("999");
    //string a("9"), b("909");
    //string a("71"), b("978");
    string a("71"), b("178");
    cout << sln.addStrings(a, b) << endl;
    return 0;
}
