#include <bitset>
#include <iostream>
#include <string>

using namespace std;

const int ODDMASK = 0x55555555;
const int EVENMASK = 0xAAAAAAAA;

// This fucntion swaps the odd bit and even bit of an integer.
void swapIntOddEvenBit(int &num)
{
    int odd = num & ODDMASK; 
    int even = num & EVENMASK;
    num = odd << 1 | even >> 1;
}

// this function prints the integer in binary.
void printIntBinary(int num)
{
    for (int i = 8 * sizeof(int) - 1; i >= 0; --i)
    {
        int bit = num >> i;
        bit = bit & 0x1;
        cout << bit;
    }

    cout << endl;
}

#ifndef EXPORTED
int main()
{
    cout << "sizeof(int): " << sizeof(int) << endl;

    int a = 375;
    bitset<32> x(a);
    cout << x << endl;

    swapIntOddEvenBit(a);
    x = bitset<32>(a);
    cout << x << endl;

    x = bitset<32>(0xdeadbeef);
    cout << x << endl;

    x = bitset<32>(string("0110110100"));
    cout << x << endl;
    return 0;
}
#endif
