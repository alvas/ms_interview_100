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
    int findTilt(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int tilt = 0;
        int sum1 = findTiltNode(root->left, tilt);
        int sum2 = findTiltNode(root->right, tilt);
        return abs(sum1 - sum2) + tilt;
    }

    int findTiltNode(TreeNode *root, int &tilt)
    {
        if (!root) {
            return 0;
        }

        int sum1 = findTiltNode(root->left, tilt);
        int sum2 = findTiltNode(root->right, tilt);
        tilt += abs(sum1 - sum2);
        return sum1 + sum2 + root->val;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    //vector<string> v = {"1", "2", "3"};
    vector<string> v = {"1", "2", "3", "4"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    cout << sln.findTilt(root) << endl;
    CleanUp2(root);
    return 0;
}
