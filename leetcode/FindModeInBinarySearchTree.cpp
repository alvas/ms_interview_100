#include <iostream>
#include <map>
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;

        if (!root)
            return res;

        int maxCount = 0;
        map<int, int> m;
        countNode(root, m, maxCount);

        for (auto p: m) {
            if (p.second == maxCount) {
                res.push_back(p.first);
            }
        }

        return res;
    }

    void countNode(TreeNode *root, map<int, int> &m, int &maxCount) {
        if (!root)
            return;

        m[root->val]++;
        maxCount = max(maxCount, m[root->val]);
        countNode(root->left, m, maxCount);
        countNode(root->right, m, maxCount);
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    vector<string> u = {"1","#","2","2"};
    ReBuildTreeFromOrderLevel<TreeNode>(u, root);
    vector<int> nums = sln.findMode(root);
    printVector<int>(nums);
    CleanUp2(root);
    return 0;
}
