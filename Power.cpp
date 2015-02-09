#include <iostream>

using namespace std;

bool isPowerOf3(int n)
{
    if (n < 0)
    {
        return false;
    }

    do
    {
        if (n % 3 != 0)
        {
            return false;
        }

        n /= 3;
    } while (n != 1);

    return true;
}

int Exp(int x, int n)
{
    int result = 1;

    do {
        if (n & 1)
        {
            result *= x;
        }
        
        x *= x;
        n >>= 1;
    } while (n > 0);

    return result;
}

#ifndef EXPORTED
int main()
{
    //cout << isPowerOf3(9) << endl;
    int n = 0;
    cout << "Please enter n for Exp(2, n):";
    cin >> n;
    cout << Exp(2, n) << endl;
}
#endif
