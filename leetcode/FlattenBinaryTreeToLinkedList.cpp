#include <iostream>

#include "Tree.h"
#include "NormalData.h"

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
    void flatten(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }

        build(root);
        return;
    }

    TreeNode * build(TreeNode *root)
    {
        // node is NULL
        if (root == NULL)
        {
            return root;
        }
        // leaf node
        else if (root->left == NULL && root->right == NULL)
        {
            return root;
        }

        TreeNode *ltail = NULL, *rtail = NULL;

        // get tail of left child subtree
        if (root->left  != NULL)
        {
            ltail = build(root->left);
        }

        // get tail of right child subtree
        if (root->right != NULL)
        {
            rtail = build(root->right);
        }

        // if left child subtree is not empty, attach the right subtree to the 
        // left tail
        if (ltail != NULL)
        {
            ltail->right = root->right;
        }

        // if the left child subtree is not empty, move it to the right side
        if (root->left != NULL)
        {
            root->right = root->left;
            root->left = NULL;
        }

        return rtail != NULL ? rtail : ltail;
    }
};

int main()
{
    Solution sln;
    vector<string> v;
    TreeNode *root = NULL;

    for (int i = 1; i <= 15; ++i)
    {
        v.push_back(to_string(i));
        ReBuildTreeFromOrderLevel<TreeNode>(v, root);
        //printTreeLevelOrder<TreeNode>(root);
        sln.flatten(root);
        printTreeLevelOrder<TreeNode>(root);
        //printTreePostorder<TreeNode>(root);
        CleanUp2<TreeNode>(root);
        root = NULL;
    }

    v.clear();
    const int LOCAL_LENGTH = 26;
    //string a[LOCAL_LENGTH] = {"1", "#", "2"};
    //string a[LOCAL_LENGTH] = {"1", "#", "2", "3"};
    //string a[LOCAL_LENGTH] = {"1", "2", "#", "3"};
    //string a[LOCAL_LENGTH] = {"1", "2", "#", "#", "3"};
    //string a[LOCAL_LENGTH] = {"1", "#", "2", "#", "3"};
    //string a[LOCAL_LENGTH] = {"1", "#", "2", "#", "3", "#", "4", "5", "6"};
    string a[LOCAL_LENGTH] = 
    {
        "1", "#", "2", "#", "3", 
        "#", "4", "5", "#", "6", 
        "#", "7", "8", "9", "10", 
        "11", "#", "#", "#", "#", 
        "#", "12", "13", "#", "#", 
        "14"
    };
    v.assign(a, a + LOCAL_LENGTH);
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    //printTreeLevelOrder<TreeNode>(root);
    sln.flatten(root);
    printTreeLevelOrder<TreeNode>(root);
    //printTreePostorder<TreeNode>(root);
    CleanUp2<TreeNode>(root);

    return 0;
}
