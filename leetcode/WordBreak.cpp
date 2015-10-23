#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    // DP
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty())
        {
            return false;
        }

        // !! Pitfall !! don't use index vector, because it needs to depends on the previous value
        int size = s.size();
        // vector v indicates that whether all characters before and include v[i] can be broken into words.
        vector<bool> v(size + 1, false);

        for (int i = 1; i <= size; ++i)
        {
            for (int j = i; j > 0; --j)
            {
                // Be careful about the index and length here!
                string str = s.substr(j - 1, i - j + 1);

                // Be careful about the condition that when the first true value is set and the previous value
                // v[j - 1] || j == 1
                v[i] = (wordDict.find(str) != wordDict.end()) && (v[j - 1] || j == 1);

                if (v[i])
                {
                    break;
                }
            }
        }

        return v[size];
    }
    
    // This solution has performance problem. Time Limit Exceeded.
    // test data: 
    /*
     * "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
     * "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaa", "aaaaaaaaaaaa", "aaaaaaaaaaaaa"
     */
    bool wordBreak_naive(string s, unordered_set<string>& wordDict) {
        if (s.empty())
        {
            return false;
        }

        int size = s.size();
        pair<int, int> p(0, 1);
        stack<pair<int, int> > stk;
        stk.push(p);
        string::iterator itr1 = s.begin();
        unordered_set<string>::iterator itr2 = wordDict.end();

        while (!stk.empty())
        {
            p = stk.top();
            string str(itr1 + p.first, itr1 + p.second);

            if (wordDict.find(str) != itr2)
            {
                if (p.second == size)
                {
                    return true;
                }
            }

            p.first = p.second;
            p.second++;

            if (p.second <= size)
            {
                stk.push(p);
            }
            else
            {
                while (!stk.empty())
                {
                    p = stk.top();
                    stk.pop();
                    p.second++;

                    if (p.second <= size)
                    {
                        stk.push(p);
                        break;
                    }
                }
            }
        }
        
        return false;
    }
};

int main()
{
    Solution sln;

    //string s1("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
 
    string s1("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    // This uses unordered_set initialier list which needs c++11 support
    // g++ -std=c++11 WordBreak.cpp
    unordered_set<string> dict1({"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaa", "aaaaaaaaaaaa", "aaaaaaaaaaaaa"});


/*
    string s;
    std::cout << "Please enter your string: ";
    getline(cin, s);


    unordered_set<string> dict;

    string w;
    std::cout << "Please enter your word: ";
    getline(cin, w);

    while (!w.empty())
    {
        dict.insert(w);
        std::cout << "Please enter your word: ";
        getline(cin, w);
    }
*/

    //std::cout << sln.wordBreak_naive(s, dict) << endl;
    //std::cout << sln.wordBreak(s, dict) << endl;
    std::cout << sln.wordBreak(s1, dict1) << endl;
    return 0;
}
