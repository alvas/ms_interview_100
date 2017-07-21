#include <iostream>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf)
{
    return 0;
}

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int numRead = 0;
        int num = 0;
        
        do {
            num = read4(buf + numRead);
            numRead += num;
        } while (num == 4 && numRead < n);

        return min(numRead, n);
    }
};

int main()
{
    Solution sln;
    char *buf = nullptr;
    int n = 4;
    cout << sln.read(buf, n) << endl;
    return 0;
}
