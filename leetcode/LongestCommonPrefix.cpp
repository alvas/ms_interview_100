#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        int lengthOfS1 = 0;
        int numOfStr = strs.size();

        // only have 1 string in the vector
        if (numOfStr == 0)
        {
            return prefix;
        }
        else if (numOfStr > 0)
        {
            if (numOfStr == 1)
            {
                return strs[0];
            }

            lengthOfS1 = strs[0].size();
        }

        bool reachMinLen = false;
        int len = 0;

        for ( ; len < lengthOfS1; ++len)
        {
            vector<string>::iterator itr = strs.begin();
            char c = (*itr++)[len];
            int numSameChar = 1;

            for ( ;itr != strs.end(); ++itr)
            {
                if (itr->size() > len)
                {
                    if ((*itr)[len] == c)
                    {
                        numSameChar++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    reachMinLen = true;
                    break;
                }
            }

            if (reachMinLen || numSameChar < numOfStr)
            {
                prefix = strs[0].substr(0, len);
                break;
            }
        }

        // if all strings are the same, return the first string
        // and also consider there is no string in the vector
        if (len == lengthOfS1 && len > 0)
        {
            prefix = strs[0];
        }

        return prefix;
    }
};

int main()
{
    Solution sln;
    vector<string> v;

    string s;
    std::cout << "Please enter string: ";
    // Use getline to get input for string.
    // get rid of the nasty side effect of cin >> s; which can't recognize empty input
    // so can't use empty string to stop input.
    getline(cin, s);

    while (!s.empty())
    {
        v.push_back(s);
        std::cout << "Please enter string: ";
        getline(cin, s);
    }

    std::cout << sln.longestCommonPrefix(v) << endl;
    return 0;
}

