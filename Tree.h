#ifndef TREE_H
#define TREE_H
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), parent(NULL), left(NULL), right(NULL) {}
};

class TreeLinkNode
{
public:
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


void ReBuildTreeFromPreIn(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromPreIn2(int *preOrder, int *inOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromPrePost(int *preOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromPrePost2(int *preOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromInPost(int *inOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void ReBuildTreeFromInPost2(int *inOrder, int *postOrder, int nTreeLen, TreeNode *&root);
void BuildOrderLevelVector(TreeNode * const root, vector<string> &v);
void CleanUp(TreeNode *&root);
void printTreePreorder(TreeNode *root);

// Deserialization
template<typename T>
void ReBuildTreeFromOrderLevel(T *&root, const vector<string> &s)
{
    int size = s.size();
    
    if (size == 0 || s[0] == "#")
    {
        root = NULL;
    }

    queue<T *> q;
    root = new T(atoi(s[0].c_str()));
    q.push(root);
    cout << "Creating node : " << root->val << endl;

    for (int i = 1; i < size; )
    {
        if (!q.empty())
        {
            T *node = q.front();
            q.pop();

            if (i < size)
            {
                if (s[i] == "#")
                {
                    cout << "left leaf child of " << node->val << " is empty leaf #!" << endl;
                }
                else
                {
                    T *tmp = new T(atoi(s[i].c_str()));
                    q.push(tmp);

                    node->left = tmp;
                    cout << "Creating node : " << tmp->val << " for as left child of " << node->val << endl;
                }
            }

            i++;

            if (i < size)
            {
                if (s[i] == "#")
                {
                    cout << "right leaf child of " << node->val << " is empty leaf #!" << endl;
                }
                else
                {
                    T *tmp = new T(atoi(s[i].c_str()));
                    q.push(tmp);

                    node->right = tmp;
                    cout << "Creating node : " << tmp->val << " for as left child of " << node->val << endl;
                }
            }

            i++;
        }
    }
}

template<typename T>
void CleanUp2(T *&root)
{
    if (root == NULL)
    {
        return;
    }

    queue<T *> q;
    q.push(root);

    while (!q.empty())
    {
        T *p = q.front();
        q.pop();

        if (p->left != NULL)
        {
            q.push(p->left);
        }

        if (p->right != NULL)
        {
            q.push(p->right);
        }

        //cout << "Freeing node: " << p->val << endl;
        delete p;
    }
}

#endif
