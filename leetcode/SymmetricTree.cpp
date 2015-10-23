#include <iostream>

#include "Tree.h"

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        string s1, s2;
        DFS(root, s1);
        DFS2(root, s2);
        std::cout << "s1: " << s1 << endl;
        std::cout << "s2: " << s2 << endl;
        return s1 == s2;
    }

    void DFS(const TreeNode *root, string &s)
    {
        if (root == NULL)
        {
            s += string("#");
            return;
        }

        s += std::to_string(root->val);
        DFS(root->left, s);
        DFS(root->right, s);
    }

    void DFS2(const TreeNode *root, string &s)
    {
        if (root == NULL)
        {
            s += string("#");
            return;
        }

        s += std::to_string(root->val);
        DFS2(root->right, s);
        DFS2(root->left, s);
    }
};

int main()
{
    Solution sln;
    TreeNode *root = NULL;
    string leaf[11] = {"1", "2", "2", "3", "#", "#", "3", "4", "#", "1", "4"};
    vector<string> v(leaf, leaf + 11);
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    std::cout << sln.isSymmetric(root) << endl;
    return 0;
}

