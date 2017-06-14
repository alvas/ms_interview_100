#include <iostream>
#include <vector>
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return nullptr;
        }

        TreeNode *node = new TreeNode((t1 ? t1->val: 0) + (t2 ? t2->val : 0));
        node->left = merge(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        node->right = merge(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        return node;
    }

    TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2) {
        TreeNode *root = nullptr;
        merge(t1, t2, root);
        return root;
    }

    void merge(TreeNode *t1, TreeNode *t2, TreeNode * &root) {
        if (t1 == nullptr && t2 == nullptr) {
            return;
        }

        root = new TreeNode(0);

        if (t1) {
            root->val += t1->val;
        }

        if (t2) {
            root->val += t2->val;
        }

        merge(t1 != nullptr ? t1->left : nullptr, t2 != nullptr ? t2->left : nullptr, root->left);
        merge(t1 != nullptr ? t1->right : nullptr, t2 != nullptr ? t2->right : nullptr, root->right);
    }
};

int main()
{
    Solution sln;
    vector<string> v1 = {"1", "3", "2", "5"};
    vector<string> v2 = {"2", "1", "3", "#", "4", "#", "7"};
    TreeNode *root1 = nullptr, *root2 = nullptr;
    ReBuildTreeFromOrderLevel<TreeNode>(v1, root1);
    ReBuildTreeFromOrderLevel<TreeNode>(v2, root2);
    TreeNode *root3 = sln.mergeTrees(root1, root2);
    printTreeLevelOrder(root3);
    CleanUp2<TreeNode>(root1);
    CleanUp2<TreeNode>(root2);
    CleanUp2<TreeNode>(root3);
    return 0;
}
