#include <bitset>
#include <iostream>
#include <set>
#include <string>

using namespace std;

const int ODDMASK = 0x55555555;
const int EVENMASK = 0xAAAAAAAA;

const int NUM = 100;

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
#if 0
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
#endif

    set<int> idSet;

    for (int i = 0; i < NUM; ++i)
    {
        int num = rand() % NUM;
        idSet.insert(num);
    }

    bitset<NUM> file;

    for (set<int>::iterator itr = idSet.begin(); itr != idSet.end(); ++itr)
    {
        file.set(*itr);
    }

    int sizeOfFile = file.size();

    for (int i = 0; i < sizeOfFile; ++i)
    {
        if (file[i])
        {
            cout << i << endl;
        }
    }
}
#endif
