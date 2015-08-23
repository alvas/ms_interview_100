#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
        {
            return false;
        }
        else if (num == 1 || num == 2 || num == 3 || num == 5)
        {
            return true;
        }

        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else if (num % 3 == 0)
            {
                num /= 3;
            }
            else if (num % 5 == 0)
            {
                num /= 5;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    int num = 0;
    cout << "Please enter num: ";
    cin >> num;
    cout << sln.isUgly(num) << endl;
    return 0;
}
