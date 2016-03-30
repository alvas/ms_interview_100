#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> m;
        m['1'] = string("");
        m['2'] = string("abc");
        m['3'] = string("def");
        m['4'] = string("ghi");
        m['5'] = string("jkl");
        m['6'] = string("mno");
        m['7'] = string("pqrs");
        m['8'] = string("tuv");
        m['9'] = string("wxyz");

        vector<string> res;
        vector<int> lens;

        for (auto d : digits)
        {
            lens.push_back(m[d].size());
        }

        int n = digits.size();

        for (int i = 0; i < n; ++i)
        {
            vector<string> tmp;

            for (int j = 0; j < lens[i]; ++j)
            {
                if(res.empty())
                {
                    string s(1, m[digits[i]][j]);
                    tmp.push_back(s);
                }
                else
                {
                    for (auto s : res)
                    {
                        s.append(1, m[digits[i]][j]);
                        tmp.push_back(s);
                    }
                }
            }

            // When the digit is 1, lens[i] is 0, we don't swap.
            if (lens[i] > 0)
            {
                res.swap(tmp);
            }
        }

        return res;
    }

    vector<string> letterCombinations_recursive(string digits) {
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
    vector<string> digits = {"23", "347", "555", "9871"};

    for (auto d : digits)
    {
        vector<string> v = sln.letterCombinations_recursive(d);
        printVector<string>(v);
        std::cout << std::endl;
        vector<string> v1 = sln.letterCombinations(d);
        printVector<string>(v1);
        std::cout << std::endl;
    }

    return 0;
}
