#include <cassert>
#include <limits>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void createUndirectedGraph(UndirectedGraphNode *&g, const vector<string> &str)
{
    int size = str.size();
    bool newNode = true;
    UndirectedGraphNode *node = NULL;
    map<int, UndirectedGraphNode *> m;

    for (int i = 0; i < size; ++i)
    {
        // checking not '#' to avoid the case that the first character is #
        // and the case that multiple # stay together
        if (newNode && str[i] != "#")
        {
            int t = atoi(str[i].c_str());
            map<int, UndirectedGraphNode *>::iterator itr = m.find(t);

            // Be careful about here!!
            // When we can find the label from map, still remember to update the node.
            if (itr == m.end())
            {
                node = new UndirectedGraphNode(t);
                m.insert(make_pair(t, node));
            }
            else
            {
                node = itr->second;
            }

            newNode = false;

            if (i == 0)
            {
                g = node;
            }
        }
        else if (str[i] == "#")
        {
            newNode = true;
        }
        else
        {
            int t = atoi(str[i].c_str());
            map<int, UndirectedGraphNode *>::iterator itr = m.find(t);

            if (itr  == m.end())
            {
                UndirectedGraphNode *p = new UndirectedGraphNode(t);
                m.insert(make_pair(t, p));
                node->neighbors.push_back(p);
            }
            else
            {
                node->neighbors.push_back(itr->second);
            }
        }
    }
}

void printUndirectedGraph(UndirectedGraphNode * const g)
{
    if (g == NULL)
    {
        cout << "Graph is empty!" << endl;
        return;
    }

    queue<UndirectedGraphNode *> q;
    map<int, UndirectedGraphNode *> m;

    q.push(g);
    m.insert(make_pair(g->label, g));

    while (!q.empty())
    {
        UndirectedGraphNode *node = q.front();
        q.pop();
        cout << "node " << node->label << " has neighbors: " << endl;

        for (vector<UndirectedGraphNode *>::iterator itr = node->neighbors.begin();
            itr != node->neighbors.end(); ++itr)
        {
            if (m.find((*itr)->label) == m.end())
            {
                m.insert(make_pair((*itr)->label, *itr));
                q.push(*itr);
            }

            cout << (*itr)->label << "\t";
        }
        
        cout << endl;
    }
}

void destroyUndirectedGraph(UndirectedGraphNode *&g)
{
    if (g == NULL)
    {
        return;
    }

    queue<UndirectedGraphNode *> q;
    map<int, UndirectedGraphNode *> m;

    q.push(g);
    m.insert(make_pair(g->label, g));

    while (!q.empty())
    {
        UndirectedGraphNode *node = q.front();
        q.pop();

        for (vector<UndirectedGraphNode *>::iterator itr = node->neighbors.begin();
            itr != node->neighbors.end(); ++itr)
        {
            if (m.find((*itr)->label) == m.end())
            {
                m.insert(make_pair((*itr)->label, *itr));
                q.push(*itr);
            }
        }
        
        delete node;
    }

    g = NULL;
}

class Vertex 
{
    public:
        Vertex(): id(idCount++), d(numeric_limits<int>::max()), pi(NULL) {}
        Vertex(int idValue): id(idValue), d(0), pi(NULL) {}
        Vertex(Vertex &v1): id(v1.id), d(v1.d), pi(v1.pi) {}
        Vertex(const Vertex &v1): id(v1.id), d(v1.d), pi(v1.pi) {}
        // If we need to call find to compare Vertex in vector, we need
        // to override this method; Or use friend method.
//        bool operator == (const Vertex &v1) const { return id == v1.id; }
        friend bool operator== (const Vertex &u, const Vertex *v);
        friend bool operator< (const Vertex &u, const Vertex *v);
        friend bool operator<= (const Vertex &u, const Vertex *v);
        friend bool operator> (const Vertex &u, const Vertex *v);
        friend bool operator>= (const Vertex &u, const Vertex *v);

        int id;
        int d;
        Vertex *pi;

        static int idCount;
};

bool operator== (const Vertex &u, const Vertex &v) { return u.id == v.id; }
bool operator< (const Vertex &u, const Vertex &v) { return u.d < v.d; }
bool operator<= (const Vertex &u, const Vertex &v) { return u.d <= v.d; }
bool operator> (const Vertex &u, const Vertex &v) { return u.d > v.d; }
bool operator>= (const Vertex &u, const Vertex &v) { return u.d >= v.d; }

int Vertex::idCount = 0;

class Edge
{
    public:
        // Because we would modify the vertex which is binding to edge, we need
        // to use reference. If we use normal varialbe, it would create a copy.
        // The modification would not take effect on the real vertex itself.
        Edge(Vertex *u1, Vertex *v1, int weight): u(u1), v(v1), w(weight) {}

        Vertex *u, *v;
        int w;
};

class Graph
{
    public:
        vector<Vertex *> V;
        vector<Edge *> E;
        ~Graph();
};

const int G_M = 14;
const int G_N = 2;
const int G_V = 8;

int GArray[14][2] = 
{
    {1, 2}, {2, 3}, {3, 1}, {4, 2}, 
    {4, 3}, {4, 5}, {5, 4}, {5, 6}, 
    {6, 3}, {6, 7}, {7, 6}, {8, 5}, 
    {8, 7}, {8, 8}
};

vector<Vertex *>::iterator FindVertex(Graph &g, int idValue)
{
    vector<Vertex *>::iterator itr = g.V.begin();
    
    for (; itr != g.V.end(); ++itr)
    {
        if ((*itr)->id == idValue)
        {
            return itr;
        }
    }

    return itr;
}

vector<Vertex *> FindAdj(Graph &g, Vertex *u)
{
    vector<Vertex *> adj;

    for(vector<Edge *>::iterator itr = g.E.begin(); itr != g.E.end(); ++itr)
    {
        Edge *e = *itr;
        
        if (e->u == u)
        {
            adj.push_back(e->v);
        }
    }

    return adj;
}

const int G_V1 = 5;

int W[5][5] =
{
    {0, 3, 0, 5, 0},
    {0, 0, 6, 2, 0},
    {0, 0, 0, 0, 2},
    {0, 1, 4, 0, 6},
    {3, 0, 7, 0, 0}
};
