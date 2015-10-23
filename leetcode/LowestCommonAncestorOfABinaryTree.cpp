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

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            s.insert(node);
        }

        findNode(root, q, stk);

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();

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

        TreeNode *prev = NULL;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *node = s.top();

            if (node == t)
            {
                return;
            }
            else if (node->left != NULL && node->left != prev && (prev == NULL || prev != node->right))
            {
                s.push(node->left);
            }
            else if (node->right != NULL && prev != node->right)
            {
                s.push(node->right);
            }
            else
            {
                s.pop();
                prev = node;
            }
        }
    }

    void findNode1(TreeNode *root, TreeNode *t, stack<TreeNode *> &s)
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

            if (!s.empty() && s.top() != t)
            {
                s.pop();
            }
        }

        if (s.top() != t && root->right != NULL)
        {
            findNode(root->right, t, s);

            if (!s.empty() && s.top() != t)
            {
                s.pop();
            }
        }
    }
};

int main()
{
    Solution sln;
    vector<string> v = {"3", "5", "1", "6", "2", "0", "8", "#", "#", "7", "4"};
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    TreeNode *p = findNodeInBT(root, 2);
    TreeNode *q = findNodeInBT(root, 4);

    //if (p != NULL)
    //{
        //std::cout << "p: " << p->val << endl;
    //}

    //if (q != NULL)
    //{
        //std::cout << "q: " << q->val << endl;
    //}

    TreeNode *node = sln.lowestCommonAncestor(root, p, q);

    if (node != NULL)
    {
        std::cout << "The lowest common ancestor: " << node->val << endl;
    }
    
    CleanUp2<TreeNode>(root);
    return 0;
}
