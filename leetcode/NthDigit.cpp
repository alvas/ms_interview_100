#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if (n <=0) {
            return 0;
        }

        // be careful about overflow
        long a = 1, b = 1, c = 9 * a * b, d = 0;

        while (d + c < n) {
            d = d + c;
            a *= 10;
            b += 1;
            c = 9 * a * b;
        }

        // be careful. this is so tircky to get it right.
        int t = (n - d - 1) / b + a;

        // or we can conver t to string and get the digi at the right location
        int s = (b - (n - d) % b) % b;

        //cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
        //cout << "t: " << t << ", s: " << s << endl;

        t /= pow(10, s);

        //for (int i = 0; i < s; ++i) {
            //t /= 10;
        //}

        return t % 10;
    }
};

int main() {
    Solution sln;
    //int n = 189;
    //int n = 190;
    //int n = 191;
    //int n = 192;
    //int n = 11;
    //int n = 189;
    //int n = 867;
    //int n = 10;
    //int n = 11;
    int n = 1000000000;
    cout << sln.findNthDigit(n) << endl;
    return 0;
}
