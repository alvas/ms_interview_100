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
    int sumNumbers(TreeNode* root) {
        int sum = 0;

        if (root == NULL)
        {
            return sum;
        }

        int tmp = 0;
        traverseTree(root, tmp, sum);
        return sum;
    }

    void traverseTree(TreeNode *root, int tmp, int &sum)
    {
        if (root != NULL && root->left == NULL && root->right == NULL)
        {
            sum = sum + 10 * tmp + root->val;
            return;
        }

        tmp = tmp * 10 + root->val;

        if (root->left != NULL)
        {
            traverseTree(root->left, tmp, sum);
        }

        if (root->right != NULL)
        {
            traverseTree(root->right, tmp, sum);
        }
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 13;
    string node[LOCAL_LENGTH] = {"1", "2", "3", "4", "6", "2", "9", "5", "#", "#", "#", "#", "8"};
    vector<string> v(node, node + LOCAL_LENGTH);
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    cout << sln.sumNumbers(root) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
