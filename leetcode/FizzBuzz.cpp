#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        for (int i = 1; i <= n; ++i) {
            int a = i % 3, b = i % 5;
            
            if (!a && !b) {
                res.push_back("FizzBuzz");
            }
            else if (!a) {
                res.push_back("Fizz");
            }
            else if (!b) {
                res.push_back("Buzz");
            }
            else {
                res.push_back(to_string(i));
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    int n = 15;
    vector<string> v = sln.fizzBuzz(n);
    printVector<string>(v);
    return 0;
}
