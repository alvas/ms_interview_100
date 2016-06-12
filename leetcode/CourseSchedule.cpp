#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinishDFS(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> visit(numCourses, 0);

        for (auto a : prerequisites)
        {
            graph[a.second].push_back(a.second);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (!canFinishDFS(graph, visit, i))
            {
                return false;
            }
        }

        return true;
    }

    bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i)
    {
        if (visit[i] == -1)
        {
            return false;
        }

        // If the visited node is OK, then just return, don't waste time to traverse it again.
        if (visit[i] == 1)
        {
            return true;
        }

        visit[i] = -1;

        for (auto a : graph[i])
        {
            if (!canFinishDFS(graph, visit, a))
            {
                return false;
            }
        }

        // Set the successful visisted node to 1 to shotcut traverse
        visit[i] = 1;

        return true;
    }

    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);

        for (auto a : prerequisites)
        {
            graph[a.second].push_back(a.second);
            ++in[a.second];
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int t = q.front();
            q.pop();

            for (auto a : graph[t])
            {
                --in[a];

                if (in[a] == 0)
                {
                    q.push(a);
                }
            }
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i] != 0)
            {
                return false;
            }
        }

        return true;
    }

    // Need to improve.
    bool canFinish1(int numCourses, vector<pair<int, int> >& prerequisites) {
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
