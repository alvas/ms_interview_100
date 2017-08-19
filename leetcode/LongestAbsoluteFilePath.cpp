#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    template <typename T>
        void split(const std::string &s, char delim, T result) {
            std::istringstream ss(s);
            //ss.str(s);
            std::string item;

            while (std::getline(ss, item, delim)) {
                *(result++) = item;
            }
        }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }

    int lengthLongestPath(string input) {
        // this can split words, but it also remove '\t'
        //std::istringstream iss(input);
        //vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
        //
        int res = 0;
        vector<string> tokens = split(input, '\n');
        stack<int> stk;
        stk.push(0);

        for (auto t: tokens) {
            int lev = t.find_last_of('\t') + 1; // num of '\t'

            while (lev + 1 < stk.size())  // find parent
                stk.pop();

            int len = stk.top() + t.size() - lev + 1; // remove '\t', add '/'
            stk.push(len);

            if (t.find('.') != std::string::npos)
                res = max(res, len - 1);
        }

        return res;
    }

    int lengthLongestPath1(string input) {
        int sz = input.size();
        vector<int> len;
        int i = 0, res = 0, prevIdx = 0, curLevel = 0;
        bool isFile = false;

        for ( ; i < sz; ) {
            if (input[i] == '\n') {
                while (len.size() > curLevel) {
                    len.pop_back();
                }

                int curLen = i - prevIdx;
                len.push_back(curLen);

                if (isFile) {
                    int pathLen = std::accumulate(len.begin(), len.end(), 0);
                    pathLen += len.size() - 1;
                    res = max(res, pathLen);
                }

                isFile = false;
                i++;

                if (input[i] == '\t')
                {
                    curLevel = 0;

                    while (i < sz && input[i] == '\t') {
                        i++;
                        curLevel++;
                    }

                    prevIdx = i;
                }
                else
                {
                    len.clear();
                    prevIdx = i;
                }
            }
            else
            {
                if (input[i] == '.')
                {
                    isFile = true;
                }

                i++;
            }
        }

        if (isFile) {
            while (len.size() > curLevel) {
                len.pop_back();
            }

            int pathLen = std::accumulate(len.begin(), len.end(), 0);
            pathLen += len.size() + sz - prevIdx;
            res = max(res, pathLen);
        }

        return res;
    }
};

int main()
{
    Solution sln;
    //string input("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    string input("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
    //string input("a.txt");
    //string input("dir\n    file.txt"); // 12
    //string input("dir\n        file.txt"); // 16
    //string input("file name with  space.txt");
    //string input("dir\n\t        file.txt\n\tfile2.txt"); // 20
    //string input("a\n\tb.txt\na2\n\tb2.txt"); // 9
    cout << sln.lengthLongestPath(input) << endl;
    return 0;
}
