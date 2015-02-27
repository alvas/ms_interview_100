#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string str;
        int result = 0, num = 0;

        vector<int> token1, token2;
        istringstream str1(version1), str2(version2);

        // tokenize string and save tokens to a vector
        while (getline(str1, str, '.'))
        {
            num = atoi(str.c_str());
            token1.push_back(num);
        }

        while (getline(str2, str, '.'))
        {
            num = atoi(str.c_str());
            token2.push_back(num);
        }


        vector<int>::iterator itr1 = token1.begin(), itr2 = token2.begin();
        vector<int>::iterator end1 = token1.end(), end2 = token2.end();

        for ( ; itr1 != end1 && itr2 != end2; ++itr1, ++itr2)
        {
            if (*itr1 < *itr2)
            {
                result = -1;
                break;
            }
            else if (*itr1 > *itr2)
            {
                result = 1;
                break;
            }
        }

        
        // "1.0" and "1" are considered as same version.
        bool zero = true;

        if (itr1 == end1)
        {
            while (itr2 != end2)
            {
                if (*itr2 != 0)
                {
                    zero = false;
                    break;
                }

                // Don't forget move forward.
                ++itr2;
            }

            if (!zero)
            {
                result = -1;
            }
        }
        else if (itr2 == end2)
        {
            while (itr1 != end1)
            {
                if (*itr1 != 0)
                {
                    zero = false;
                    break;
                }

                // Don't forget move forward.
                ++itr1;
            }

            if (!zero)
            {
                result = 1;
            }
        }

        return result;
    }
};

void tokenize(const string &v1)
{
    vector<string> str1;
    boost::split(str1, v1, boost::is_any_of("."));

    // This only works for white space token.
    //copy(istream_iterator<string>(str1), istream_iterator<string>(), back_inserter(token1));
    
    for (const auto& i: str1)
    {
        cout << i << "\t";
    }

    cout << endl;

}

void tokenize2(const string &v1)
{
    boost::char_separator<char> sep(".");
    boost::tokenizer<boost::char_separator<char> > token1(v1, sep);

    for (const auto& t: token1)
    {
        cout << t << "\t";
    }

    cout << endl;
}

void tokenize3(const string &v1)
{
    vector<string> token1;

    size_t start = 0, pos = v1.find(".", start);

    while (pos != string::npos)
    {
        // 2nd parameter of substr is len, not end position.
        token1.push_back(v1.substr(start, pos - start));
        // Need to adjust the next start position.
        start = pos + 1;
        pos = v1.find(".", start);
    }

    token1.push_back(v1.substr(start, pos));

    for (const auto& t: token1)
    {
        cout << t << "\t";
    }

    cout << endl;
}

int main()
{
    Solution sln;
    string v1, v2;
    cin >> v1;
    //cin >> v2;
    //cout << sln.compareVersion(v1, v2) << endl;
    tokenize3(v1);
    return 0;
}
