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
    // This is really difficault. Got a lot of failure before tuning it right.
    int maxPathSum(TreeNode* root) {
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
    string a[] = {"-3"};
    //string a[] = {"-2", "-1"};
    //string a[] = {"-2", "1"};
    //string a[] = {"2", "-1", "-2"};
    //string a[] = {"2", "-1"};
    //string a[] = {"2", "-1", "-2"};
    //string a[] = {"4", "2", "7", "1", "3", "8", "9"};
    //string a[] = {"-1", "5", "#", "4", "#", "#", "2", "-4"};
    //string a[] = {"-3", "2", "#", "3", "-6", "#", "#", "2"};
    //string a[] = {"9", "6", "-3", "#", "#", "-6", "2", "#", "#", "2", "#", "-6", "-6", "-6"};
    //string a[] = {"5", "6", "-6", "3", "5", "3", "#", "-7"};
    vector<string> s(a, a + SIZE(a));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    printTreeLevelOrder<TreeNode>(root);
    cout << sln.maxPathSum(root) << endl;
    CleanUp2(root);
    return 0;
}