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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        return ans;
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    vector<string> v = {"1", "#", "3", "2", "4" "#", "5"};
    //vector<string> v = {"2", "#", "3", "2", "#" "1"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    cout << sln.longestConsecutive(root) << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
