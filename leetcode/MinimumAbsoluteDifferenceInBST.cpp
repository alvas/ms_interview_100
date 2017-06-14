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
    int getMinimumDifference(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int curV = INT_MIN, diff = INT_MAX;
        inOrderTraverse(root, curV, diff);
        return diff;
    }

    void inOrderTraverse(TreeNode *root, int &curV, int &diff) {
        if (!root) {
            return;
        }

        inOrderTraverse(root->left, curV, diff);

        // be careful about this condition and location
        if (curV != INT_MIN || diff != INT_MAX) {
            diff = min(diff, root->val - curV);
        }

        curV = root->val;
        inOrderTraverse(root->right, curV, diff);
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    //vector<string> v = {"1", "#", "3", "2"};
    vector<string> v = {"20", "9", "30", "4", "15", "24", "35", "#", "7", "#", "#", "#", "26"};
    //vector<string> v = {"5", "4", "7"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    cout << sln.getMinimumDifference(root) << endl;
    CleanUp2(root);
    return 0;
}
