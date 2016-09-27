#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (!num) {
            return "0";
        }

        string hex;
        unsigned int value = num;

        while (value) {
            int c = value & 0xf;
            value >>= 4;
            hex += m[c];
        }

        reverse(hex.begin(), hex.end());
        return hex;
    }

    unordered_map<int, char> m = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
        {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
        {8, '8'}, {9, '9'}, {10, 'a'}, {11, 'b'},
        {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}};
};

int main()
{
    Solution sln;
    //int num = 26;
    //int num = 0;
    //int num = -1;
    //int num = 2147483647;
    int num = -2147483648;
    cout << sln.toHex(num) << endl;
    return 0;
}
