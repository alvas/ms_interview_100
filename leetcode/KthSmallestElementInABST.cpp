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
    int kthSmallest(TreeNode* root, int k) {
    }
};

int main()
{
    Solution sln;
    string s[] = {"6", "2", "8", "0", "4", "7", "9", "#", "#", "3", "5"};
    vector<int> v(s, s + SIZE(s));
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    printTreeLevelOrder<TreeNode>(root);
    int k = 0;
    cout << "Please enter k: ";
    cin >> k;
    cout << sln.kthSmallest(root, k);
    CleanUp2(root);
    return 0;
}
