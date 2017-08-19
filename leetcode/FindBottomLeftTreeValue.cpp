#include <iostream>
#include <queue>

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
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int res = root->val;
        findBottomLeftValue(root, maxDepth, res, 0);
        return res;
    }

    void findBottomLeftValue(TreeNode *root, int &maxDepth, int &res, int depth) {
        if (!root)
            return;

        findBottomLeftValue(root->left, maxDepth, res, depth + 1);
        findBottomLeftValue(root->right, maxDepth, res, depth + 1);

        // for the leftmost leaf node, the above 2 lines would just return and do nothing.
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root->val;
        }
    }

    int findBottomLeftValue1(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        int res = root->val;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            if (!t) {
                if (!q.empty())
                    t = q.front();

                if (t) {
                    res = t->val;
                    q.push(nullptr);
                }

                continue;
            }

            if (t->left) {
                q.push(t->left);
            }

            if (t->right) {
                q.push(t->right);
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    //vector<string> v = {"2", "1", "3"};
    vector<string> v = {"1", "2", "3", "4", "#", "5", "6", "#", "#", "#", "#", "7"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    cout << sln.findBottomLeftValue(root) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
