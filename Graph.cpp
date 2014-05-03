#include <iostream>
#include <map>
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
#ifdef MULTI_MAP
    static multimap<int, int> graph;
#else
    static map<int, vector<int> > graph;
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
    vector<int> tmp = graph[v];
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
    for (map<int, vector<int> >::iterator itr = graph.begin(); itr != graph.end(); ++itr)
    {
        if (visitedSet.find(itr->first) == visitedSet.end())
        {
            strongConnect(itr->first);
        }
    }
}

#ifndef EXPORTED
int main()
{
    int a[14][2] = {{1, 2}, {2, 3}, {3, 1}, {4, 2}, 
                    {4, 3}, {4, 5}, {5, 4}, {5, 6}, 
                    {6, 3}, {6, 7}, {7, 6}, {8, 5}, 
                    {8, 7}, {8, 8}};


    for (int i = 0; i < 14; ++i)
    {
#ifdef MULTI_MAP
        graph.insert(pair<int, int>(a[i][0], a[i][1]));
#else
        graph[a[i][0]].push_back(a[i][1]);
#endif
    }

#ifdef MULTI_MAP
    for (multimap<int, int>::iterator itr = graph.begin(); itr != graph.end(); ++itr)
    {
        cout << itr->first << " => " << itr->second << endl;
    }
#else
    for (map<int, vector<int> >::iterator itr = graph.begin(); itr != graph.end(); ++itr)
    {
        cout << "Node " << itr->first << " is connected to: ";
        vector<int> tmp = itr->second;
        for_each(tmp.begin(), tmp.end(), printFunc<int>);
        cout << endl;
    }
#endif

    tarjan();

    return 0;
}
#endif
