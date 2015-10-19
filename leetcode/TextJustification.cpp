#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;

        if (n == 0 || maxWidth == 0)
        {
            string b(maxWidth, ' ');
            res.push_back(b);
            return res;
        }
        else if (n == 1)
        {
            int sz = words[0].size();

            // {"a"}, 1
            if (sz > 0)
            {
                string b(maxWidth - sz, ' ');
                res.push_back(words[0] + b);
            }
            else
            {
                // {""}, 2
                string b(maxWidth, ' ');
                res.push_back(b);
            }

            return res;
        }

        int i = 0;

        while (i < n)
        {
            int sz = words[i].size();
            int l = sz;
            int next = i + 1;

            while (next < n)
            {
                sz = words[next].size() + 1;

                if (l + sz <= maxWidth)
                {
                    next++;
                    l += sz;
                }
                else
                {
                    break;
                }
            }

            int c = next - i, extraSpace = 0;
            string space;
            string s;

            // not last line
            if (next != n)
            {
                // only one word in a line.
                if (c == 1)
                {
                    string b(maxWidth - l, ' ');
                    space = b;
                }
                else
                {
                    string b((maxWidth - l) / (c - 1) + 1, ' ');
                    space = b;
                    extraSpace = (maxWidth - l) % (c - 1);
                }
            }
            else
            {
                // last line. Only insert one space between word if space is allowed.
                // Otherwise, don't insert space.
                // {"a", "b", "c"}, 1
                if (l < maxWidth)
                {
                    space = ' ';
                }
            }

            for (int j = 0; j < c; ++j)
            {
                s += words[i + j];

                if (j != c - 1 || c == 1)
                {
                    s += space;
                }

                if (j < extraSpace)
                {
                    s += " ";
                }
            }

            // Insert space to the right of last line.
            if (next == n)
            {
                string b(maxWidth - s.size(), ' ');
                s += b;
            }

            res.push_back(s);
            i = next;
        }

        return res;
    }
};

int main()
{
    Solution sln;
    int maxWidth = 1;
    //int maxWidth = 12;
    //cout << "Please enter maxWidth: ";
    //cin >> maxWidth;
    //const vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    //const vector<string> words = {"a", "b", "c", "d", "e"};
    const vector<string> words = {"a"};
    //const vector<string> words = {};
    //const vector<string> words = {""};
    //const vector<string> words = {"What", "must", "be", "shall", "be."};
    vector<string> v = sln.fullJustify(words, maxWidth);

    for (auto &s : v)
    {
        cout << s << endl;
    }

    return 0;
}
