#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string val;
        int sz = path.size();
        
        if (sz == 0)
        {
            return val;
        }

        val.push_back(path[0]);

        for (int i = 1; i < sz; ++i) 
        { 
            char a = path[i];

            if (a != '.')
            {
                // skip "//"
                if (a == '/' && val.back() == '/')
                {
                    continue;
                }
                else
                {
                    // charactor
                    val.push_back(a);
                }
            }
            else
            {
                // "xx/./"
                // "xx/../"
                // "xx/..."
                // "xx/..hidden"
                if (i != sz - 1)
                {
                    int idx = i;
                    int len = 1;

                    while (i + 1 < sz && path[i + 1] != '/')
                    {
                        len++;
                        i++;
                    }

                    if (len == 1)
                    {
                        continue;
                    }
                    if (len == 2)
                    {
                        if (val.size() > 1 && val.back() == '/')
                        {
                            val.pop_back();
                        }

                        while (val.size() > 1 && val.back() != '/')
                        {
                            val.pop_back();
                        }
                    }
                    else
                    {
                        for (int j = 0; j < len; ++j)
                        {
                            val.push_back(path[idx + j]);
                        }
                    }

                }
                else
                {
                    // skip the last  point "xxxx/."
                }
            }
        }

        if (val.size() > 1 && val.back() == '/')
        {
            val.pop_back();
        }

        return val;
    }
};

int main()
{
    Solution sln;
    //string path("/");
    //string path("//");
    //string path("/../");
    //string path("/..hidden");
    //string path("/...");
    //string path("/home//foo/");
    //string path("/a/./b/../../c/");
    //string path("/../../../.");
    //string path("/a");
    //string path("/a/b/c");
    string path("/a/b/c/");
    cout << sln.simplifyPath(path) << endl;
    return 0;
}
