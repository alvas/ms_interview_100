#include <iostream>

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
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return isMonotonicIncreasing(root, prev);
    }

    bool isMonotonicIncreasing(TreeNode *p, TreeNode *&prev)
    {
        if (p == NULL)
        {
            return true;
        }

        if (isMonotonicIncreasing(p->left, prev))
        {
            if (prev != NULL && p->val <= prev->val)
            {
                return false;
            }

            prev = p;

            return isMonotonicIncreasing(p->right, prev);
        }

        return false;
    }

    // This algorithm would consider duplicated nodes are valid in binary search tree.
    bool isValidBST1(TreeNode* root) {
        // Be careful about the INT_MAX if use int type.
        //long long min = LLONG_MIN, max = LLONG_MAX;
        int min = INT_MIN, max = INT_MAX;
        return validate(root, min, max);
    }

    bool validate(TreeNode *root, int min, int max)
    {
        if (root == NULL)
        {
            return true;
        }
        // if there are duplicated nodes in the BST tree.
        else if (min <= root->val && root->val <= max)
        {
            return validate(root->left, min, root->val) && validate(root->right, root->val, max);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution sln;
    vector<string> v = {"2147483647"};
    //vector<string> v = {"1", "2"};
    //vector<string> v = {"2", "1"};
    //vector<string> v = {"1", "#", "2", "3"};
    //vector<string> v = {"2", "2", "3", "#", "#", "#", "4", "#", "5"};
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    std::cout << sln.isValidBST1(root) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
