#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        size_t n = pattern.size();
        unordered_map<char, string> m; 
        unordered_map<string, char> rm;
        istringstream instr(str);
        int i = 0;

        for (string w; instr >> w; )
        {
            char c = pattern[i++];

            auto itr1 = m.find(c);
            auto itr2 = rm.find(w);

            if (itr1 == m.end() && itr2 == rm.end())
            {
                m[c] = w;
                rm[w] = c;
            }
            else if ((itr1 != m.end() && itr1->second != w) ||
                     (itr2 != rm.end() && itr2->second != c))
            {
                return false;
            }
        }

        return i == n;
    }

    bool wordPattern1(string pattern, string str) {
        std::size_t b = 0, count = 0, idx = 0, sz = pattern.size();
        std::unordered_map<char, string> m;
        std::unordered_map<string, char> rm;

        do
        {
            idx = str.find(" ", b);
            string token = str.substr(b, idx - b);

            if (count >= sz)
            {
                return false;
            }

            char c = pattern[count];

            if (m.find(c) != m.end())
            {
                if (m[c] != token)
                {
                    return false;
                }
            }
            else
            {
                if (rm.find(token) != rm.end())
                {
                    return false;
                }

                m.emplace(c, token);
                rm.emplace(token, c);
            }

            count++;

            // don't miss increasing 1
            b = idx + 1;
        } while (idx != std::string::npos);

        return count == sz;
    }
};

int main()
{
    Solution sln;
    std::string pattern("abba"), str("dog cat cat dog");
    //string pattern("abba"), str("dog cat cat fish");
    //string pattern("aaaa"), str("dog cat cat dog");
    //string pattern("abba"), str("dog dog dog dog");
    //string pattern("jquery"), str("jquery");
    std::cout << sln.wordPattern(pattern, str) << endl;
    return 0;
}
