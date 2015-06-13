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
        vector<TreeNode *> subset;

        for (int i = 1; i <= n; ++i)
        {
            TreeNode *node = new TreeNode(i);
            subset.push_back(node);
        }

        return v;
    }

    void buildSubTree(int start, int end, vector<TreeNode *> &subset)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n - i; ++j)
            {
                for (int k = j; k < i + j; ++k)
                {
                    TreeNode *node = new TreeNode(i);
                    subset.push_back(node);
                }
            }
        }
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
        cout << endl;
    }

    return 0;
}
