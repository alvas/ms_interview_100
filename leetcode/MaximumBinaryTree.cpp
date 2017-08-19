#include <iostream>
#include <vector>

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
public:
    /*
     * The key idea is:

       We scan numbers from left to right, build the tree one node by one step;
       We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
       For each number, we keep pop the stack until empty or a bigger number; The bigger number (if exist, it will be still in stack) is current number's root, and the last popped number (if exist) is current number's right child (temporarily, this relationship may change in the future); Then we push current number into the stack.
    */
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode *> s;

        for (int i = 0; i < nums.size(); ++i) {
            TreeNode *cur = new TreeNode(nums[i]);
            TreeNode *l = nullptr;

            // find node before cur and smaller than it
            // all nodes on the stack are in descending order
            while (!s.empty() && s.back()->val < nums[i]) {
                l = s.back();
                s.pop_back();
            }

            // set node before cur and smaller than it to cur->left
            cur->left = l;

            // node before cur but bigger than cur, set cur to right child of it
            if (!s.empty()) {
                s.back()->right = cur;
            }

            // if stack is empty, cur is the biggest one; if not empty, cur is smaller than top of stack
            // but bigger than any one between top of stack and cur;
            s.push_back(cur);
        }

        // Because we need to get the first node, we can't use stack directly.
        return s.front();
    }

    TreeNode* constructMaximumBinaryTree1(vector<int>& nums) {
        int num = nums.size();
        TreeNode *root = construct(nums, 0, num);
        return root;
    }

    TreeNode *construct(const vector<int> &nums, int b, int e) {
        if (e <= b)
            return nullptr;

        int maxIdx = findMaxIndex(nums, b, e);
        TreeNode *root = new TreeNode(nums[maxIdx]);
        // be careful about the end index here.
        root->left = construct(nums, b, maxIdx);
        root->right = construct(nums, maxIdx + 1, e);
        return root;
    }

    int findMaxIndex(const vector<int> &nums, int b, int e) {
        int idx = e, maxV = INT_MIN;

        for (int i = b; i < e; ++i) {
            if (maxV < nums[i]) {
                maxV = nums[i];
                idx = i;
            }
        }

        return idx;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {3,2,1,6,0,5};
    //vector<int> nums;
    //vector<int> nums = {3};
    //vector<int> nums = {3, 5};
    vector<int> nums = {8, 3, 5};
    TreeNode *root = sln.constructMaximumBinaryTree(nums);
    printTreeLevelOrder<TreeNode>(root);
    CleanUp2<TreeNode>(root);
    return 0;
}
