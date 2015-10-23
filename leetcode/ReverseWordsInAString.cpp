#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void reverseWords(string &s) {
        int n = s.size(), j = n;
        string res;

        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
            {
                j = i;
            }
            else if (i == 0 || s[i - 1] == ' ')
            {
                if (!res.empty())
                {
                    res += " ";
                }

                res += s.substr(i, j - i);
            }
        }

        s = res;
    }

    void reverseWords1(string &s) {
        int n = s.size();

        // Can't use <=, becuase " " should not return the space.
        if (n < 1)
        {
            return;
        }

        string res;
        int j = -1;

        for (int i = 0; i <= n; ++i)
        {
            if (s[i] == ' ' || i == n)
            {
                if (j != -1)
                {
                    string c = s.substr(j, i - j);
                    std::reverse(c.begin(), c.end());

                    if (!res.empty())
                    {
                        res += " ";
                    }

                    res += c;

                    //if (res.empty())
                    //{
                        //res = c;
                    //}
                    //else
                    //{
                        //res += ' ' + c;
                    //}
                }

                j = -1;
            }
            else
            {
                if (j == -1)
                {
                    j = i;
                }

                //if (i == n - 1 && j != -1)
                //{
                    //// Be careful about the length of the last word
                    //string c = s.substr(j, i - j + 1);
                    //std::reverse(c.begin(), c.end());

                    //if (res.empty())
                    //{
                        //res = c;
                    //}
                    //else
                    //{
                        //res += ' ' + c;
                    //}
                //}
            }
        }

        std::reverse(res.begin(), res.end());
        s = res;
    }

    void reverse(string &s, string::iterator startIdx, string::iterator endIdx)
    {
        while (startIdx < --endIdx)
        {
            char tmp = *startIdx;
            *startIdx = *endIdx;
            *endIdx = tmp;
            startIdx++;
        }
    }

    void sanitizeSpace(string &s)
    {
        size_t idx = s.find_first_not_of(' ');
        size_t spaceIdx = s.find_first_of(' ');

        if ((spaceIdx < idx && spaceIdx != string::npos && idx != string::npos) ||
                (spaceIdx != string::npos && idx == string::npos))
        {
            s.erase(spaceIdx, idx);
        }

        idx = s.find_last_not_of(' ');
        spaceIdx = s.find_last_of(' ');

        if (idx < spaceIdx && spaceIdx != string::npos && idx != string::npos)
        {
            s.erase(idx + 1, spaceIdx + 1);
        }

        string::iterator itr = s.begin();

        while (itr != s.end())
        {
            if (*itr != ' ')
            {
                ++itr;
            }
            else
            {
                string::iterator nextItr = itr + 1;

                if (nextItr != s.end() && *nextItr == ' ')
                {
                    s.erase(nextItr);
                }
                else
                {
                    ++itr;
                }
            }
        }
    }

    void reverseWords_complicated(string &s) {
        sanitizeSpace(s);

        string::iterator startIdx = s.begin();

        for (string::iterator itr = s.begin(); itr != s.end(); ++itr)
        {
            if (*itr != ' ')
            {
                continue;
            }

            reverse(s, startIdx, itr);

            startIdx = itr + 1;
        }

        if (startIdx != s.end())
        {
            reverse(s, startIdx, s.end());
        }

        reverse(s, s.begin(), s.end());
    }
};

int main()
{
    Solution sln;
    //string sentence("the sky is blue");
    string sentence("the sky   xxx  is a blue");
    std::cout << "Original sentence: " << sentence << endl;
    sln.reverseWords(sentence);
    std::cout << "Reverse sentence: " << sentence << endl;
    return 0;
}
