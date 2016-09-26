#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;

        for (int h = 0; h < 12; ++h)
        {
            for (int m = 0; m < 60; ++m)
            {
                if (bitset<10>((h << 6) + m).count() == num)
                {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }

        return res;
    }

    // Need to improve.
    vector<string> readBinaryWatch1(int num) {
        vector<string> res;
        int b = 1 << 10;

        for (int i = 0; i < b; ++i)
        {
            if (countBit(i) == num)
            {
                string &&str = constructTime(i);

                if (!str.empty())
                {
                    res.push_back(str);
                }
            }
        }

        return res;
    }

    int countBit(unsigned int i)
    {
        int count = 0;

        while (i)
        {
            count++;
            i = i & (i - 1);
        }

        return count;
    }

    string constructTime(int i)
    {
        int h = i >> 6;

        if (h > 11)
        {
            return "";
        }

        // be careful about the bit mask, it is not 0x111111
        int m = i & (0x3f);

        if (m > 59)
        {
            return "";
        }
        else if (m < 10)
        {
            return to_string(h) + ":0" + to_string(m);
        }
        else
        {
            return to_string(h) + ":" + to_string(m);
        }
    }
};

int main()
{
    Solution sln;

    for (int i = 0; i < 5; ++i)
    {
        cout << i << " LEDs: " << endl;
        vector<string> &&v = sln.readBinaryWatch(i);
        printVector<string>(v);
        cout << endl;
    }

    return 0;
}
