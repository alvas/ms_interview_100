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
        int count = 0;

        if (root == NULL)
        {
            return count;
        }

        return count;
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
    string a[] = {"4", "2", "7", "1", "3", "6", "9"};
    vector<string> s(a, a + SIZE(a));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    cout << sln.countNodes_recursive(root) << endl;
    cout << sln.countNodes(root) << endl;
    CleanUp2(root);
    return 0;
}
