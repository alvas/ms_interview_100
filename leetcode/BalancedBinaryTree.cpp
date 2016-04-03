#include <iostream>

#include "Tree.h"

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        return maxDepth(root) != -1;
    }

    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int L = maxDepth(root->left);

        if (L == -1)
        {
            return -1;
        }

        int R = maxDepth(root->right);

        if (R == -1)
        {
            return -1;
        }

        return abs(L - R) <= 1 ? max(L, R) + 1 : -1;
    }

    bool isBalanced2(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return abs(maxDepth2(root->left) - maxDepth2(root->right)) <= 1
            && isBalanced2(root->left) && isBalanced2(root->right);
    }

    int maxDepth2(TreeNode *root)
    {
        if (root == NULL)
        {
            return 1;
        }

        return max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
    }

    // Need to improve performance
    bool isBalanced1(TreeNode *root) {

        if (root == NULL)
        {
            return true;
        }

        if (isBalanced(root->left) && isBalanced(root->right))
        {
            // Be very careful!!
            // When one of the children is NULL, it is checking the high of
            // the other child. SO if its high is >= 1, the current node
            // has one branch >= 2, the other branch == 0.
            if (root->left == NULL && root->right != NULL)
            {
                if (highOfTree(root->right) >= 1)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if (root->left != NULL && root->right == NULL)
            {
                if (highOfTree(root->left) >= 1)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                int left = highOfTree(root->left);
                int right = highOfTree(root->right);

                if (abs(left - right) > 1)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        else
        {
            return false;
        }
    }

    int highOfTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            int h = highOfTree(root->right);
            //std::cout << "node " << root->val << "; high " << 1 + h << endl;
            return 1 + h;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            int h = highOfTree(root->left);
            //std::cout << "node " << root->val << "; high " << 1 + h << endl;
            return 1 + h;
        }
        else
        {
            int h = max(highOfTree(root->right), highOfTree(root->left));
            //std::cout << "node " << root->val <<  "; high " << 1 + h << endl;
            return 1 + h;
        }
    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;
    //const int TREELEN = 7;
    //int szInOrder[TREELEN] = {3, 2, 4, 1, 6, 5, 7};
    //int szPostOrder[TREELEN] = {3, 4, 2, 6, 7, 5, 1};
    //ReBuildTreeFromInPost2(szInOrder, szPostOrder, TREELEN, root);

    string leaf[11] = {"1", "2", "2", "3", "#", "#", "3", "4", "#", "#", "4"};
    vector<string> s(leaf, leaf + 11);
    ReBuildTreeFromOrderLevel<TreeNode>(s, root);
    std::cout << sln.isBalanced(root) << endl;
    CleanUp(root);
    return 0;
}

