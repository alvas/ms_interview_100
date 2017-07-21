#include <iostream>
#include <queue>
#include <vector>

#include "NormalData.h"
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> r;

        if (root == NULL)
        {
            return r;
        }

        queue<TreeNode *> q, nextLevel;
        q.push(root);
        bool added = false;

        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();

            if (!added)
            {
                r.push_back(t->val);
                added = true;
            }

            if (t->right != NULL)
            {
                nextLevel.push(t->right);
            }

            if (t->left != NULL)
            {
                nextLevel.push(t->left);
            }

            if (q.empty())
            {
                added = false;
                q.swap(nextLevel);
            }
        }

        return r;
    }
};

int main()
{
    Solution sln;
    TreeNode *p = nullptr;
    string leaf[11] = {"1", "2", "3", "#", "5", "#", "4"};
    vector<string> v(leaf, leaf + 7);
    ReBuildTreeFromOrderLevel<TreeNode>(v, p);
    vector<int> u = sln.rightSideView(p);
    printVector<int>(u);
    return 0;
}

