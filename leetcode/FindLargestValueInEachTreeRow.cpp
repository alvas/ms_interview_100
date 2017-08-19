#include <iostream>
#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if (!root) {
            return ans;
        }

        helper(root, 0, ans);
        return ans;
    }

    void helper(TreeNode *node, int cl, vector<int> &ans) {
        if (!node) {
            return;
        }

        // when first time traverse a new level, push the first node to the array.
        if (ans.size() < cl + 1) {
            ans.push_back(node->val);
        }
        else {
            // when traverse other node on the same level, update the max value.
            if (ans[cl] < node->val) {
                ans[cl] = node->val;
            }
        }

        helper(node->left, cl + 1, ans);
        helper(node->right, cl + 1, ans);
    }

    vector<int> largestValues1(TreeNode* root) {
        vector<int> ans;

        if (!root){
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        int maxV = INT_MIN;

        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();

            if (!t) {
                if (!q.empty()) {
                    q.push(nullptr);
                }
                ans.push_back(maxV);
                maxV = INT_MIN;
            }
            else {
                maxV = max(maxV, t->val);

                if (t->left) {
                    q.push(t->left);
                }

                if (t->right) {
                    q.push(t->right);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    vector<string> v = {"1", "3", "2", "5", "3", "#", "9"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    vector<int> ans = sln.largestValues(root);
    printVector<int>(ans);
    CleanUp2<TreeNode>(root);
    return 0;
}
