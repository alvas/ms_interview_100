#include <iostream>
#include <string>

using namespace std;

void reverse(string &s, std::string::iterator startIdx, std::string::iterator endIdx)
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
    
    std::string::iterator itr = s.begin();
    
    while (itr != s.end())
    {
        if (*itr != ' ')
        {
            ++itr;
        }
        else
        {
            std::string::iterator nextItr = itr + 1;
        
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

void reverseWords(string &s) {
    sanitizeSpace(s);
    
    std::string::iterator startIdx = s.begin();
    
    for (std::string::iterator itr = s.begin(); itr != s.end(); ++itr)
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

class Solution
{
public:
    string reverseWords(string &s) 
    {
        string reversedString;

    }
};

int main()
{
    Solution sln;

    cout << "Original sentence: " << sentence << endl;
    cout << "Reverse sentence: " << sln.reverseWrods(sentence) << endl;
}
