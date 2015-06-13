#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<vector<int> > v(sz1 + 1, vector<int>(sz2 + 1, 0));

        for (int i = 0; i <= sz2; ++i)
        {
            v[0][i] = i;
        }

        for (int i = 0; i <= sz1; ++i)
        {
            v[i][0] = i;
        }

        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    v[i][j] = v[i - 1][j - 1];
                }
                else
                {
                    v[i][j] = min(v[i - 1][j] + 1, min(v[i][j - 1] + 1, v[i - 1][j - 1] + 1));
                }
            }
        }

        return v[sz1][sz2];
    }

    int minDistance_recursive(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        int dis = distance(word1, sz1, 0, word2, sz2, 0, 0);
        return dis;
    }

    int distance(string &w1, int sz1, int start1, string &w2, int sz2, int start2, int val)
    {
        if (start1 >= sz1)
        {
            val += sz2 - start2;
            return val;
        }
        else if (start2 >= sz2)
        {
            val += sz1 - start1;
            return val;
        }

        if (w1[start1] == w2[start2])
        {
            return distance(w1, sz1, start1 + 1, w2, sz2, start2 + 1, val);
        }
        else
        {
            int v1 = 0, v2 = 0, v3 = 0;

            v1 = distance(w1, sz1, start1, w2, sz2, start2 + 1, val + 1);
            v2 = distance(w1, sz1, start1 + 1, w2, sz2, start2, val + 1);
            v3 = distance(w1, sz1, start1 + 1, w2, sz2, start2 + 1, val + 1);

            return min(v1, min(v2, v3));;
        }
    }
};

int main()
{
    Solution sln;
    string w1("dinitrophenylhydrazine"), w2("acetylphenylhydrazine");
    //cout << "Please enter w1: ";
    //cin >> w1;
    //cout << "Please enter w2: ";
    //cin >> w2;
    cout << sln.minDistance(w1, w2) << endl;
    return 0;
}
