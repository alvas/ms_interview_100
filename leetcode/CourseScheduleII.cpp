#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Need to improve.
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> v;
        int n = prerequisites.size();

        // I code several special case but made several error in this algorithm.
        if (n <= 0)
        {
            // 3, []; there are 3 classes, but not order dependency.
            for (int i = 0; i < numCourses; ++i)
            {
                v.push_back(i);
            }

            return v;
        }
        else if (numCourses <= 0)
        {
            return v;
        }
        else if (n == 1 && numCourses == 2)
        {
            v.push_back(prerequisites[0].second);
            v.push_back(prerequisites[0].first);
            return v;
        }
        //else if (n >= numCourses * (numCourses - 1))
        //{
            //return v;
        //}

        vector<vector<bool> > d(numCourses, vector<bool>(numCourses, false));

        for (int i = 0; i < n; ++i)
        {
            pair<int, int> &p = prerequisites[i];

            if (p.second == p.first)
            {
                return v;
            }

            d[p.second][p.first] = true;
        }

        map<int, int> m;
        bool possible = true;
        int c = numCourses - 1;

        for (int i = 0; i < numCourses && possible; ++i)
        {
            if (m.find(i) != m.end())
            {
                continue;
            }

            set<int> s;
            possible = TopologicalSort(d, numCourses, i, m, s, c, v);
        }

        if (!possible || c >= 0)
        {
            v.clear();
            return v;
        }

        reverse(v.begin(), v.end());
        return v;
    }

    bool TopologicalSort(vector<vector<bool> > &g, int n, int j, map<int, int> &m, set<int> &s, int &c, vector<int> &v)
    {
        bool possible = true;

        s.insert(j);

        for (int i = 0; i < n && possible; ++i)
        {
            if (g[j][i] == false)
            {
                continue;
            }
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
                possible = TopologicalSort(g, n, i, m, s, c, v);
            }
        }

        if (possible)
        {
            m.insert(make_pair(j, c--));
            v.push_back(j);
        }

        return possible;
    }
};

int main()
{
    Solution sln;
    int num = 3;
    //std::cout << "Please enter num of courses: ";
    //cin >> num;
    //int a[4][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    //int a[1][2] = {{1, 0}};
    int a[3][2] = {{1, 0}, {0, 2}, {1, 2}};
    vector<pair<int, int> > pre;

    for (int i = 0; i < SIZE(a); ++i)
    {
        pre.push_back(make_pair(a[i][0], a[i][1]));
    }

    vector<int> v = sln.findOrder(num, pre);
    printVector<int>(v);
    return 0;
}
