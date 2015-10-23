#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Can't figure out the solution at the begining. After check the tag, I know it is using divide-and-conquer
    vector<int> diffWaysToCompute(string input) {
        vector<int> r;
        string op("+-*");
        size_t found = input.find_first_of(op);

        if (found == string::npos)
        {
            r.push_back(atoi(input.c_str()));
        }
        else
        {
            while (found != string::npos)
            {
                char c = input[found];
                string s1 = input.substr(0, found);
                string s2 = input.substr(found + 1);
                vector<int> a = diffWaysToCompute(s1);
                vector<int> b = diffWaysToCompute(s2);

                for (vector<int>::iterator itr1 = a.begin(); itr1 != a.end(); ++itr1)
                {
                    for (vector<int>::iterator itr2 = b.begin(); itr2 != b.end(); ++itr2)
                    {
                        switch (c)
                        {
                            case '+':
                                {
                                    r.push_back(*itr1 + *itr2);
                                    break;
                                }
                            case '-':
                                {
                                    r.push_back(*itr1 - *itr2);
                                    break;
                                }
                            case '*':
                                {
                                    r.push_back(*itr1 * *itr2);
                                    break;
                                }
                            default:
                                {
                                    break;
                                }
                        }
                    }
                }

                found = input.find_first_of(op, found + 1);
            }
        }

        return r;
    }

    //vector<string> tokenize(const char *s, const char *tokens)
    //{
        //vector<string> r;
        //char *a = strtok(const_cast<char *>(s), tokens);

        //while (a != NULL)
        //{
            //string b(a);
            //r.push_back(b);
            //a = strtok(NULL, tokens);
        //}

        //return r;
    //}
};

int main()
{
    Solution sln;
    //string input("2-1-1");
    string input("2*3-4*5");
    //std::cout << "Please enter input: ";
    //cin >> input;
    vector<int> v = sln.diffWaysToCompute(input);
    printVector<int>(v);
    return 0;
}
