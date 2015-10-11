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
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        findK(root, k, val);
        return val;
    }

    void findK(TreeNode *root, int &k, int &val)
    {
        // Important to check the terminate conditions.
        if (root == NULL || k <= 0)
        {
            return;
        }

        findK(root->left, k, val);

        if (--k == 0)
        {
            val = root->val;
            return;
        }

        findK(root->right, k, val);
    }
};

int main()
{
    Solution sln;
    vector<string> s = {"6", "2", "8", "0", "4", "7", "9", "#", "#", "3", "5"};
    vector<string> v(s, s + SIZE(s));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    printTreeLevelOrder<TreeNode>(root);
    int k = 0;
    cout << "Please enter k: ";
    cin >> k;
    cout << sln.kthSmallest(root, k) << endl;
    CleanUp2(root);
    return 0;
}
