#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> umap;
        int ans = 0, num = sentence.size();

        for (int i = 0; i < rows; ++i) {
            int start = ans % num;

            if (umap.count(start) == 0) {
                int cnt = 0, len = 0;

                for (int j = start; len < cols; j = (j + 1) % num, cnt++) {
                    if (len + sentence[j].size() > cols) {
                        break;
                    }

                    len += sentence[j].size() + 1;
                }

                ans += cnt;
                umap.emplace(start, cnt);
            }
            else {
                ans += umap[start];
            }
        }

        return ans / num;
    }

    int wordsTyping2(vector<string>& sentence, int rows, int cols) {
        int ans = 0;
        vector<int> num;
        std::transform(sentence.begin(), sentence.end(), std::back_inserter(num), [](string &s) { return s.size(); });
        int idx1 = 0, sz = num.size();

        for (int i = 0; i < rows; ++i) {
            int count = num[idx1];

            if (count <= cols) {
                // only increase idx1 here
                if (++idx1 == sz) {
                    idx1 = 0;
                }

                ans++;
            }

            while (count < cols) {
                count += num[idx1] + 1;

                if (count <= cols) {
                    // only increase idx1 here
                    if (++idx1 == sz) {
                        idx1 = 0;
                    }

                    ans++;
                }
            }
        }

        return ans / sz;
    }

    int wordsTyping1(vector<string>& sentence, int rows, int cols) {
        int ans = 0;
        int num = sentence.size();

        for (int i = 0; i < rows; ++i) {
            int count = sentence[ans % num].size();

            if (count <= cols) {
                ans++;
            }

            while (count < cols) {
                count += sentence[ans % num].size() + 1;

                if (count <= cols) {
                    ans++;
                }
            }
        }

        return ans / num;
    }
};

int main()
{
    Solution sln;
    //vector<string> sentence = {"hello", "world"};
    //int rows = 2, cols = 8;
    //vector<string> sentence = {"a", "bcd", "e"};
    //int rows = 3, cols = 6;
    //vector<string> sentence = {"I", "had", "apple", "pie"};
    //int rows = 4, cols = 5;
    //vector<string> sentence = {"f","p","a"};
    //int rows = 8, cols = 7;
    vector<string> sentence = {"a", "bc"};
    int rows = 20000, cols = 20000;
    //vector<string> sentence = {"try","to","be","better"};
    //int rows = 10000, cols = 9001;
    //cout << sln.wordsTyping1(sentence, rows, cols) << endl;
    cout << sln.wordsTyping(sentence, rows, cols) << endl;
    return 0;
}
