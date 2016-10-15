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
    vector<vector<int>> findLeaves(TreeNode* root) {
        
    }
};

int main() {
    Solution sln;
    TreeNode* root = nullptr;
    vector<string> tree = {"1", "2", "3", "4", "5", "#", "#"};
    ReBuildTreeFromOrderLevel(tree, root);
    vector<vector<int>> v = sln.findLeaves(root);
    print2DVector<int>(v);
    CleanUp2<TreeNode>(tree);
    return 0;
}
