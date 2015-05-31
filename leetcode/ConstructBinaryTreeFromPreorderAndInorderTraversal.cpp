#include <cassert>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = NULL;
        int size = preorder.size();

        if (size == 0)
        {
            return root;
        }

        root = new TreeNode(preorder[0]);

        int numL = findM(inorder, preorder[0], 0, size);
        int numR = size - numL - 1;

        // !!!pitfall!! We need to use length to indicate the range of left and right subtree.
        root->left = build(preorder, inorder, 1, 0, numL);
        // Because the top level right child in both preorder and inorder starts from 0 + numL + 1
        root->right = build(preorder, inorder, numL + 1, numL + 1, numR);
        return root;
    }

    int findM(vector<int> &inorder, int target, int begin, int end)
    {
        int count = 0;

        for (int i = begin; i < end; ++i)
        {
            if (inorder[i] == target)
            {
                break;
            }

            count++;
        }

        return count;
    }

    TreeNode * build(vector<int> &preorder, vector<int> &inorder, int pbegin, int ibegin, int num)
    {
        if (num <= 0)
        {
            return NULL;
        }

        TreeNode *node = new TreeNode(preorder[pbegin]);
        int numL = findM(inorder, preorder[pbegin], ibegin, ibegin + num);
        int numR= num - numL - 1;

        // Be careful to check when there is no node left in left or right subtree.
        if (numL > 0)
        {
            node->left = build(preorder, inorder, pbegin + 1, ibegin, numL);
        }

        if (numR > 0)
        {
            // Be careful about the inorder begin position.
            node->right = build(preorder, inorder, pbegin + numL + 1, ibegin + numL + 1 , numR);
        }

        return node;
    }
};

int main()
{
    Solution sln;
    int a[] = {5, 4, 11, 7, 2, 8, 13, 4, 1};
    int b[] = {7, 11, 2, 4, 5, 13, 8, 4, 1};
    vector<int> preorder(a, a + SIZE(a));
    vector<int> inorder(b, b + SIZE(b));
    TreeNode *root = sln.buildTree(preorder, inorder);
    printTreeLevelOrder(root);
    CleanUp2<TreeNode>(root);
    return 0;
}
