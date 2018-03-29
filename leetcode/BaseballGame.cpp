#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> data;

        for (auto &o : ops) {
            if (o == "C") {
                if (!data.empty())
                    data.pop_back();
            }
            else if (o == "D") {
                if (!data.empty()) {
                    int sum = 2 * data.back();
                    data.push_back(sum);
                }
            }
            else if (o == "+") {
                if (data.size() > 1) {
                    int sum = data.back();
                    sum += data[data.size() - 2];
                    data.push_back(sum);
                }
            }
            else {
                data.push_back(stoi(o));
            }
        }

        return std::accumulate(data.begin(), data.end(), 0);
    }
};

int main()
{
    Solution sln;
    //vector<string> ops = {"5","2","C","D","+"};
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    cout << sln.calPoints(ops) << endl;
    return 0;
}
