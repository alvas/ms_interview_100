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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> v;

        return v;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    cout << "Please enter n: ";
    cin >> n;
    vector<TreeNode *> v = sln.generateTrees(n);

    for (vector<TreeNode *>::iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        TreeNode *root = *itr;
        printTreeLevelOrder(root);
        CleanUp2(root);
    }

    return 0;
}
