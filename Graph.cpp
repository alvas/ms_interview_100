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
    static multimap<int, int> GT;
#else
    static map<int, vector<int> > G;
    static map<int, vector<int> > GT;
#endif

Graph::~Graph()
{
    for (vector<Edge *>::iterator itr = E.begin(); itr != E.end(); ++itr)
    {
        Edge *e = *itr;
        delete e;
    }

    for (vector<Vertex *>::iterator itr = V.begin(); itr != V.end(); ++itr)
    {
        Vertex *v = *itr;
        delete v;
    }
}

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
    vector<int> adj = G[v];
    S.push(v);
    int *tail = &S.top() + 1;
    int *start = tail - S.size();
    vector<int> stackContent(start, tail);
#ifdef DEBUG
    cout << "stack contents: ";
    for_each(stackContent.begin(), stackContent.end(), printFunc<int>);
    cout << endl;
#endif

    for (vector<int>::iterator itr = adj.begin(); itr != adj.end(); ++itr)
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

static void InitializeGraph(int a[14][2])
{
    for (int i = 0; i < 14; ++i)
    {
#ifdef MULTI_MAP
        G.insert(pair<int, int>(a[i][0], a[i][1]));
#else
        G[a[i][0]].push_back(a[i][1]);
#endif
    }
}

#if 0
static void TransposeGraph(int a[14][2])
{
    for (int i = 0; i < 14; ++i)
    {
#ifdef MULTI_MAP
        GT.insert(pair<int, int>(a[i][1], a[i][0]));
#else
        GT[a[i][1]].push_back(a[i][0]);
#endif
    }
}
#endif

static void TransposeGraph(const map<int, vector<int> > &graph)
{
    for (map<int, vector<int> >::const_iterator itr = graph.begin(); itr != graph.end(); ++itr)
    {
        vector<int> adj = itr->second;

        for (vector<int>::iterator itr2 = adj.begin(); itr2 != adj.end(); ++itr2)
        {
            GT.insert(pair<int, int>(*itr2, itr->first));
        }
    }
}

static void printGraph(const map<int, vector<int> > &graph)
{
#ifdef MULTI_MAP
//    for (multimap<int, int>::iterator itr = G.begin(); itr != G.end(); ++itr)
//    {
//        cout << itr->first << " => " << itr->second << endl;
//    }
#else
    for (map<int, vector<int> >::const_iterator itr = G.begin(); itr != G.end(); ++itr)
    {
        cout << "Node " << itr->first << " is connected to: ";
        vector<int> adj= itr->second;
        for_each(adj.begin(), adj.end(), printFunc<int>);
        cout << endl;
    }
#endif
}

static void printVertex(const Vertex *v)
{
    cout << "id = " << v->id << "; d = " << v->d << endl;
}

static void printEdge(const Edge *e)
{
    cout << e->u->id << " -->(" << e->w << ") " << e->v->id << endl; 
}

struct VertexCmp
{
    VertexCmp(int idValue): id(idValue) {}
    VertexCmp() {}
    bool operator () (const Vertex *v) const { return v->id == id; }
    bool operator() (const Vertex *v, const Vertex *u) const { return u->d < v->d; }
    int id;
};

static void InitializeGraph(Graph &g, int numVertex, int w[][G_V1])
{
    for (int i = 0; i < numVertex; ++i)
    {
        Vertex *v = new Vertex();
        g.V.push_back(v);
    }

#ifdef DEBUG
    for_each(g.V.begin(), g.V.end(), printVertex);
#endif

    for (int i = 0; i < numVertex; ++i)
    {
        for (int j = 0; j < numVertex; ++j)
        {

            VertexCmp u1(i);
            vector<Vertex *>::iterator uItr = find_if(g.V.begin(), g.V.end(), u1);
            VertexCmp v1(j);
            vector<Vertex *>::iterator vItr = find_if(g.V.begin(), g.V.end(), v1);

//            Vertex u1(i);
//            vector<Vertex>::iterator uItr = find(g.V.begin(), g.V.end(), u1);
//            Vertex v1(j);
//            vector<Vertex>::iterator vItr = find(g.V.begin(), g.V.end(), v1);

//            vector<Vertex>::iterator uItr = FindVertex(g, i);
//            vector<Vertex>::iterator vItr = FindVertex(g, j);

            if (uItr != g.V.end() && vItr != g.V.end() && w[i][j] != 0)
            {
                Edge *e = new Edge(*uItr, *vItr, w[i][j]);
                g.E.push_back(e);
            }
        }
    }

#ifdef DEBUG
    for_each(g.E.begin(), g.E.end(), printEdge);
#endif
}

