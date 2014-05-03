#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include "Graph.h"
#include "NormalData.h"

using namespace std;

static int idx = 0;
static stack<int> S;
static set<int> visitedSet;
static map<int, int> indexMap;
static map<int, int> lowLinkMap;
static deque<int> Q;
#ifdef MULTI_MAP
    static multimap<int, int> G;
#else
    static map<int, vector<int> > G;
#endif

static void strongConnect(int v)
{
    indexMap.insert(pair<int, int>(v, idx));
    lowLinkMap.insert(pair<int, int>(v, idx));
#ifdef DEBUG
    cout << "insert node " << v << ", index " << idx << " into indexMap!" << endl;
    cout << "insert node " << v << ", index " << idx << " into lowLinkMap!" << endl;
#endif
    idx++;
    visitedSet.insert(v);
    vector<int> tmp = G[v];
    S.push(v);
    int *tail = &S.top() + 1;
    int *start = tail - S.size();
    vector<int> stackContent(start, tail);
#ifdef DEBUG
    cout << "stack contents: ";
    for_each(stackContent.begin(), stackContent.end(), printFunc<int>);
    cout << endl;
#endif

    for (vector<int>::iterator itr = tmp.begin(); itr != tmp.end(); ++itr)
    {
        if (visitedSet.find(*itr) == visitedSet.end())
        {
            strongConnect(*itr);
            lowLinkMap[v] = min(lowLinkMap[v], lowLinkMap[*itr]);
        }
        else if (find(stackContent.begin(), stackContent.end(), *itr) != stackContent.end())
        {
            lowLinkMap[v] = min(lowLinkMap[v], indexMap[*itr]);
        }
    }

#ifdef DEBUG
    cout << "lowLinkMap[" << v << "] = " << lowLinkMap[v] << endl;
    cout << "indexMap[" << v << "] = " << indexMap[v] << endl;
#endif

    map<int, int>::iterator itrIndex = indexMap.find(v);
    map<int, int>::iterator  itrLowLink= lowLinkMap.find(v);

    if (itrIndex != indexMap.end() &&
        itrLowLink != lowLinkMap.end() &&
        *itrIndex ==  *itrLowLink)
    {
        cout << "{ ";
        int w = -1;

        do
        {
            w = S.top();
            cout << w << " ";
            S.pop();
        } while (w != v && !S.empty());

        cout << "}" << endl;
    }
}

void tarjan()
{
    for (map<int, vector<int> >::iterator itr = G.begin(); itr != G.end(); ++itr)
    {
        if (visitedSet.find(itr->first) == visitedSet.end())
        {
            strongConnect(itr->first);
        }
    }
}

static void DFS_VISIT(int u)
{
    vector<int> adj = G[u];
    visitedSet.insert(u);

    for (vector<int>::iterator itr = adj.begin(); itr != adj.end(); ++itr)
    {
        if (visitedSet.find(*itr) == visitedSet.end())
        {
            DFS_VISIT(*itr);
        }
    }

#ifdef DEBUG
    cout << u << " ";
#endif
    Q.push_front(u);
}

// DFS search the whole graph
void DFS()
{
    for (map<int, vector<int> >::iterator itr = G.begin(); itr != G.end(); ++itr)
    {
        if (visitedSet.find(itr->first) == visitedSet.end())
        {
            DFS_VISIT(itr->first);
        }
    }

    cout << endl;
}

// BFS search a graph from start node s
void BFS(int s)
{
    Q.push_back(s);
    visitedSet.insert(s);

    while (!Q.empty())
    {
        int u = Q.front();
        cout << u << " ";
        Q.pop_front();

        vector<int> adj = G[u];

        for (vector<int>::iterator itr2 = adj.begin(); itr2 != adj.end(); ++itr2)
        {
            if (visitedSet.find(*itr2) == visitedSet.end())
            {
                Q.push_back(*itr2);
                visitedSet.insert(*itr2);
            }
        }
    }

    cout << endl;
}

void TopologicalSort()
{
    DFS();

    cout << "Topological Soring: " << endl;

    for (deque<int>::iterator itr = Q.begin(); itr != Q.end(); ++itr)
    {
        cout << *itr << " ";
    }

    cout << endl;
}

#ifndef EXPORTED
int main()
{
    for (int i = 0; i < 14; ++i)
    {
#ifdef MULTI_MAP
        G.insert(pair<int, int>(GArray[i][0], GArray[i][1]));
#else
        G[GArray[i][0]].push_back(GArray[i][1]);
#endif
    }

#ifdef MULTI_MAP
    for (multimap<int, int>::iterator itr = G.begin(); itr != G.end(); ++itr)
    {
        cout << itr->first << " => " << itr->second << endl;
    }
#else
    for (map<int, vector<int> >::iterator itr = G.begin(); itr != G.end(); ++itr)
    {
        cout << "Node " << itr->first << " is connected to: ";
        vector<int> tmp = itr->second;
        for_each(tmp.begin(), tmp.end(), printFunc<int>);
        cout << endl;
    }
#endif

//    tarjan();
//    DFS();
//    TopologicalSort();
//
    // here we manually search graph from node 1
    BFS(1);

    return 0;
}
#endif
