#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int len = 0;

        for (auto a: s) {
            m[a]++;
        }

        bool hasOddCount = false;

        for (int i = 'a'; i <= 'z'; ++i) {
            if (m[i] & 1) {
                len += m[i] - 1;
                hasOddCount = true;
            }
            else {
                len += m[i];
            }
        }

        for (int i = 'A'; i <= 'Z'; ++i) {
            if (m[i] & 1) {
                len += m[i] - 1;
                hasOddCount = true;
            }
            else {
                len += m[i];
            }
        }

        if (hasOddCount) {
            len++;
        }

        return len;
    }
};

int main() {
    Solution sln;
    //string s("abccccdd");
    string s("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    cout << sln.longestPalindrome(s) << endl;
    return 0;
}
