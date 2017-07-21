#include <iostream>
#include <string>

#include "Tree.h"

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int dia = 0;
        findDiameter(root, dia);
        return dia;
    }

    int findDiameter(TreeNode *root, int &dia) {
        if (!root) {
            return 0;
        }

        int l = 0, r = 0;
        
        if (root->left)
            l = findDiameter(root->left, dia) + 1;
        
        if (root->right)
            r = findDiameter(root->right, dia) + 1;

        dia = max(dia, l + r);

        return max(l, r);
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    vector<string> v = {"1", "2", "3", "4", "5"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    cout << sln.diameterOfBinaryTree(root) << endl;
    CleanUp2(root);
    return 0;
}
