#include <iostream>
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

        TreeNode *node = root;
        int maxV = max(p->val, q->val), minV = min(p->val, q->val);

        while (node != NULL)
        {
            if (minV == node->val || maxV == node->val)
            {
                return node;
            }
            else if (minV < node->val && node->val < maxV)
            {
                return node;
            }
            else if (node->val < minV)
            {
                // don't be stupid. think careful what should be the logic here
                node = node->right;
            }
            else if (maxV < node->val)
            {
                // don't be stupid. think careful what should be the logic here
                node = node->left;
            }
        }

        return NULL;
    }
};

int main()
{
    Solution sln;
    vector<string> s = {"6", "2", "8", "0", "4", "7", "9", "#", "#", "3", "5"};
    vector<string> v(s, s + SIZE(s));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    TreeNode *p = findNodeInBST(root, 2);
    TreeNode *q = findNodeInBST(root, 4);

    //printTreeLevelOrder<TreeNode>(root);

    //if (p != NULL)
    //{
        //cout << "find p: " << p->val << endl;
    //}

    //if (q != NULL)
    //{
        //cout << "find q: " << q->val << endl;
    //}

    TreeNode *node = sln.lowestCommonAncestor(root, p, q);

    if (node != NULL)
    {
        cout << "The lowest common ancestor: " << node->val << endl;
    }
    
    CleanUp2<TreeNode>(root);
    return 0;
}
