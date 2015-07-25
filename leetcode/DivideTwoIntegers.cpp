#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
        {
            return INT_MAX;
        }
        
        int val = 0;
        return val;
    }
};

int main()
{
    Solution sln;
    int dividend = 0, divisor = 0;
    cout << "Please enter dividend: ";
    cin >> dividend;
    cout << "Please enter divisor: ";
    cin >> divisor;
    cout << sln.divide(dividend, divisor) << endl;
    return 0;
}
