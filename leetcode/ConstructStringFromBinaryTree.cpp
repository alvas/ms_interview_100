#include <iostream>

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
    string tree2str(TreeNode* t) {
        return !t ? "" : to_string(t->val)
                        + (t->left ? "(" + tree2str(t->left) + ")" : t->right ? "()" : "")
                        + (t->right ? "(" + tree2str(t->right) + ")" : "");
    }

    string tree2str1(TreeNode* t) {
        string res;

        if (t == nullptr)
            return res;
        
        preTrav(t, res);
        return res;
    }

    void preTrav(TreeNode *root, string &s) {
        if (root == nullptr)
            return;

        s.append(to_string(root->val));

        if (root->left != nullptr || root->right != nullptr)
            s.append(1, '(');

        preTrav(root->left, s);

        if (root->left != nullptr || root->right != nullptr)
            s.append(1, ')');

        if (root->right != nullptr)
            s.append(1, '(');

        preTrav(root->right, s);

        if (root->right != nullptr)
            s.append(1, ')');
    }
};

int main()
{
    Solution sln;
    TreeNode *root = nullptr;
    //vector<string> v = {"1"};
    //vector<string> v = {"1", "2"};
    //vector<string> v = {"1", "#", "2"};
    //vector<string> v = {"1", "2", "3"};
    //vector<string> v = {"1", "2", "3", "4"};
    //vector<string> v = {"1", "2", "3", "#", "4"};
    vector<string> v = {"1", "2", "3", "#", "#", "4"};
    //vector<string> v = {"1", "2", "3", "#", "#", "#", "4"};
    //vector<string> v = {"1", "2", "3", "4", "5"};
    //vector<string> v = {"1", "2", "3", "4", "#", "5"};
    //vector<string> v = {"1", "2", "3", "4", "#", "#", "5"};
    //vector<string> v = {"1", "2", "3", "4", "#", "#", "5", "6"};
    ReBuildTreeFromOrderLevel<TreeNode>(v, root);
    string res = sln.tree2str(root);
    cout << res << endl;
    CleanUp2<TreeNode>(root);
    return 0;
}
