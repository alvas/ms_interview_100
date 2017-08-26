#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    //int countComponents(int n, vector<pair<int, int>>& edges) {
    //}

    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ans = n;
        vector<int> node(n, -1);

        for (auto e: edges) {
            int idx1 = e.first, idx2 = e.second;
            // be careful about overwriting the value
            if (node[idx1] == -1) {
                node[idx1] = idx1;
            }
            
            int value = node[idx1];

            if (node[idx2] == -1) {
                node[idx2] = value;
                ans--;
            }
            else {
                int value2 = node[idx2];

                if (value2 != value) {
                    for (int i = 0; i < n; ++i) {
                        // can't use node[idx2], because it would be overwirte. need to use saved value idx
                        if (node[i] == value2) {
                            node[i] = value;
                        }
                    }

                    ans--;
                }

            }
        }
        
        return ans;

        //set<int> s;

        //for (auto n: node) {
            //if (n == -1) {
                //ans++;
            //}
            //else if (s.count(n) == 0) {
                //s.insert(n);
                //ans++;
            //}
        //}

        //return ans;
    }
};

int main()
{
    Solution sln;
    int n = 4;
    //vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    //vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<pair<int, int>> edges = {{0, 1}, {2, 3}, {1, 2}};
    cout << sln.countComponents(n, edges) << endl;
    return 0;
}
