#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1, m2; 

        for (char c: magazine) {
            ++m2[c];
        }

        for (char c: ransomNote) {
            if (--m2[c] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sln;
    //string note("a"), mag("b");
    //string note("aa"), mag("ab");
    string note("aa"), mag("aab");
    cout << sln.canConstruct(note, mag) << endl;
    return 0;
}
