#include <limits>

using namespace std;

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
