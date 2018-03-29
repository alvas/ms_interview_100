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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return;

        TreeNode *left = trimBST(root->left, L, R);
        TreeNode *newRoot = nullptr;
        TreeNode *right = trimBST(root->right, L, R);

        return newRoot;
    }
};

int main()
{
    Solution sln;
    int L = 1, R = 2;
    //int L = 1, R = 3;
    TreeNode *root = nullptr;
    vector<string> v = {"1", "0", "2"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    TreeNode *res = sln.trimBST(root, L, R);
    printTreeLevelOrder<TreeNode>(res);
    CleanUp2<TreeNode>(res);
    return 0;
}
