#include <iostream>
#include <queue>

#include "Tree.h"

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p == NULL && q != NULL)
        {
            return false;
        }
        else if (p != NULL && q == NULL)
        {
            return false;
        }

        queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty())
        {
            TreeNode *n1 = q1.front();
            TreeNode *n2 = q2.front();
            q1.pop();
            q2.pop();

            if (n1->val != n2->val ||
                (n1->left != NULL && n2->left == NULL) ||
                (n1->left == NULL && n2->left != NULL) ||
                (n1->right != NULL && n2->right == NULL) ||
                (n1->right == NULL && n2->right != NULL))
            {
                return false;
            }

            if (n1->left != NULL && n2->left != NULL)
            {
                q1.push(n1->left);
                q2.push(n2->left);
            }

            if (n1->right != NULL && n2->right != NULL)
            {
                q1.push(n1->right);
                q2.push(n2->right);
            }
        }

        if (!q1.empty() || !q2.empty())
        {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution sln;
    TreeNode *p = NULL, *q = NULL;
    string leaf[11] = {"1", "2", "2", "3", "#", "#", "3", "4", "#", "#", "4"};
    string leaf2[12] = {"1", "2", "2", "3", "#", "#", "3", "7", "4", "#", "#", "4"};
    vector<string> v(leaf, leaf + 11);
    vector<string> v2(leaf2, leaf2 + 12);
    ReBuildTreeFromOrderLevel<TreeNode>(v, p);
    ReBuildTreeFromOrderLevel<TreeNode>(v2, q);
    std::cout << sln.isSameTree(p, q) << endl;
    return 0;
}

