#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
    }

    bool checkPerfectNumber1(int num) {
        if (num == 1) {
            return false;
        }

        int sum = 1, root = sqrt(num);

        for (int i = 2; i <= root; ++i) {
            if (num % i == 0) {
                sum += i + num / i;
            }
        }

        return sum == num;
    }
};

int main()
{
    Solution sln;
    //int num = 28;
    //int num = 99999993;
    int num = 99999998;
    cout << sln.checkPerfectNumber1(num) << endl;
    return 0;
}
