#include <iostream>

#include "Graph.h"

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
        {
            return NULL;
        }

        UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> q;
        map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        q.push(node);
        m.insert(make_pair(node, head));

        while (!q.empty())
        {
            UndirectedGraphNode *t = q.front();
            q.pop();
            vector<UndirectedGraphNode *> v = t->neighbors;
            map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator itr = m.find(t);
            UndirectedGraphNode *ct = itr->second;

            // Pitfall!!. This is very important. We need to use reference here in order to add value to the vector. If don't use reference, it would copy a vector and only add value to the copy. The clone graph is not touched.
            vector<UndirectedGraphNode *> &cv = ct->neighbors;

            for (vector<UndirectedGraphNode *>::iterator vitr = v.begin();
                vitr != v.end(); ++vitr)
            {
                UndirectedGraphNode *nt = *vitr;
                map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator nmitr = m.find(nt);
                
                if (nmitr != m.end())
                {
                    cv.push_back(nmitr->second);
                }
                else
                {
                    UndirectedGraphNode *cnt = new UndirectedGraphNode(nt->label);
                    cv.push_back(cnt);
                    q.push(nt);
                    m.insert(make_pair(nt, cnt));
                }
            }
        }

        return head;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 9;
    string s[LOCAL_LENGTH] = {"0", "1", "2", "#", "1", "2", "#", "2", "2"};
    vector<string> vs(s, s + LOCAL_LENGTH);
    UndirectedGraphNode *g = NULL;
    createUndirectedGraph(g, vs);
    UndirectedGraphNode *cg = sln.cloneGraph(g);
    printUndirectedGraph(cg);
    destroyUndirectedGraph(g);
    destroyUndirectedGraph(cg);
    return 0;
}
