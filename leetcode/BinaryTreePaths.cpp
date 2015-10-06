#include <iostream>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;

        if (root == NULL)
        {
            return ret;
        }

        string path;
        treePath(root, path, ret);
        return ret;
    }

    void treePath(TreeNode *root, string &path, vector<string> &ret)
    {
        if (root == NULL)
        {
            // We can't push back the path here. We have to push back
            // the path at the leave node. Because the leave node has
            // 2 NULL children. If we push back path here, one path
            // would be pushed back twice.
            return;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            string num = to_string(root->val);
            int sz  = num.size();
            path += num;
            ret.push_back(path);
            int sz2 = path.size();
            path.erase(sz2 - sz, sz);
            return;
        }

        string num = to_string(root->val);
        int sz  = num.size();
        path += num + "->";
        treePath(root->left, path, ret);
        treePath(root->right, path, ret);
        int sz2 = path.size();
        // Be careful about the size.
        path.erase(sz2 - sz - 2, sz + 2);
    }
};

int main()
{
    Solution sln;
    vector<string> s{"8", "2", "6", "0", "4", "7", "9", "#", "#", "3", "5"};
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    vector<string> v = sln.binaryTreePaths(root);
    printVector<string>(v);
    CleanUp2(root);
    return 0;
}