static void INITIALIZE_SINGLE_SOURCE(Graph &g, Vertex *s)
{
    for (vector<Vertex *>::iterator itr = g.V.begin(); itr != g.V.end(); ++itr)
    {
        Vertex *v = *itr;
        
        if (v != NULL)
        {
            v->d = numeric_limits<int>::max();
            v->pi = NULL;
        }
    }

    s->d = 0;
}

static void RELAX(Vertex *u, Vertex *v, int w[][G_V1])
{
    if (u->d != numeric_limits<int>::max() &&
        v->d > (u->d + w[u->id][v->id]))
    {
        v->d = u->d + w[u->id][v->id];
        v->pi = u;
    }
}

bool BELLMAN_FORD(Graph &g, int w[][G_V1], Vertex *s)
{
    INITIALIZE_SINGLE_SOURCE(g, s);

#ifdef DEBUG
    for_each(g.V.begin(), g.V.end(), printVertex);
#endif

    for (int i = 1; i < g.V.size(); ++i)
    {
        for (vector<Edge *>::iterator itr = g.E.begin(); itr != g.E.end(); ++itr)
        {
            Edge *e = *itr;

            if (e != NULL)
            {
                RELAX(e->u, e->v, w);
            }
        }
    }

    for (vector<Edge *>::iterator itr = g.E.begin(); itr != g.E.end(); ++itr)
    {
        Edge *e = *itr;

        if (e != NULL && 
            e->u->d > (e->u->d + w[e->u->id][e->v->id]))
        {
            return false;
        }
    }

    return true;
}

void Dijkstra(Graph &g, int w[][G_V1], Vertex *s)
{
    INITIALIZE_SINGLE_SOURCE(g, s);
//    set<Vertex *> S;
    priority_queue<Vertex *, vector<Vertex *>, VertexCmp> Q(g.V.begin(), g.V.end());

    while (!Q.empty())
    {
        Vertex *u = (Q.top());
        Q.pop();
//        S.insert(u);

        vector<Vertex *> adj = FindAdj(g, u);

        for (vector<Vertex *>::iterator itr = adj.begin(); itr != adj.end(); ++itr)
        {
            RELAX(u, (*itr), w);
        }
    }
}

//EXTEND_SHORTEST_PATHS
//
//SLOW_ALL_PAIRS_SHORTEST_PATHS
//
//FASTER_ALL_PAIRS_SHORTEST_PATHS
//
//FLOYD_WARSHALL
//
//TRANSITIVE_CLOSURE
//
//JOHNSON
//
//FORD_FULKERSON
//

#ifndef EXPORTED
int main()
{
//    InitializeGraph(GArray);
//    printGraph(G);
//    TransposeGraph(G);
//    printGraph(GT);
//    tarjan();
//    DFS();
//    TopologicalSort();
//
    // here we manually search graph from node 1
//    BFS(1);

    Graph g;
    InitializeGraph(g, G_V1, W);
    vector<Vertex *>::iterator sItr = FindVertex(g, 0);
    
    if (sItr != g.V.end())
    {
//        cout << BELLMAN_FORD(g, W, *sItr) << endl;

        Dijkstra(g, W, *sItr);
        for_each(g.V.begin(), g.V.end(), printVertex);
        cout << endl;
    }

    return 0;
}
#endif
