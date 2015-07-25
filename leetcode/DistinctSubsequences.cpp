#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int sz1 = s.size(), sz2 = t.size();

        if (sz1 == 0 || sz2 == 0)
        {
            return 0;
        }

        int num;
        return num;
    }

    int numDistinct_naive(string s, string t) {
        int sz1 = s.size(), sz2 = t.size();

        if (sz1 == 0 || sz2 == 0)
        {
            return 0;
        }

        int num = 0;
        find(s, 0, sz1, t, 0, sz2, num);
        return num;
    }

    void find(string &s, int i, int sz1, string &t, int j, int sz2, int &num)
    {
        if (i >= sz1)
        {
            if (j == sz2)
            {
                num++;
            }

            return;
        }
        else if (j >= sz2)
        {
            num++;
            return;
        }

        if (s[i] != t[j])
        {
            find(s, i + 1, sz1, t, j, sz2, num);
        }
        else
        {
            find(s, i + 1, sz1, t, j, sz2, num);
            find(s, i + 1, sz1, t, j + 1, sz2, num);
        }
    }
};

int main()
{
    Solution sln;
    //string s("rabbbit"), t("rabbit");
    //string s("ABCDE"), t("AEC");
    string s("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac"), t("ceadbaa");
    //cout << "Please enter S: " << endl;
    //cin >> s;
    //cout << "Please enter T: " << endl;
    //cin >> t;
    cout << sln.numDistinct_naive(s, t) << endl;
    cout << sln.numDistinct(s, t) << endl;
    return 0;
}
