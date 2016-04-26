#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int m = s.size();
        int b = 0, e = m - 1;

        while (b < e)
        {
            std::swap(s[b], s[e]);
            b++;
            e--;
        }

        return s;
    }

    string reverseString1(string s) {
        std::reverse(s.begin(), s.end()); 
        return s;
    }
};

int main()
{
    Solution sln;
    string s("hello");
    std::cout << s << std::endl;
    std::cout << sln.reverseString(s) << std::endl;
}
