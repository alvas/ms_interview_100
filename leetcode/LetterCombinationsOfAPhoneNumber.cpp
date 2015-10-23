#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        int sz = digits.size();

        // Be careful. When the digits is "", it expects [], not an empty string in the vector [""]
        if (sz == 0)
        {
            return v;
        }

        map<char, string> m;
        m['2'] = string("abc");
        m['3'] = string("def");
        m['4'] = string("ghi");
        m['5'] = string("jkl");
        m['6'] = string("mno");
        m['7'] = string("pqrs");
        m['8'] = string("tuv");
        m['9'] = string("wxyz");

        string tmp;
        letter(digits, sz, 0, m, tmp, v);
        
        return v;
    }

    void letter(string &digits, int sz, int idx, map<char, string> &m, string &tmp, vector<string> &v)
    {
        if (idx >= sz)
        {
            v.push_back(tmp);
            return;
        }

        int szM = m[digits[idx]].size();

        if (szM > 0)
        {
            for (int j = 0; j < szM; ++j)
            {
                tmp.push_back(m[digits[idx]][j]);
                letter(digits, sz, idx + 1, m, tmp, v);
                tmp.pop_back();
            }
        }
        else
        {
            letter(digits, sz, idx + 1, m, tmp, v);
        }
    }
};

int main()
{
    Solution sln;
    string digits;
    std::cout << "Please enter digits: ";
    cin >> digits;
    vector<string> v = sln.letterCombinations(digits);
    printVector<string>(v);
    return 0;
}
