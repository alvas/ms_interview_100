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
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }

    void swap(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = right;
        root->right = left;
        swap(root->left);
        swap(root->right);
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
    root = sln.invertTree(root);
    printTreeLevelOrder<TreeNode>(root);
    CleanUp2(root);
    return 0;
}

