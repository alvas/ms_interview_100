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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }

    void convert(TreeNode *root, int &sum) {
        if (!root) {
            return;
        }

        convert(root->right, sum);
        root->val += sum;
        sum = root->val;
        convert(root->left, sum);
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    vector<string> s = {"5", "2", "13"};
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    root = sln.convertBST(root);
    printTreeLevelOrder<TreeNode>(root);
    CleanUp2(root);
    return 0;
}
