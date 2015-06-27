#include <iostream>

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
    void recoverTree(TreeNode* root) {
    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;
    sln.recoverTree(root);
    printTreeInLevelOrder<TreeNode>(root);
    CleanUp2(root);
    return 0;
}
