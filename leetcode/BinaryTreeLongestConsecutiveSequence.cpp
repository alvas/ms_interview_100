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
    int longestConsecutive(TreeNode* root) {
        return search(root, nullptr, 0);
    }

    int search(TreeNode *root, TreeNode *parent, int len) {
        if (!root) {
            return len;
        }

        len = (parent && root->val == parent->val + 1) ? len + 1 : 1;
        return max(len, max(search(root->left, root, len), search(root->right, root, len)));
    }

    int longestConsecutive1(TreeNode* root) {
        if (!root) {
            return 0;
        }

        ans = 1;
        dfs(root, root->val, 1);

        return ans;
    }

    void dfs(TreeNode *node, int value, int count) {
        if (!node) {
            return;
        }

        if (node->val == value + 1) {
            count++;
            ans = max(ans, count);
        }
        else {
            count = 1;
        }

        dfs(node->left, node->val, count);
        dfs(node->right, node->val, count);
    }

private:
    int ans;
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    //vector<string> v = {"1", "#", "3", "2", "4", "#", "#", "#", "5"};
    //vector<string> v = {"2", "#", "3", "2", "#" "1"};
    vector<string> v = {"1"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    cout << sln.longestConsecutive(root) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
