#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    // Need to improve.
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        bool possible = true;
        int sz = prerequisites.size();
        vector<vector<bool> > g(numCourses, vector<bool>(numCourses));

        for (int i = 0; i < sz; ++i)
        {
            g[prerequisites[i].second][prerequisites[i].first] = true;
        }

        if (sz <= 1)
        {
            return possible;
        }

        map<int, int> m;
        int c = numCourses - 1;

        for (int i = 0; i < numCourses && possible; ++i)
        {
            if (m.find(i) != m.end())
            {
                continue;
            }

            set<int> s;
            possible = TopologicalSort(g, numCourses, i, m, s, c);
        }

        return possible && c < 0;
    }

    bool TopologicalSort(vector<vector<bool> > &g, int n, int j, map<int, int> &m, set<int> &s, int &c)
    {
        if (g[j][j] == true)
        {
            return false;
        }

        bool possible = true;
        // Be careful about the position where we insert the visiting node.
        s.insert(j);

        for (int i = 0; i < n && possible; ++i)
        {
            if (g[j][i] == false)
            {
                continue;
            }
            // Should do this before we check the node on path.
            else if (m.find(i) != m.end())
            {
                continue;
            }
            else if (s.find(i) != s.end())
            {
                return false;
            }
            else
            {
                possible = TopologicalSort(g, n, i, m, s, c);
            }
        }

        // Only need to insert it here.
        if (possible)
        {
            m.insert(make_pair(j, c--));
        }

        return possible;
    }
};

int main()
{
    Solution sln;
    int num = 0;
    std::cout << "Please enter num of courses: ";
    cin >> num;
    vector<pair<int, int> > pre;
    //pre.push_back(make_pair(1, 0));
    //pre.push_back(make_pair(0, 1));
    pre.push_back(make_pair(1, 0));
    //pre.push_back(make_pair(2, 0));
    pre.push_back(make_pair(0, 2));
    pre.push_back(make_pair(1, 2));
    std::cout << sln.canFinish(num, pre) << endl;
    return 0;
}
