#include <iostream>
#include <random>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
        {
            return false;
        }

        return ((num & (num - 1)) == 0) && ((num & 0x5555555555555555) == num);
    }

    bool isPowerOfFour2(int num) {
        if (num <= 0)
        {
            return false;
        }

        int count = (num & 0x3) + 
                    ((num & 0xc) >> 2) +
                    ((num & 0x30) >> 4) + 
                    ((num & 0xc0) >> 6) +
                    ((num & 0x300) >> 8) +
                    ((num & 0xc00) >> 10) +
                    ((num & 0x3000) >> 12) +
                    ((num & 0xc000) >> 14) +
                    ((num & 0x30000) >> 16) +
                    ((num & 0xc0000) >> 18) + 
                    ((num & 0x300000) >> 20) +
                    ((num & 0xc00000) >> 22) + 
                    ((num & 0x3000000) >> 24) +
                    ((num & 0xc000000) >> 26) + 
                    ((num & 0x30000000) >> 28) +
                    ((num & 0xc0000000) >> 30);

        return count == 1;
    }

    bool isPowerOfFour1(int num) {
        if (num <= 0)
        {
            return false;
        }

        while (num != 1)
        {
            if (num % 4 != 0)
            {
                return false;
            }

            num /= 4;
        }

        return num == 1;
    }
};

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 500);
    //int num = distribution(generator);
    int num = 16;
    Solution sln;
    std::cout << num << ", " << sln.isPowerOfFour(num) << ", " << sln.isPowerOfFour1(num) << std::endl;
}
