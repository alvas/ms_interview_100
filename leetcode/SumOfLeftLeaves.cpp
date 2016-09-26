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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        else if (!root->left && !root->right) {
            // this question considers that the only root node should not be consider as a left leaf.
            return 0;
        }

        return addLeaves(root);
    }

    int addLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        else if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + addLeaves(root->right);
        }
        else if (!root->left && !root->right) {
            return 0;
        }

        return addLeaves(root->left) + addLeaves(root->right);
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    vector<string> v = {"1", "2", "#"};
    //vector<string> v = {"1", "#", "2"};
    //vector<string> v = {"3", "9", "20", "#", "#", "15", "7"};
    ReBuildTreeFromOrderLevel(v, root);
    cout << sln.sumOfLeftLeaves(root) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
