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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    // end is the index of the last element
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = start + ((end - start) >> 1);

        // create parent first, then left/right child
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST1(vector<int>& nums) {
        TreeNode *root = NULL;
        int size = nums.size();

        if (size == 0)
        {
            return root;
        }

        buildTree(nums, root, 0, size);

        return root;
    }

    void buildTree(const vector<int> &nums, TreeNode *&root, int start, int end)
    {
        if (start >= end)
        {
            return;
        }

        int mid = (start + end) / 2;
        root = new TreeNode(nums[mid]);
        buildTree(nums, root->left, start, mid);
        buildTree(nums, root->right, mid + 1, end);
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1};
    //vector<int> nums = {1, 2};
    //vector<int> nums = {1, 2, 3};
    //vector<int> nums = {1, 2, 3, 4};
    //vector<int> nums = {1, 2, 3, 4, 5};
    //vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printVector<int>(nums);
    TreeNode *root = sln.sortedArrayToBST(nums);
    //printTreePreorder(root);
    vector<string> v;
    BuildOrderLevelVector(root, v);
    printVector<string>(v);
    CleanUp2<TreeNode>(root);
    return 0;
}
