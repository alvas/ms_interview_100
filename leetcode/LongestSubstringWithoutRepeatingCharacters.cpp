#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    // Need to improve.
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();

        if (sz == 0)
        {
            return 0;
        }

        int len = 0, maxL = 0, rpIdx = 0;
        map<char, int> m;

        for (int i = 0; i < sz; ++i)
        {
            char c = s[i];
            map<char, int>::iterator itr = m.find(c);

            if (itr != m.end())
            {
                // be careful about the index m[c] + 1
                rpIdx = m[c] + 1;
            }

            m[c] = i;

            // be careful about the length, i - rpIdx + 1
            maxL = max(maxL, i - rpIdx + 1);
        }

        //for (int i = 0; i < sz; ++i)
        //{
            //char c = s[i];
            //map<char, int>::iterator itr = m.find(c);

            //if (itr == m.end())
            //{
                ////m.insert(make_pair(c, i));
                //m.insert({c, i});
                //len++;
            //}
            //else
            //{
                //int idx = itr->second;
                //m[c] = i;

                //if (idx < rpIdx)
                //{
                    //len++;
                //}
                //else
                //{
                    //len = i - idx;
                    //rpIdx = idx;
                //}
            //}

            //maxL = max(maxL, len);
        //}

        return maxL;
    }
};

int main()
{
    Solution sln;
    //string s("abcabcbb");
    string s("bbb");
    //string s("");
    //string s("a");
    std::cout << sln.lengthOfLongestSubstring(s) << endl;
    return 0;
}
