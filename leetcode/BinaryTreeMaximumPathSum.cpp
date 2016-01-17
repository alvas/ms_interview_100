#include <iostream>
#include <vector>

#include "NormalData.h"
#include "Tree.h"

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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMax(root, maxSum);
        return maxSum;
    }

    // 1. max(left subtree) + node
    // 2. max(right subtree) + node
    // 3. max(left subtree) + max(right subtree) + node
    // 4. node
    int findMax(TreeNode *root, int &maxSum)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = findMax(root->left, maxSum);
        int right = findMax(root->right, maxSum);
        maxSum = max(root->val + left + right, maxSum);
        int ret = root->val + max(left, right);
        return ret ? ret : 0;
    }

    // This is really difficault. Got a lot of failure before tuning it right.
    int maxPathSum1(TreeNode* root) {
        int max = INT_MIN;
        traverseSum(root, max);
        return max;
    }

    // Really need to consider all kinds of situations.
    int traverseSum(TreeNode *root, int &localMax)
    {
        // Be carefull, can't check root == NULL and return 0.
        // Otherwise, if {-3} would return 0, instead of -3.
        // The default value 0 may not suitible in some situation,
        // because there can be negative number.
        if (root->left == NULL && root->right == NULL)
        {
            localMax = max(localMax, root->val);
            return root->val;
        }

        // Be careful, don't initialize left and right as INT_MIN, because they 
        // are added together later. And this would cause overflow.
        int left = 0, right = 0;

        if (root->left != NULL)
        {
            // Get the max value of the left child subtree.
            left = traverseSum(root->left, localMax);

            // Need to check the max among previous localMax, root and left + root.
            localMax = max(localMax, root->val);
            localMax = max(localMax, left + root->val);
        }
        else
        {
            localMax = max(localMax, root->val);
        }

        if (root->right != NULL)
        {
            // Get the max value of the right child subtree.
            right = traverseSum(root->right, localMax);

            // Need to check the max among previous localMax, root and right + root.
            localMax = max(localMax, root->val);
            localMax = max(localMax, right + root->val);
        }
        else
        {
            // Be careful, we can't assign root->val to localMax directly.
            // Have to get the max between previous localMax and root->val,
            // because the localMax would be set by the left child branch.
            localMax = max(localMax, root->val);
        }

        // Need to get the max among previous localMax, root + left subtree + right subtree
        localMax = max(localMax, root->val + left + right);

        // Be very careful about the return value. The if the left/right subtree is negative, then don't add it to the return value. Otherwise, add the max of left/right subtree to root.
        return max(0, max(left, right)) + root->val;
    }
};

int main()
{
    Solution sln;
    std::vector<string> s = {"-3"};
    //std::vector<string> s = {"-2", "-1"};
    //std::vector<string> s = {"-2", "1"};
    //std::vector<string> s = {"2", "-1", "-2"};
    //std::vector<string> s = {"2", "-1"};
    //std::vector<string> s = {"2", "-1", "-2"};
    //std::vector<string> s = {"4", "2", "7", "1", "3", "8", "9"};
    //std::vector<string> s = {"-1", "5", "#", "4", "#", "#", "2", "-4"};
    //std::vector<string> s = {"-3", "2", "#", "3", "-6", "#", "#", "2"};
    //std::vector<string> s = {"9", "6", "-3", "#", "#", "-6", "2", "#", "#", "2", "#", "-6", "-6", "-6"};
    //std::vector<string> s = {"5", "6", "-6", "3", "5", "3", "#", "-7"};
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    std::cout << sln.maxPathSum(root) << endl;
    CleanUp2(root);
    return 0;
}
