#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;

        if (root == NULL)
        {
            return r;
        }

        stack<TreeNode *> s;
        s.push(root);
        TreeNode *prev = root;

        while (!s.empty())
        {
            TreeNode *top = s.top();

            if (top->left == NULL && top->right == NULL)
            {
                s.pop();
                prev = top;
                r.push_back(top->val);
            }
            else if (top->left != NULL && prev != top->left && prev != top->right)
            {
                s.push(top->left);
            }
            else if (top->right != NULL && prev != top->right)
            {
                s.push(top->right);
                r.push_back(top->val);
            }
            else
            {
                s.pop();

                // if a node doesn't have right child, when after visit its left child tree, we need to print this node
                // {"1", "#", "3", "2", "#"}
                if (prev != top->right)
                {
                    r.push_back(top->val);
                }

                prev = top;
            }
        }

        return r;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 5;
    //string s[LOCAL_LENGTH] = {"30", "10", "50", "#", "#", "#", "20", "45", "#", "#", "35", "#", "#"};
    //string s[LOCAL_LENGTH] = {"1", "2"};
    //string s[LOCAL_LENGTH] = {"1", "#", "2"};
    //string s[LOCAL_LENGTH] = {"1"};
    //string s[LOCAL_LENGTH] = {"1", "2", "#", "3", "#", "4", "#"};
    //string s[LOCAL_LENGTH] = {"4", "#", "3", "#", "2", "#", "1"};
    //string s[LOCAL_LENGTH] = {"1", "3", "#", "#", "2"};
    string s[LOCAL_LENGTH] = {"1", "#", "3", "2", "#"};
    vector<string> v(s, s + LOCAL_LENGTH);
    TreeNode *root = NULL;
    ReBuildTreeFromOrderLevel(root, v);
    vector<int> r = sln.inorderTraversal(root);
    printVector<int>(r);
    CleanUp2(root);
    return 0;
}
