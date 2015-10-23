#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Need to improve.
    vector<string> findRepeatedDnaSequences(string s) {
        int sz = s.size();
        vector<string> v;

        if (sz <= 10)
        {
            return v;
        }

        set<long long> keyS, duplicates;
        long long sum = 0;

        // Please be careful, dont' use += below. 
        for (int i = 0; i < 10; ++i)
        {
            char c = s[i];

            switch (c)
            {
                case 'A':
                    {
                        sum = 1 + sum * 10;
                        break;
                    }
                case 'C':
                    {
                        sum = 2 + sum * 10;
                        break;
                    }
                case 'G':
                    {
                        sum = 3 + sum * 10;
                        break;
                    }
                case 'T':
                    {
                        sum = 4 + sum * 10;
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
        }

        keyS.insert(sum);

        for (int i = 10; i < sz; ++i)
        {
            char c = s[i - 10];

            // Need to use -= here.
            switch (c)
            {
                case 'A':
                    {
                        sum -= 1000000000 * 1;
                        break;
                    }
                case 'C':
                    {
                        sum -= 1000000000 * 2;
                        break;
                    }
                case 'G':
                    {
                        // Be careful 100000000 * 3 would overlow int
                        sum -= 1000000000 * (long long)3;
                        break;
                    }
                case 'T':
                    {
                        sum -= 1000000000 * (long long)4;
                        break;
                    }
                default:
                    {
                        break;
                    }
            }

            c = s[i];

            switch (c)
            {
                case 'A':
                    {
                        sum = 1 + sum * 10;
                        break;
                    }
                case 'C':
                    {
                        sum = 2 + sum * 10;
                        break;
                    }
                case 'G':
                    {
                        sum = 3 + sum * 10;
                        break;
                    }
                case 'T':
                    {
                        sum = 4 + sum * 10;
                        break;
                    }
                default:
                    {
                        break;
                    }
            }

            set<long long>::iterator itr = keyS.find(sum);
            set<long long>::iterator itr2 = duplicates.find(sum);

            if (itr != keyS.end() && itr2 ==  duplicates.end())
            {
                v.push_back(s.substr(i - 9, 10));
                duplicates.insert(sum);
            }
            else
            {
                keyS.insert(sum);
            }
        }

        return v;
    }
};

int main()
{
    Solution sln;
    //string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    string s("AAAAAAAAAAAA");
    std::cout << s << endl;
    vector<string> v = sln.findRepeatedDnaSequences(s);
    printVector<string>(v);
    return 0;
}
