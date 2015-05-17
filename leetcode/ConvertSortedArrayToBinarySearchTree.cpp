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
    const int LOCAL_LENGTH = 10;
    //int a[LOCAL_LENGTH] = {1};
    //int a[LOCAL_LENGTH] = {1, 2};
    //int a[LOCAL_LENGTH] = {1, 2, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5, 6};
    int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums(a, a + LOCAL_LENGTH);
    printVector<int>(nums);
    TreeNode *root = sln.sortedArrayToBST(nums);
    //printTreePreorder(root);
    vector<string> v;
    BuildOrderLevelVector(root, v);
    printVector<string>(v);
    CleanUp2<TreeNode>(root);
    return 0;
}
