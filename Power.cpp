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

#ifndef EXPORTED
int main()
{
    cout << isPowerOf3(9) << endl;
}
#endif
