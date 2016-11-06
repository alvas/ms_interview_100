#include <cmath>
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
    int closestValue(TreeNode* root, double target) {
        if (!root) {
            return 0;
        }

        int res = root->val;
        dfs(root, target, res);
        return res;
    }

    void dfs(TreeNode* root, double target, int& res) {
        if (!root) {
            return;
        }

        if (fabs(target - root->val) < fabs(target - res)) {
            res = root->val;
        }

        // Binary search tree!!
        if (root->val >= target)  {
            dfs(root->left, target, res);
        }
        else {
            dfs(root->right, target, res);
        }
    }
};

int main() {
    Solution sln;
    double target = 15.7;
    TreeNode *root = nullptr;
    vector<string> v = {"30", "20", "40", "10", "25", "35", "50"};
    ReBuildTreeFromOrderLevel(v, root);
    cout << sln.closestValue(root, target) << endl;
    CleanUp2(root);
    return 0;
}
