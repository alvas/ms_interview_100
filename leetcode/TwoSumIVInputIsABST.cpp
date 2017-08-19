#include <iostream>
#include <vector>

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
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        return dfs(root, root, k);
    }

    bool dfs(TreeNode *root, TreeNode *node, int k) {
        // be careful about this condition here.
        if (!node)
            return false;

        // in dfs, alway start searching from the root node
        // in find, start searching from the current node, but skipping the used node
        if (find(root, node, k - node->val))
            return true;

        return dfs(root, node->left, k) || dfs(root, node->right, k);
    }

    bool find(TreeNode *root, TreeNode *usedNode, int k) {
        if (!root)
            return false;

        if (root->val == k && root != usedNode)
            return true;
        else if (root->val > k)
            return find(root->left, usedNode, k);
        else
            return find(root->right, usedNode, k);
    }

    bool findTarget1(TreeNode* root, int k) {
        if (!root)
            return false;

        return traverse1(root, root, k);
    }

    bool traverse1(TreeNode *root, TreeNode *node, int k) {
        // be careful about this condition here.
        if (!node)
            return false;

        if (find1(root, node, k - node->val))
            return true;

        return traverse1(root, node->left, k) || traverse1(root, node->right, k);
    }

    bool find1(TreeNode *root, TreeNode *usedNode, int k) {
        if (!root)
            return false;

        if (root->val == k && root != usedNode)
            return true;

        return find1(root->left, usedNode, k) || find1(root->right, usedNode, k);
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    //vector<string> s = {"5", "3", "6", "2", "4", "#", "7"};
    vector<string> s = {"2", "1", "3"};
    //vector<string> s = {"1"};
    //int k = 9;
    //int k = 28;
    //int k = 2;
    int k = 4;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    cout << sln.findTarget(root, k) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
