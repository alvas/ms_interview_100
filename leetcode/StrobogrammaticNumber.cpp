#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        // we can use an array int buddy[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        // this is faster than map
        unordered_map<char, char> m;
        // don't forget 0
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';

        int sz = num.size();
        int l = 0, r = sz - 1;

        // single number like 2 is false
        while (l <= r) {
            if (m[num[l++]] != num[r--]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sln;
    //string num("2");
    string num("101");
    //string num("69");
    //string num("88");
    //string num("818");
    cout << sln.isStrobogrammatic(num) << endl;
    return 0;
}
