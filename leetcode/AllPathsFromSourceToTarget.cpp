/*
 * AllPathsFromSourceToTarget.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <queue>
#include <vector>

#include "UnitTest.h"
#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        queue<vector<int>> paths;
        paths.push({0});

        for (int i = 0; i < graph.size(); ++i) {
            int psz = paths.size();

            for (int k = 0; k < psz; ++k) {
                vector<int> path = paths.front();
                paths.pop();
                int idx = path.back();

                // this optimization save 4ms
                if (idx == graph.size() - 1) {
                    res.push_back(path);
                    continue;
                }

                for (int j = 0; j < graph[idx].size(); ++j) {
                    path.push_back(graph[idx][j]);
                    paths.push(path);
                    path.pop_back();
                }
            }
        }

        return res;
    }

    vector<vector<int>> allPathsSourceTarget1(vector<vector<int>>& graph) {
        vector<vector<int>> res = {{0}};
        int gsz = graph.size();

        for (int i = 0; i < gsz; ++i) {
            vector<vector<int>> tmp;
            int rsz = res.size();

            for (int j = 0; j < rsz; ++j) {
                int idx = res[j].back();

                if (idx == gsz - 1) {
                    tmp.push_back(res[j]);
                    continue;
                }

                vector<int> &nodes = graph[idx];
                vector<int> path = res[j];
                int nsz = nodes.size();

                for (int k = 0; k < nsz; ++k) {
                    path.push_back(nodes[k]);
                    tmp.push_back(path);
                    path.pop_back();
                }
            }

            tmp.swap(res);
        }

        return res;
    }
};

SUITE(TEST_CASES)
{
    class MyFixture
    {
    public:
        Solution sln;
    };

    TEST_FIXTURE(MyFixture, CASE1)
    {
        vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};
        vector<vector<int>> res = sln.allPathsSourceTarget(graph);
        print2DVector<int>(res);
        //CHECK_EQUAL(,);
    }
}

