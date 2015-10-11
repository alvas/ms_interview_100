#include <cmath>
#include <iostream>
#include <queue>
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
    int countNodes(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }

        TreeNode *p = root;
        int h = 0;

        while (p != NULL)
        {
            h++;
            p = p->left;
        }

        // [l, r] is the range of number for nodes in the last level.
        int l = 0, r = (1 << (h - 1)) - 1;

        // binary search the last node on the last level.
        while (l <= r)
        {
            int m = l + ((r - 1) >> 1);

            if (isOK(root, h, m))
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return (1 << (h - 1)) + r;
    }

    bool isOK(TreeNode *root, int h, int v)
    {
        TreeNode *p = root;

        // there are h levels, but we need to go h - 1 steps to the last level.
        for (int i = h - 2; i >= 0; --i)
        {
            if (v & (1 << i))
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }

        return p != NULL;
    }

    int countNodes_height_recursive(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }

        int leftH = heightLeft(root);
        int rightH = heightRight(root);

        // If this is a complete binary tree.
        if (leftH == rightH)
        {
            return pow(2, leftH) - 1;
        }

        // If it is not complete binary tree, recursively count node of left/right sub tree.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int heightLeft(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return 1 + heightLeft(root->left);
    }

    int heightRight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return 1 + heightRight(root->right);
    }

    int countNodes_queue(TreeNode* root) {
        int count = 0;

        if (root == NULL)
        {
            return count;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            count++;
            q.pop();

            if (node->left != NULL)
            {
                q.push(node->left);
            }

            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }

        return count;
    }

    int countNodes_recursive(TreeNode* root) {
        int count = 0;

        if (root == NULL)
        {
            return count;
        }

        traverse(root, count);
        return count;
    }

    void traverse(TreeNode *root, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        count++;

        traverse(root->left, count);
        traverse(root->right, count);
    }
};

int main()
{
    Solution sln;
    vector<string> a = {"4", "2", "7", "1", "3", "6", "9"};
    vector<string> s(a, a + SIZE(a));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    cout << sln.countNodes_recursive(root) << endl;
    cout << sln.countNodes(root) << endl;
    CleanUp2(root);
    return 0;
}
