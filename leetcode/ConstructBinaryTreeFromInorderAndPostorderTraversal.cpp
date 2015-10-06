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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = NULL;
        int size = inorder.size();

        if (size == 0)
        {
            return root;
        }

        root = new TreeNode(postorder[size - 1]);
        int numR = findM(inorder, postorder[size - 1], 0, size - 1);
        int numL = size - 1 - numR;

        root->right = build(inorder, postorder, size - 1, size - 2, numR);
        root->left = build(inorder, postorder, size - 2 - numR, size - 2 - numR, numL);

        return root;        
    }

    int findM(const vector<int> &inorder, int target, int begin, int end)
    {
        int count = 0;

        for (int i = end; i >= begin; --i)
        {
            if (inorder[i] == target)
            {
                break;
            }
            
            count++;
        }

        return count;
    }

    TreeNode * build(vector<int> &inorder, vector<int> &postorder, int iend, int pend, int num)
    {
        if (num <= 0)
        {
            return NULL;
        }

        TreeNode *node = new TreeNode(postorder[pend]);
        int numR = findM(inorder, postorder[pend], iend - num, iend);
        int numL = num - numR - 1; 

        if (numR > 0)
        {
            node->right = build(inorder, postorder, iend, pend - 1, numR);
        }

        if (numL > 0)
        {
            node->left = build(inorder, postorder, iend - 1 - numR, pend - 1 - numR, numL);
        }

        return node;
    }
};

int main()
{
    Solution sln;
    vector<int> inorder{7, 11, 2, 4, 5, 13, 8, 4, 1};
    vector<int> postorder{7, 2, 11, 4, 13, 1, 4, 8, 5};
    TreeNode *root = sln.buildTree(inorder, postorder);
    printTreeLevelOrder(root);
    CleanUp2<TreeNode>(root);
    return 0;
}
