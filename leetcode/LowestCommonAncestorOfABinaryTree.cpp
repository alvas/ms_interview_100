#include <iostream>
#include <set>
#include <stack>
#include <vector>

#include "NormalData.h"
#include "Tree.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
        {
            return NULL;
        }
        else if (p == q)
        {
            return p;
        }
        else if (root == p || root == q)
        {
            return root;
        }

        TreeNode *ancestor = NULL;
        stack<TreeNode *> stk;
        set<TreeNode *> s;

        findNode(root, p, stk);

        cout << "stack1: " << endl;

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            cout << "node: " << node->val << endl;
            s.insert(node);
        }

        findNode(root, q, stk);

        cout << "stack2: " << endl;

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            cout << "node: " << node->val << endl;

            if (s.find(node) != s.end())
            {
                ancestor = node;
                break;
            }
        }
        
        return ancestor;
    }

    void findNode(TreeNode *root, TreeNode *t, stack<TreeNode *> &s)
    {
        if (root == NULL || t == NULL)
        {
            return;
        }
        else if (root == t)
        {
            s.push(root);
            return;
        }
        else if (!s.empty() && s.top() == t)
        {
            return;
        }

        s.push(root);

        if (root->left != NULL)
        {
            findNode(root->left, t, s);
        }

        if (root->right != NULL)
        {
            findNode(root->right, t, s);
        }
    }
};

int main()
{
    Solution sln;
    string s[] = {"3", "5", "1", "6", "2", "0", "8", "#", "#", "7", "4"};
    vector<string> v(s, s + SIZE(s));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    TreeNode *p = findNodeInBT(root, 5);
    TreeNode *q = findNodeInBT(root, 1);

    //if (p != NULL)
    //{
        //cout << "p: " << p->val << endl;
    //}

    //if (q != NULL)
    //{
        //cout << "q: " << q->val << endl;
    //}

    TreeNode *node = sln.lowestCommonAncestor(root, p, q);

    if (node != NULL)
    {
        cout << "The lowest common ancestor: " << node->val << endl;
    }
    
    CleanUp2<TreeNode>(root);
    return 0;
}
