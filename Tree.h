#ifndef TREE_H
#define TREE_H
#include <queue>
#include <stack>
#include <vector>

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
void printTreeLinkOrderLevel(const TreeLinkNode *root);
TreeNode *findNodeInBST(TreeNode *root, int val);
TreeNode *findNodeInBT(TreeNode *root, int val);

// Deserialization
template<typename T>
void ReBuildTreeFromOrderLevel(const vector<string> &s, T *&root)
{
    int size = s.size();
    
    if (size == 0 || s[0] == "#")
    {
        root = NULL;
    }

    queue<T *> q;
    root = new T(atoi(s[0].c_str()));
    q.push(root);
    //cout << "Creating node : " << root->val << endl;

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
                    //cout << "left leaf child of " << node->val << " is empty leaf #!" << endl;
                }
                else
                {
                    T *tmp = new T(atoi(s[i].c_str()));
                    q.push(tmp);

                    node->left = tmp;
                    //cout << "Creating node : " << tmp->val << " for as left child of " << node->val << endl;
                }
            }

            i++;

            if (i < size)
            {
                if (s[i] == "#")
                {
                    //cout << "right leaf child of " << node->val << " is empty leaf #!" << endl;
                }
                else
                {
                    T *tmp = new T(atoi(s[i].c_str()));
                    q.push(tmp);

                    node->right = tmp;
                    //cout << "Creating node : " << tmp->val << " for as left child of " << node->val << endl;
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

// because we need to push TreeNode * to stack, it can't be declared as const
template<typename T>
void printTreePreorder(T *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<T *> s;
    s.push(root);
    T *prev = root;
    cout << root->val << "\t";

    while (!s.empty())
    {
        T *top = s.top();

        if (top->left == NULL && top->right == NULL)
        {
            s.pop();
            prev = top;
        }
        else if (top->left != NULL && prev != top->left && prev != top->right)
        {
            s.push(top->left);
            cout << top->left->val << "\t";
        }
        else if (top->right != NULL && prev != top->right)
        {
            s.push(top->right);
            cout << top->right->val << "\t";
        }
        else
        {
            s.pop();
            prev = top;
        }
    } 

    cout << endl;
}

template<typename T>
void printTreeInorder(T *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<TreeNode *> s;
    s.push(root);
    TreeNode *prev = root;

    while (!s.empty())
    { 
        TreeNode *top = s.top();

        if (top->left == NULL && top->right == NULL)
        {
            s.pop();
            cout << top->val << "\t";
            prev = top;
        }
        else if (top->left != NULL && prev != top->left && prev != top->right)
        {
            s.push(top->left);
        }
        else if (top->right != NULL && prev != top->right)
        {
            cout << top->val << "\t";
            s.push(top->right);
        }
        else
        {
            s.pop();
            prev = top;
        }
    }

    cout << endl;
}

template<typename T>
void printTreePostorder(T *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<TreeNode *> s;
    s.push(root);
    TreeNode *prev = NULL;

    while (!s.empty())
    {
        TreeNode *top = s.top();

        if (top->left != NULL && prev != top->left && (prev == NULL || prev != top->right))
        {
            s.push(top->left);
        }
        else if (top->right != NULL && prev != top->right)
        {
            s.push(top->right);
        }
        else
        {
            cout << top->val << "\t";
            prev = top;
            s.pop();
        }
    }

    cout << endl;
}

template <typename T>
void printTreeLevelOrder(T * const root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    cout << root->val << "\t";

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node->left != NULL)
        {
            TreeNode *left = node->left;
            q.push(left);
            cout << left->val << "\t";
        }

        if (node->right != NULL)
        {
            TreeNode *right = node->right;
            q.push(right);
            cout << right->val << "\t";
        }
    }

    cout << endl;
}

#endif
