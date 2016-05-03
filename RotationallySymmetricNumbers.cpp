#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool isRotationallySymmetricNumber(string src)
{
    if (src.empty())
    {
        return true;
    }

    string tar;
    unordered_map<char, char> m = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    int n = src.size(), n2 = n / 2;

    for (int i = 0; i <= n2; ++i)
    {
        if (m[src[i]]!= src[n - 1 - i])
        {
            return false;
        }
    }

    return true;

    //for (auto c: src)
    //{
        //if (m.find(c) != m.end())
        //{
            //tar += m[c];
        //}
        //else
        //{
            //return false;
        //}
    //}

    //reverse(tar.begin(), tar.end());
    //return src == tar;
}

void generate(int n, unordered_map<char, char> &m, set<string> &s, string str)
{
    if (n <= 0)
    {
        if (isRotationallySymmetricNumber(str))
        {
            s.insert(str);
        }

        return;
    }

    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        str.push_back(itr->second);
        generate(n - 1, m, s, str);
        // don't forget to pop it out.
        str.pop_back();
    }
}

set<string> generateRotationallySymmetricNumbers(int n)
{
    set<string> s;

    if (n < 0)
    {
        return s;
    }

    unordered_map<char, char> m = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    string str;

    generate(n, m, s, str);

    return s;
}


int main()
{
    //vector<string> nums = {"0", "1", "8"};
    //vector<string> nums = {"2", "3", "."};
    vector<string> nums = {"00", "11", "88", "69", "96"};

    for (auto num : nums)
    {
        std::cout << isRotationallySymmetricNumber(num) << std::endl;
    }

    set<string> s = generateRotationallySymmetricNumbers(3);

    for (auto str : s)
    {
        std::cout << str << std::endl;
    }
}
