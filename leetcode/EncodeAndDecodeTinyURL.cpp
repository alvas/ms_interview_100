#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string subUrl = getUrl(longUrl);
        auto v = hash<string>{}(subUrl);
        m[v] = subUrl;
        string res = to_string(v);
        auto pos = longUrl.find("//") + 2;
        return longUrl.replace(longUrl.begin() + pos, longUrl.end(), res);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto v = stoul(getUrl(shortUrl));
        string res = m[v];
        auto pos = shortUrl.find("//") + 2;
        return shortUrl.replace(shortUrl.begin() + pos, shortUrl.end(), res);
    }

    string getUrl(string url) {
        auto pos = url.find("//");
        return url.substr(pos + 2);
    }

private:
    map<int, string> m;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
//
int main()
{
    Solution sln;
    string longUrl("https://leetcode.com/problems/design-tinyurl");
    cout << sln.encode(longUrl) << endl;
    cout << sln.decode(sln.encode(longUrl)) << endl;
    return 0;
}
