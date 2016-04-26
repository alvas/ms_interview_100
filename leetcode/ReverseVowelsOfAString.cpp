#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int m = s.size();

        int b = 0, e = m - 1;
        unordered_set<char> s1 = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (b < e)
        {
            while (b < e && s1.find(s[b]) == s1.end())
            {
                b++;
            }

            while (b < e && s1.find(s[e]) == s1.end())
            {
                e--;
            }

            swap(s[b], s[e]);

            b++;
            e--;
        }
        
        return s;
    }
};

int main()
{
    Solution sln;
    string s("leetcode");
    std::cout << s << std::endl;
    std::cout << sln.reverseVowels(s) << std::endl;
}
