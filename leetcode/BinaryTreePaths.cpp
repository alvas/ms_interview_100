#include <iostream>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {

    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;
    vector<string> v = sln.binaryTreePaths(root);
    printVector<string>(v);
    return 0;
}
