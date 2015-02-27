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

        // This only works for white space token.
        //copy(istream_iterator<string>(str1), istream_iterator<string>(), back_inserter(token1));
        //copy(istream_iterator<string>(str2), istream_iterator<string>(), back_inserter(token2));

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

int main()
{
    Solution sln;
    string v1, v2;
    cin >> v1;
    cin >> v2;
    cout << sln.compareVersion(v1, v2) << endl;
    return 0;
}
