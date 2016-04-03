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
        if (!root)
        {
            return true;
        }

        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty())
        {
            TreeNode *nl = q1.front();
            TreeNode *nr = q2.front();
            q1.pop();
            q2.pop();

            if (!nl && !nr)
            {
                continue;
            }

            if (!nl || !nr)
            {
                return false;
            }
            else if (nl->val != nr->val)
            {
                return false;
            }

            q1.push(nl->left);
            q2.push(nr->right);
            q1.push(nl->right);
            q2.push(nr->left);

        }

        return q1.empty() && q2.empty();
    }

    bool isSymmetric_recursive(TreeNode *root) {
        if (root == nullptr)
        {
            return true;
        }

        return checkSymmetric(root->left, root->right);
    }

    bool checkSymmetric(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr)
        {
            return right == nullptr;
        }
        else if (right == nullptr)
        {
            return left == nullptr;
        }
        else if (left->val != right->val)
        {
            return false;
        }

        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }

    bool isSymmetric1(TreeNode *root) {
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

