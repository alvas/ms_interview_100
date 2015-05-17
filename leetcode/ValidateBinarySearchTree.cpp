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
    bool isValidBST(TreeNode* root) {
        // Be careful about the INT_MAX if use int type.
        long long min = LLONG_MIN, max = LLONG_MAX;
        return validate(root, min, max);
    }

    bool validate(TreeNode *root, long long min, long long max)
    {
        if (root == NULL)
        {
            return true;
        }
        else if (min < root->val && root->val < max)
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
    const int LOCAL_LENGTH = 2;
    //string a[LOCAL_LENGTH] = {"2147483647"};
    //string a[LOCAL_LENGTH] = {"1", "2"};
    string a[LOCAL_LENGTH] = {"2", "1"};
    //string a[LOCAL_LENGTH] = {"1", "#", "2", "3"};
    //string a[LOCAL_LENGTH] = {"2", "2", "3", "#", "#", "#", "4", "#", "5"};
    vector<string> v(a, a + LOCAL_LENGTH);
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(root, v);
    cout << sln.isValidBST(root) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
