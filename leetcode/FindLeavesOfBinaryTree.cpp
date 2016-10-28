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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }

    int helper(TreeNode* root, vector<vector<int>>& res) {
        if (!root) {
            return -1;
        }

        int depth = 1 + max(helper(root->left, res), helper(root->right, res));

        if (depth >= res.size()) {
            res.resize(depth + 1);
        }

        res[depth].push_back(root->val);
        return depth;
    }

    vector<vector<int>> findLeaves1(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) {
            return res;
        }


        while (root) {
            vector<int> tmp;
            root = collectLeaves(root, tmp);
            res.push_back(tmp);
        }

        //vector<int> tmp;

        //while (root->left || root->right) {
            //collectLeaves1(root, tmp);
            //res.push_back(tmp);
            //tmp.clear();
        //}

        //tmp.push_back(root->val);
        //res.push_back(tmp);

        return res;
    }

    TreeNode* collectLeaves(TreeNode* root, vector<int>& tmp) {
        if (!root->left && !root->right) {
            tmp.push_back(root->val);
            return NULL;
        }

        root->left = collectLeaves(root->left, tmp);
        root->right = collectLeaves(root->right, tmp);
        return root;
    }

    bool collectLeaves1(TreeNode* root, vector<int>& tmp) {
        if (!root->left && !root->right) {
            tmp.push_back(root->val);
            return true;
        }

        if (root->left) {
            if (collectLeaves1(root->left, tmp)) {
                root->left = nullptr;
            }
        }

        if (root->right) {
            if (collectLeaves1(root->right, tmp)) {
                root->right = nullptr;
            }
        }

        return false;
    }
};

int main() {
    Solution sln;
    TreeNode* root = nullptr;
    vector<string> tree = {"1", "2", "3", "4", "5", "#", "#"};
    ReBuildTreeFromOrderLevel(tree, root);
    vector<vector<int>> v = sln.findLeaves(root);
    print2DVector<int>(v);
    CleanUp2<TreeNode>(root);
    return 0;
}
